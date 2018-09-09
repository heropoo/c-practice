#include<stdio.h>
#include<float.h>

int main(int argc, char const *argv[])
{
	printf("float 存储最大字节数：%lu\n", sizeof(float));
	printf("float 最大值：%E\n", FLT_MAX);
	printf("float 最小值：%E\n", FLT_MIN);
	printf("float 精度：%d\n", FLT_DIG);
	return 0;
}

/** output **
float 存储最大字节数：4
float 最大值：3.402823E+38
float 最小值：1.175494E-38
float 精度：6
*/