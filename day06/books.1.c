#include<stdio.h>
#include<string.h>

struct Books
{
    char title[100];
    char author[50];
    char subject[100];
    int book_id;
};

void main()
{
    struct Books book1, book2;

    strcpy(book1.title, "C语言");
    strcpy(book1.author, "张三");
    strcpy(book1.subject, "不知道");
    book1.book_id = 123;

    //访问结构成员
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book1.title, book1.author, book1.subject, book1.book_id);
}