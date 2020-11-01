#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address
{
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database
{
    struct Address rows[MAX_ROWS];
};

struct Connection
{
    FILE *file;
    struct Database *db;
};

void Address_print(struct Address *addr)
{
    printf("%d\t|\t%s\t|\t%s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn){
    //C 库函数 size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) 从给定流 stream 读取数据到 ptr 所指向的数组中。
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1){
        die("Failed to load database.");
    }
}



void die(const char *msg)
{
    if (errno)
    {
        perror(msg);
    }
    else
    {
        printf("Error: %s\n", msg);
    }
    exit(1);
}

int main(const int argc, const char *argv[])
{
    if (argc < 3)
    {
        char msg[255] = "USAGE: ";
        strcat(msg, argv[0]);
        strcat(msg, " <dbfile> <action> [action params]\n");
        die(msg);
    }

    return 0;
}
