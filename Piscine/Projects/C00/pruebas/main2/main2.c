#include <stdio.h>

int main()
{
	int a = 42; 
	int b;

	b = a;
	printf("hello %d world %d\n", a, b);
	a = 12;
	b = 13;
	printf("hello %d world %d\n", a, b);
}
