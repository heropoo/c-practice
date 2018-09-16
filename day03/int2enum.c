#include<stdio.h>

int main()
{
	enum DAY{
		Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
	};

	int a = 6;
	enum DAY weekend;
	weekend  = (enum DAY) a;	//类型转换
	printf("weekend: %d\n", weekend);
	return 0;
}