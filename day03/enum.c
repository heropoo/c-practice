#include<stdio.h>

enum DAY
{
	MON=1, TUE, WED, THU, FRI, SAT, SUN
};

int main()
{
	enum DAY day;
	day = WED;
	printf("WED = %d\n", day);
	return 0;
}