#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
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

void die(const char *message)
{
    if(errno){
        perror(message);
    }else{
        printf("Error: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Faild to load database.");
}

struct Connextion *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error");

}

int main(int argc, char *argv[])
{
    printf("argc: %d \n argv: %s", argc, **argv);
    return 0;
    //if (argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

}
