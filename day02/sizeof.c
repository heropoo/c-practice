#include<stdio.h>

int main()
{
    printf("c lang data type sizeof:\n");
    printf("int: %lu\n", sizeof(int));
    printf("short int: %lu\n", sizeof(short int));
    printf("long int: %lu\n", sizeof(long int));
    printf("unsigned int: %lu\n", sizeof(unsigned int));
    printf("char: %lu\n", sizeof(char));
    printf("float: %lu\n", sizeof(float));
    printf("double: %lu\n", sizeof(double));
    printf("long double: %lu\n", sizeof(long double));
    return 0;
}

/** output **
c lang data type sizeof:
int: 4
short int: 2
long int: 8
unsigned int: 4
char: 1
float: 4
double: 8
long double: 16
*/
