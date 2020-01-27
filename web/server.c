#include <stdio.h>
//#include <sys/socket.h>
#include<winsock2.h>

int main(int argc, char *argv[])
{
    char *host = "127.0.0.1";
    unsigned int port = 8080;

    printf("Http server start at http://%s:%d\n", host, port);

    

    return 0;
}

int create_server(unsigned int port){
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    return 0;
}


void die(const char *message)
{
    if (errno)
    {
        perror(message);
    }
    else
    {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}