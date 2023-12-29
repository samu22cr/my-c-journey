#include <stdio.h>
#include <stdarg.h>


void some_func(int a, ...) {
	printf("a = %d\n");
}


int add(int count, ...) {

	int total = 0;
	va_list va;
	va_start(va, count); // start processing variable args

	for(int i = 0; i < count; i++) {
		int n = va_arg(va, int); // process each argument
		total += n;
	}
	va_end(va); // wrap it up when done
	return total;

}

int my_printf(int serial, const char *format, ...)
{
    va_list va;

    // Do my custom work
    printf("The serial number is: %d\n", serial);

    // Then pass the rest off to vprintf()
    va_start(va, format);
    int rv = vprintf(format, va);
    va_end(va);

    return rv;
}


int main(void) {
	//some_func(1, 321, 3213, 321321);
	//
	//printf("%d\n", add(2, 5643, 123));
	//printf("%d\n", add(5, 123, 44, 1, 543, 1111));
	//printf("%d\n", add(3, 23222, 999, 788));

	//int x = 10;
	//float y = 3.2;
	//my_printf(3490, "x is %d, y is %f\n", x, y);
}

