#include<stdio.h>

struct Books
{
    char title[100];
    char author[50];
    char subject[100];
    int book_id;
} book = {"C语言", "RUNOOB", "编程语言", 123456};

void main()
{
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}