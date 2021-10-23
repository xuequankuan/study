#include <stdarg.h>
#include <stdio.h>

static char printbuf[1024];

int my_print(const char *fmt, ...)
{
	int i;
	va_list args;

	va_start(args, fmt);
	write(1, printbuf, i = vsprintf(printbuf, fmt, args));
	va_end(args);

	return 1;
}

int main()
{
	int a = 10;
	int b = 2;

	my_print("a=%d\n", a);
	my_print("a=%d b=%d\n", a, b);

	return 0;	
}
