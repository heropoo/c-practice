#include<stdio.h>

int main()
{
    int c;

    printf("Enter a value:");
    c=getchar();

    printf( "\nYou entered: %d => ", c);

    putchar(c);
    printf( "\n");
    return 0;
}