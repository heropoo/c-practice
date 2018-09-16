#include<stdio.h>

enum DAY
{
	MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;

int main()
{
	for(day = MON; day <= SUN; day ++)
	{
		printf("枚举元素： %d\n", day);		
	}
	return 0;
}