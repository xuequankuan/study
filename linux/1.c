#include <stdio.h>

void main()
{
	int a = 10;
	int *b = &a;
	unsigned int c = b;

	printf("a=%p b=%p c=%#X\n", &a, b, c);

	int *d = (int *)c;
	printf("%d\n", *d);
}
