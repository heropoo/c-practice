#include<stdio.h>

double get_average(int arr[], int size);

int main()
{
	int size = 5;
	int babance[5] = {10002,3233,321,23,4};
	double avg;

	avg = get_average(babance, size);

	printf("avg is %f\n", avg);

	return 0;
}

double get_average(int arr[], int size)
{
	int i;
	double avg;
	double sum = 0;

	for(i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	avg = sum / size;
	return avg;
}

//就函数而言，数组的长度是无关紧要的，因为 C 不会对形式参数执行边界检查
