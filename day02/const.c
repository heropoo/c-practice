#include<stdio.h>

#define WIDTH 0x1000U
#define HEIGHT 0766LU
#define PI 3.14159
#define STRING "Hello\tWorld\n"

int main()
{
	int area;
	area = WIDTH * HEIGHT;
	printf("%s", STRING);
	printf("area = %d\n", area);
	printf("Π = %le\n", PI);
	return 0;
}