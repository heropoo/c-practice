#include <stdio.h>
#include <stdlib.h>

main(){
    int dividend = 20;
    int divisor = 0;
    int quotient;

    if (divisor == 0){
        fprintf(stderr, "整数为0退出运行。。。\n");
        exit(EXIT_FAILURE);
    }

    quotient = dividend / divisor;
    fprintf(stderr, "结果为：%d\n", quotient);

    exit(EXIT_SUCCESS);
}
