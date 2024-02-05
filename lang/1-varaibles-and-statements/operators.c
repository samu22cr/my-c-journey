// Operators

#include <stdio.h>
#include <stdbool.h>


int main(void) { 

	
	// sizeof operator--------------------
	// This operator tells you the size (in bytes)
	// that a particular variable or data type uses in memory.
	//int a = 7000;
	//printf("%zu\n", sizeof a);
	//printf("%zu\n", sizeof(123 +  12312));
	//printf("%zu\n", sizeof 3.14);
	//printf("%zu\n", sizeof 3.14f);
	//printf("%zu\n", sizeof(int));
	//printf("%zu\n", sizeof (char) );
	//printf("%zu\n", sizeof(void) );


	// boolean operators-----------------
	// &&
	// ||
	// !
	// ! has higher precedence than the other Boolean operators,
	//  so we have to use parentheses in that case.
	//int x = 20;
	//if (!(x < 12))
	    //printf("x is not less than 12\n");

	// conditional operators----------
	//bool a = true, b = false;
	//a == b;  // True if a is equivalent to b
	//a != b;  // True if a is not equivalent to b
	//a < b;   // True if a is less than b
	//a > b;   // True if a is greater than b
	//a <= b;  // True if a is less than or equal to b
	//a >= b;  // True if a is greater than or equal to b

	// comma operator-------------
	//
	//int x = 0;
	//int y = 0;
	//x = 10, y = 20; // single expression separated by comma
	//
	//x = (1,2,3); //the value of the comma expresion is
		    //// the value of the rightmost expression (i.e., 3)
	//printf("x equals to %d\n", x);
	//int i = 0, j = 0;
	//for(i = 0, j = 0; i < 100; i++, j++) {
		//printf("i = %d, j = %d\n", i, j);
	//}

	// pre-increment--------------
	//int i = 100;
	//int j = 200;
	//j += ++i; // j should equal 301
		 //// i should equal 101
	//printf("j equals %d\n", j);
	//printf("i equals %d\n", i);


	// post-increment--------------
	//int i = 100;
	//int j = 200;
	//j += i++; // j should equal 300
		 //// i should equal 101
	//printf("j equals %d\n", j);
	//printf("i equals %d\n", i);
	

	// pre-decrement--------------
	//int i = 100;
	//int j = 200;
	//j += --i; // j should equal 299
		 //// i should equal 99
	//printf("j equals %d\n", j);
	//printf("i equals %d\n", i);


	// pre-decrement---------------
	//int i = 100;
	//int j = 200;
	//j += i--; // j should equal 300
		 //// i should equal 99
	//printf("j equals %d\n", j);
	//printf("i equals %d\n", i);


	// ternary operator----------------
	//bool x = false;
	//int y = x ? 10 : 100;
	//printf("y equals %d\n", y);
}


