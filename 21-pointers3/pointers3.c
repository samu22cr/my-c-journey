#include <stdio.h>
#include <stdint.h>
#include <stddef.h>


int add(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }

void do_math(int (*callback)(int, int), int x, int y) {
	int rs = callback(x,y);
	printf("result of callback = %d\n", rs);
}


int main(void) {
	
	//pointers-to-pointers----------------------------------------------------
	//int x = 3490;  // Type: int
	//int *p = &x;   // Type: pointer to an int
	//int **q = &p;  // Type: pointer to pointer to int
	//printf("%d %d\n", *p, **q);  // 3490 3490
	// pointers-to-pointers & const______________________
	//int x = 3490;
	//int *const p = &x;
	//int *const *q = &p;

	// multibyte-values-------------------------------------------------------
	// Two things with the same object representation in memory are equal.
	// ONLY ITERATE over the object representation with pointers
	// to UNSIGNED CHARs
	
	// the NULL-pointer and Zero----------------------------------------------
	//These things can be used interchangeably:
	//	NULL
	//	0
	//	'\0'
	//	(void *)0

	// Pointers as Integers------------------------------------------
	//int x = 1;
	//uintptr_t unsigned_integer_pointer = (uintptr_t) &x;
	//intptr_t signed_integer_pointer = (intptr_t) &x;
	//printf("%p\n", (void *)unsigned_integer_pointer);
	//printf("%p\n", (void *)signed_integer_pointer);
	// ABOVE: MUST cast to void * to prevent undefined behavior
	//printf("%p\n", unsigned_integer_pointer);
	//printf("%p\n", signed_integer_pointer);


	// Pointer Differences------------------------------------------
	//int cats[100];
	//int *f = cats + 20;
	//int *g = cats + 60;
	//ptrdiff_t d = g - f;  // difference is 40	
	//printf("%td\n", d);  // Print decimal: 40
	//printf("%tX\n", d);  // Print hex:     28


	// Pointers to Functions------------------------------------------
	// -- basically callbacks
	do_math(add, 2, 3);
	do_math(mult, 2, 3);

}

