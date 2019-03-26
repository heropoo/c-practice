#include<stdio.h>
#include<string.h>

union Data{
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;

    data.i = 10;
    data.f = 220.5;
    strcpy(data.str, "好哈哟~");

    printf( "Memory size occupied by data : %d\n", sizeof(data));
    printf( "data.i : %d\n", data.i);
    printf( "data.f : %f\n", data.f);
    printf( "data.str : %s\n", data.str);

    data.i = 10;
    printf( "data.i : %d\n", data.i);
    
    data.f = 220.5;
    printf( "data.f : %f\n", data.f);
    
    strcpy( data.str, "好哈哟~");
    printf( "data.str : %s\n", data.str);
    
    return 0;
}