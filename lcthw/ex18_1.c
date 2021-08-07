#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void die(const char *message)
{
    if (errno)
    {
        perror(message);
    }
    else
    {
        printf("Error: %s\n", message);
    }
    exit(1);
}

//TODO 

int main(int argc, char *argv[])
{
    if (argc < 2)
        die("USAGE: ex18_1 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    printf("%s", inputs);

    return 0;
}