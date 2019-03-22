#include<stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int (*p)(int, int) = &max;   //&可以省略
    int a,b,c,d;

    printf("请输入三个数字：\n");
    scanf("%d %d %d", &a, &b, &c);

    d = p(p(a, b), c);

    printf("最大的数字是：%d", d);
    
    return 0;
}