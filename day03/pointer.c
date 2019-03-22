#include <stdio.h>

int main()
{
	int var1;
	char var2[10];
	int *prt = NULL;

	printf("var1的地址： %p\n", &var1);
	printf("var2的地址： %p\n", &var2);
	printf("prt的地址： %p\n", prt);	// prt的地址： (nil)

	return 0;
}
