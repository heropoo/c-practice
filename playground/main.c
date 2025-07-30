#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <time.h>
#include "jansson.h"
#include <sys/stat.h>
#include <fcntl.h>

// JSON string escaping helper function
char* escape_json_string(const char* input);

#define PORT 8080
#define BUFFER_SIZE 8192
#define TEMP_DIR "/tmp/c_playground"

void handle_compile_request(int client_socket, const char *request_body);
void send_json_response(int client_socket, int status, const char *message, const char *output);
void create_temp_dir();
void cleanup_temp_files();

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // 创建临时目录
    create_temp_dir();
    
    // 创建socket文件描述符
    if ((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // 设置socket选项
    // Temporarily remove setsockopt to test
    // if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
    //     perror("setsockopt");
    //     exit(EXIT_FAILURE);
    // }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // 绑定socket到端口
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // 开始监听
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("服务器运行在 http://localhost:%d\n", PORT);
    
    while (1) {
        // 接受新连接
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }
        
        // 读取请求
        ssize_t bytes_read = read(new_socket, buffer, BUFFER_SIZE - 1);
        if (bytes_read < 0) {
            perror("read");
            close(new_socket);
            continue;
        }
        buffer[bytes_read] = '\0';
        
        // 检查是否是POST /compile请求
        if (strstr(buffer, "POST /compile") != NULL) {
            // 查找请求体开始位置
            char *body_start = strstr(buffer, "\r\n\r\n");
            if (body_start != NULL) {
                body_start += 4;
                handle_compile_request(new_socket, body_start);
            } else {
                send_json_response(new_socket, 400, "无效请求", NULL);
            }
        } else {
            // 检查是否是GET请求访问根路径
            if (strstr(buffer, "GET / ") == buffer) {
                // 打开并读取public/index.html
                int fd = open("public/index.html", O_RDONLY);
                if (fd < 0) {
                    const char *error = "HTTP/1.1 500 Internal Server Error\r\n"
                                       "Content-Type: text/plain\r\n"
                                       "Connection: close\r\n\r\n"
                                       "无法打开文件";
                    write(new_socket, error, strlen(error));
                } else {
                    struct stat st;
                    fstat(fd, &st);
                    char *content = malloc(st.st_size);
                    read(fd, content, st.st_size);
                    
                    const char *headers = "HTTP/1.1 200 OK\r\n"
                                          "Content-Type: text/html\r\n"
                                          "Content-Length: %ld\r\n"
                                          "Connection: close\r\n\r\n";
                    char header_buf[256];
                    snprintf(header_buf, sizeof(header_buf), headers, st.st_size);
                    write(new_socket, header_buf, strlen(header_buf));
                    write(new_socket, content, st.st_size);
                    
                    free(content);
                    close(fd);
                }
            } else {
                // 返回404对于其他路径
                const char *not_found = "HTTP/1.1 404 Not Found\r\n"
                                        "Content-Type: text/plain\r\n"
                                        "Connection: close\r\n\r\n"
                                        "404 Not Found";
                write(new_socket, not_found, strlen(not_found));
            }
        }
        
        close(new_socket);
    }
    
    return 0;
}

void handle_compile_request(int client_socket, const char *request_body) {
    json_error_t error;
    json_t *root = json_loads(request_body, 0, &error);
    
    if (!root) {
        send_json_response(client_socket, 400, "无效的JSON数据", NULL);
        return;
    }
    
    json_t *code_json = json_object_get(root, "code");
    if (!json_is_string(code_json)) {
        send_json_response(client_socket, 400, "缺少或无效的代码字段", NULL);
        json_decref(root);
        return;
    }
    
    const char *code = json_string_value(code_json);
    
    // 创建临时文件名
    char temp_file_path[256];
    char output_file_path[256];
    pid_t pid = getpid();
    time_t now = time(NULL);
    
    snprintf(temp_file_path, sizeof(temp_file_path), "%s/%ld_%d.c", TEMP_DIR, now, pid);
    snprintf(output_file_path, sizeof(output_file_path), "%s/%ld_%d.out", TEMP_DIR, now, pid);
    
    // 写入临时文件
    FILE *fp = fopen(temp_file_path, "w");
    if (!fp) {
        send_json_response(client_socket, 500, "无法创建临时文件", NULL);
        json_decref(root);
        return;
    }
    
    fprintf(fp, "%s", code);
    fclose(fp);
    
    // 编译代码
    char compile_command[512];
    snprintf(compile_command, sizeof(compile_command), 
             "gcc %s -o %s 2>&1", temp_file_path, output_file_path);
    
    FILE *compile_pipe = popen(compile_command, "r");
    if (!compile_pipe) {
        send_json_response(client_socket, 500, "编译失败", NULL);
        json_decref(root);
        return;
    }
    
    char compile_output[1024] = {0};
    size_t compile_output_len = 0;
    char buf[256];
    
    while (fgets(buf, sizeof(buf), compile_pipe) != NULL) {
        strncat(compile_output, buf, sizeof(compile_output) - compile_output_len - 1);
        compile_output_len += strlen(buf);
    }
    
    int compile_status = pclose(compile_pipe);
    
    if (compile_status != 0 || strlen(compile_output) > 0) {
        // 编译失败
        send_json_response(client_socket, 400, compile_output, NULL);
        remove(temp_file_path);
        json_decref(root);
        return;
    }
    
    // 执行程序
    char run_command[256];
    snprintf(run_command, sizeof(run_command), "%s 2>&1", output_file_path);
    
    FILE *run_pipe = popen(run_command, "r");
    if (!run_pipe) {
        send_json_response(client_socket, 500, "执行失败", NULL);
        remove(temp_file_path);
        remove(output_file_path);
        json_decref(root);
        return;
    }
    
    char program_output[4096] = {0};
    size_t program_output_len = 0;
    
    while (fgets(buf, sizeof(buf), run_pipe) != NULL) {
        strncat(program_output, buf, sizeof(program_output) - program_output_len - 1);
        program_output_len += strlen(buf);
    }
    
    pclose(run_pipe);
    
    // 返回结果
    send_json_response(client_socket, 200, NULL, program_output);
    
    // 清理临时文件
    remove(temp_file_path);
    remove(output_file_path);
    
    json_decref(root);
}

// Helper function to escape JSON special characters
char* escape_json_string(const char* input) {
    if (!input) return NULL;
    
    // Calculate required buffer size
    size_t len = strlen(input);
    size_t escaped_len = len;
    for (size_t i = 0; i < len; i++) {
        switch(input[i]) {
            case '"':
            case '\\':
            case '\b':
            case '\f':
            case '\n':
            case '\r':
            case '\t':
                escaped_len++;
                break;
        }
    }
    
    char* output = malloc(escaped_len + 1);
    if (!output) return NULL;
    
    // Escape characters
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        switch(input[i]) {
            case '"':
                output[j++] = '\\';
                output[j++] = '"';
                break;
            case '\\':
                output[j++] = '\\';
                output[j++] = '\\';
                break;
            case '\b':
                output[j++] = '\\';
                output[j++] = 'b';
                break;
            case '\f':
                output[j++] = '\\';
                output[j++] = 'f';
                break;
            case '\n':
                output[j++] = '\\';
                output[j++] = 'n';
                break;
            case '\r':
                output[j++] = '\\';
                output[j++] = 'r';
                break;
            case '\t':
                output[j++] = '\\';
                output[j++] = 't';
                break;
            default:
                output[j++] = input[i];
                break;
        }
    }
    output[j] = '\0';
    return output;
}

void send_json_response(int client_socket, int status, const char *message, const char *output) {
    char response[8192];
    const char *status_text = "OK";
    
    if (status >= 400) status_text = "Bad Request";
    if (status >= 500) status_text = "Internal Server Error";
    
    if (message) {
        char* escaped_message = escape_json_string(message);
        snprintf(response, sizeof(response),
                 "HTTP/1.1 %d %s\r\n"
                 "Content-Type: application/json\r\n"
                 "Connection: close\r\n\r\n"
                 "{\"error\":\"%s\"}",
                 status, status_text, escaped_message);
        free(escaped_message);
    } else {
        char* escaped_output = escape_json_string(output);
        snprintf(response, sizeof(response),
                 "HTTP/1.1 %d %s\r\n"
                 "Content-Type: application/json\r\n"
                 "Connection: close\r\n\r\n"
                 "{\"output\":\"%s\"}",
                 status, status_text, escaped_output);
        free(escaped_output);
    }
    
    write(client_socket, response, strlen(response));
}

void create_temp_dir() {
    struct stat st = {0};
    if (stat(TEMP_DIR, &st) == -1) {
        mkdir(TEMP_DIR, 0700);
    }
}

void cleanup_temp_files() {
    // 可以添加定期清理旧文件的逻辑
}