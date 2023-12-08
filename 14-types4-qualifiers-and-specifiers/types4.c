#include <stdio.h>

void counter(void);

int main(void) {


	// storage-class specifiers-----------------------------------------
	
	//-----------------
	// auto
	//{
	    //int a;         // auto is the default...
	    //auto int a;    // So this is redundant
	//}

	//-----------------
	// static
		// static in block scope
		//One thing of note is that static block scope variables are initialized to 0 by default.
			//counter();	
			//counter();	
			//counter();	
			//counter();	
		// static in file scope
		//Instead what static means in this context is that this variable 
		//isn’t visible outside of this particular source file. Kinda like 
		//“global”, but only in this file.

	//-----------------
	// extern
	// extern int a; // it's like "importing" a file-scoped variable from another source file
	// "extern" is the default por functions, but can mark them as "static" to only be
	// visible in a single source file

	//-----------------
	// register
	// but can't access it's address or dereference (in case of array)
	// since we are telling compiler to try to mantain this variables in
	// the CPU registers (somehow cached?) and not to flush them
	// to MEMORY/RAM
	//register int a; // Make "a" as fast to use as possible
	//for (a = 0; a < 10; a++) {
		//printf("%d\n", a);
	//}

	//-----------------

	
	// type qualifiers-----------------------------------------
	//			CONST
	//-----------------
	//const int x = 2
	//2 = 4; // ANGRY COMPILER
	//-----------------
	//const int *p;  // Can't modify what p points to
	//int const *p;  // Can't modify what p points to, just like the previous line
	//-----------------
	//int x = 5;
	//int *const p = &x; // can't modify the pointer but CAN modify what it points to
	////p++;// COMPILER ERROR cause modifying pointer itself
	//*p = 10; // ALLOWED casuse modifying what pointer points 
	//-----------------
	//const int *const p; // can't modify p or *p;

	//			RESTRICT
	//			VOLATILE
}


void counter(void) {
	static int count = 1;
	printf("This has been called %d time(s)\n", count);
	count++;
}
