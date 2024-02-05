#include <stdio.h>
#include <stdlib.h>

//#define EXTRA_HAPPY
#define HAPPY_FACTOR 0


#define SQR(x) ((x) * (x)) // ()s to accept expressions that resolve to ints
//#define SQR(x) x * x // <-- This would behave wierdly on math operators
#define STR(x) #x
#define PRINT_INT_VAL(x) printf("%s = %d\n", #x, x)
#define CAT(a, b) a ## b
#define PRINT_NUMS_TO_PRODUCT(a, b) do { \
    int product = (a) * (b); \
    for (int i = 0; i < product; i++) { \
        printf("%d\n", i); \
    } \
} while(0)


#define ASSERT_ENABLED 1
#if ASSERT_ENABLED
#define ASSERT(c, m) \
do { \
    if (!(c)) { \
        fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
                        __LINE__, #c, m); \
        exit(1); \
    } \
} while(0)
#else
#define ASSERT(c, m)  // Empty macro if not enabled
#endif



int main(void) {

//----------------------------------------
	// #pragma directive
// pragma == 'pragmatic'



//----------------------------------------
	// #error directive
#ifndef __STDC_IEC_559__ 
	#error I really need IEEE-754 floating point to compile. Sorry!  
#endif

//----------------------------------------
	// ASSERT MACRO
	//int x = 30;
	//ASSERT(x < 20, "x must be under 20");

//----------------------------------------
	// Multiline MACROS
	//PRINT_NUMS_TO_PRODUCT(2,4);
	//Escapes at the end of every line except the last one to indicate that the macro continues.
	//The whole thing is wrapped in a do-while(0) loop with squirrley braces.

//----------------------------------------
	// Concatenation
	//printf("%f\n", CAT(3.14, 1592));

//----------------------------------------
	// Stringification
	//printf("%s\n", STR(3.14159));
	//int a = 5;
	//PRINT_INT_VAL(a);
//----------------------------------------
// Macros with args
	//printf("%d\n", SQR(12));
	//printf("%d\n", SQR(3 + 4));

//----------------------------------------
//#ifdef EXTRA_HAPPY
	//printf("Im extra happy mf!\n");
//#endif
	//printf("Ok\n");
//#ifndef EXTRA_HAPPY
	//printf("Not happy nor sadge\n");
//#endif

//#ifdef EXTRA_HAPPY
	//printf("Im extra happy mf!\n");
//#else
	//printf("Not happy nor sadge\n");
//#endif

//#if HAPPY_FACTOR == 0
	//printf("Not happy\n");
//#elif HAPPY_FACTOR == 1
	//printf("Not happy nor sadge\n");
	//
//#else 
	//printf("Im extra happy\n");
//#endif
	//printf("Ok\n");

//----------------------------------------

#if 0
	//large commment with valid code but doesn't
	//get to the compiler since the C preprocessor
	//removes this code
	printf("some aswome code\n");
	printf("some aswome code\n");
	printf("some aswome code\n");
	printf("some aswome code\n");
#endif

// these are equivalent
// #defined is preprocessor operator
	//#ifdef FOO
	//#if defined FOO
	//#if defined(FOO) // parentheses are optional
// therefore this negations of the above are also equivalent
	//#ifndef FOO
	//#if !defined FOO
	//#if !defined(FOO) // parentheses are optional

//----------------------------------------
		//Right way
	//#if defined FOO
	    //x = 2;
	//#elif defined BAR
	    //x = 3;
	//#endif
		//Wrong way
	//#ifdef FOO
	    //x = 2;
	//#elifdef BAR  // ERROR: "#elifdef" Not supported by standard C
	    //x = 3;
	//#endif

//----------------------------------------

	// Losing/Undefining Macros

	//#define GOATS
	//#ifdef GOATS
		//printf("goats detected!\n");
	//#endif
	//#undef GOATS
	//#if defined GOATS
		//printf("goats are still here!\n");
	//#else 
		//printf("goates removed :'v\n");
	//#endif

//----------------------------------------
	// BUILT-IN MACROS
	//printf("This function: %s\n", __func__);
	//printf("This file: %s\n", __FILE__);
	//printf("This line: %d\n", __LINE__);
	//printf("Compiled on: %s %s\n", __DATE__, __TIME__);
	//printf("C Version: %ld\n", __STDC_VERSION__);


//----------------------------------------


}
