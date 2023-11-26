
#include <stdio.h>

int my_str_len_ptr_arithmetics(char *first_index) {
	// *_index of memory, if we see memory as a big array of bytes
	char *last_index = first_index;
	while (*last_index != '\0') {
		last_index++;
	}
	return last_index - first_index;
	// ^^^ return the difference in pointers,
	// which means the string length
}


int main(void) {

	// void pointers----------------------------------------------------------

	// void pointer = a pointer to a thing that you don’t know the type of.





	// array/pointer-equivalence----------------------------------------------------------

	// a[b] == *(a + b) or E1[E2] is identical to (* ( (E1) + (E2) ) )
	// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	// array-pointer-equivalence IN FUNCTION CALLS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// If you have a function that takes a pointer argument, e.g.:
	// this means you can pass either an array or a pointer to this function and have it work!
	// ^^^^^ SIEMPRE Y CUANDO SE TRATE DE ARRAYS y no de OBJETOS EN ESPECIFICO
	//char s[] = "Antelopes";
	//char *t = "Wombats";
	//printf("%d\n", my_strlen(s));  // Works!
	//printf("%d\n", my_strlen(t));  // Works, too!	
	//// And it’s also why these two function signatures are equivalent:
	//int my_strlen(char *s)    // Works!
	//int my_strlen(char s[])   // Works, too!


	//int a[] = {11, 22, 33, 44, 55};
	//int *p = a;  // p points to the first element of a, 11
	// Print all elements of the array a variety of ways:
	//for (int i = 0; i < 5; i++)
		//printf("%d\n", a[i]);      // Array notation with a
	//for (int i = 0; i < 5; i++)
		//printf("%d\n", p[i]);      // Array notation with p
	//for (int i = 0; i < 5; i++)
		//printf("%d\n", *(a + i));  // Pointer notation with a
	//for (int i = 0; i < 5; i++)
		//printf("%d\n", *(p + i));  // Pointer notation with p
	//for (int i = 0; i < 5; i++)
		//printf("%d\n", *(p++));    // Moving pointer p
		////printf("%d\n", *(a++));    // Moving array variable a--ERROR!

	// So you can see that in general, if you have an
	// array variable, you can use pointer or array 
	// notion to access elements. Same with a pointer variable.

	// The one big difference is that you can modify 
	// a pointer to point to a different address,
	// but you can’t do that with an array variable.

	// pointer-arithmetic---------------------------------------------------------

	// SUBSTRACTING POINTERS
	printf("%d\n", my_str_len_ptr_arithmetics("Hello, world!")); // prints "13"
	// Remember that you can only use pointer
	// subtraction between two pointers that point to the same array!

	// CHANGING POINTERS
	//int a[] = {11, 22, 33, 44, 55, 999};  // Add 999 here as a sentinel
	//int *p = &a[0];  // p points to the 11
	//while (*p != 999) {       // While the thing p points to isn't 999
	    //printf("%d\n", *p);   // Print it
	    //p++;                  // Move p to point to the next int!
	//}

	// ADDING TO POINTERS
	//int a[5] = {11, 22, 33, 44, 55};
	//int *p = &a[0];  // Or "int *p = a;" works just as well
	//for (int i = 0; i < 5; i++) {
	    //printf("%d\n", *(p + i));  // Same as p[i]!
	//}

	// POINTER ARITHMETICS
	//int a[5] = { 11, 22, 33, 44, 55 };
	//int *p = &a[0]; // == int *p = a; ???
	//printf("%d\n", *p); // 11
	//printf("%d\n", *(p + 0)); // 11
	//printf("%d\n", *(p + 1)); // 22


}
