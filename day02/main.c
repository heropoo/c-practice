#include <stdio.h>

int count;

extern void write_extern();

int main ()
{
	count = 5;
	write_extern();
	return 0;
}

/**编译
gcc main.c support.c
*/