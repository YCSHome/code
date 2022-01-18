#include <stdio.h>

int main(int argc, char *argv[])
{
	int x = 3, y = 4;

	__asm__("addl %1, %0"
		: "=r" (y)
		: "r" (x), "0" (y));
	
	printf("x + y = %d\n", y);
	return 0;
}

