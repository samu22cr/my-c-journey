#include <stdio.h>

void increment(int *p);


int main(void) {

	//sizeof and pointers--------------------------------------------
	int *p;

	// Prints size of an 'int'
	printf("%zu\n", sizeof(int));

	// p is type 'int *', so prints size of 'int*'
	printf("%zu\n", sizeof p);

	// *p is type 'int', so prints size of 'int'
	printf("%zu\n", sizeof *p);


	// declaring pointers--------------------------------------------
	int a, *b; // a is int and b is int-pointer
	int* c, d; // c is pointer to int and d is just a regular int
	int *e, *f; // both e and f are int-pointers


	// the NULL pointer---------------------------------------------
	// (Of course, like other variables, the pointer points to garbage unless
	// you explicitly assign it to point to an address or NULL.)
//	int *p;
//	p = NULL;


	//Since it doesn’t point to a value, dereferencing it is undefined behavior, and probably will result in a crash:
	//int *p = NULL;
	//*p = 12;  // CRASH or SOMETHING PROBABLY BAD. BEST AVOIDED.
//
	//int i = 123;
	//int* p = NULL;
	//p = &i;
	//printf("%d\n", i);
	//printf("%p\n", (void *)p);



	// passing pointers as arguments-------------------------------
	//int i = 10;
	//int* j = &i;
	//printf("i = %d\n", i);
	//printf("i is also = %d\n", *j);
	//increment(j);
	//printf("i = %d\n", i);
	//printf("i is also = %d\n", *j);

	// The above example is often more concisely 
	// written in the call just by using address-of
	// right in the argument list:
	//printf("i is %d\n", i);  // prints "10"
	//increment(&i);
	//printf("i is %d\n", i);  // prints "11"!

	// indirection-operator/dereference-operator------------------------
	//int i;  // i's type is "int"
	//int* p; // p's type is "pointer to an int", or "int-pointer"
	//p =  &i;// p is assigned the address of i  --  p now "points to" i
	//i = 10;
	//*p = 20;
	//printf("i is %d\n", i);
	//printf("i is %d\n", *p);//"20"! dereference-p is the same as i!
	

	// address-of operator--------------------------------------------
	//int i = 10;
	//printf("i = %d\n", i);
	//printf("pointer/address-of i = %p\n", (void *) &i);
	// %p expects the argument to be a pointer to void
	// so we cast it to make the compiler happy.
}


void increment(int *p) {
	*p += 1;
}
