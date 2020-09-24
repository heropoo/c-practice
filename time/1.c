#include<time.h>
#include<stdio.h>

int main(){

	time_t t; 
	t = time(NULL); //获取当前时间

	printf("Now time is %ld\n", t);

	struct tm * pst = localtime(&t); //把time_t类型转换为struct tm类型
	
	printf("The year is %d\n", pst->tm_year + 1900); // 别忘了要加1900
	printf("The month is %d\n", pst->tm_mon); 
	printf("The day is %d\n", pst->tm_mday); 
	printf("The hour is %d\n", pst->tm_hour); 
	printf("The min is %d\n", pst->tm_min); 
	printf("The sec is %d\n", pst->tm_sec); 

	printf("Now Time is: %4d-%2d-%2d %2d:%2d:%2d\n", pst->tm_year+1900, pst->tm_mon, pst->tm_mday, pst->tm_hour, pst->tm_min, pst->tm_sec);

	return 0;
}
