#include <stdio.h>
#include <stdlib.h>


int main(void) {

	// explicit conversions---------------------------------------------

		// casting
		//int x = 10;
		//long int y = (long int)x + 12;


	// numeric conversions---------------------------------------------
		// bools
			//false == 0
			//true == any other number
		// integer-to-float and viceversa
			// if value converted 
			// are too large then it's
			// UNDEFINED BEHAVIOR 



	// char conversions---------------------------------------------
	//char c = '6';
	//int x = c;  // x has value 54, the code point for '6'
	//int y = c - '0'; // y has value 6, just like we want

	//int x = 6;
	//char c = x + '0';  // c has value 54
	//printf("%d\n", c);  // prints 54
	//printf("%c\n", c);  // prints 6 with %c


	
	// string conversions---------------------------------------------
	// string-to-numeric

		// atoi family of funcs ________________________
			// ^a => stands for ASCI
			// insecure
			// bad-error handling
			// undefined behavior
		//char *pi = "3.14159";
		//float f;
		//f = atof(pi);
		//printf("%f\n", f);

		// strtol family of funcs _______________________
			// strtol => means "string to long"
			//strtol	String to long int
			//strtoll	String to long long int
			//strtoul	String to unsigned long int
			//strtoull	String to unsigned long long int
			//strtof	String to float
			//strtod	String to double
			//strtold	String to long double
		
		// Convert string s, a number in base 10, to an unsigned long int.
		// NULL means we don't care to learn about any error information
		//char *s = "3490";
		//unsigned long int x = strtoul(s, NULL, 10);
		//printf("%lu\n", x);

		//char *s = "101010";  // What's the meaning of this number?
		//// Convert string s, a number in base 2, to an unsigned long int.
		//unsigned long int x = strtoul(s, NULL, 2); // base 2 is binary
		//printf("%lu\n", x);  // 42

		
		// ERROR HANDLING
		//char *s = "34x90";  // "x" is not a valid digit in base 10!
		//char *badchar;
		//// Convert string s, a number in base 10, to an unsigned long int.
		//unsigned long int x = strtoul(s, &badchar, 10);
		//// It tries to convert as much as possible, so gets this far:
		//printf("%lu\n", x);  // 34
		//// But we can see the offending bad character because badchar
		//// points to it!
		//printf("Invalid character: %c\n", *badchar);  // "x"

		//char *s = "3c90";  // "x" is not a valid digit in base 10!
		//char *badchar;
		//// Convert string s, a number in base 10, to an unsigned long int.
		//unsigned long int x = strtoul(s, &badchar, 10);
		//// Check if things went well
		//if (*badchar == '\0') {
			//printf("Success! %lu\n", x);
		//} else  {
			//printf("Partial conversion: %lu\n", x);
			//printf("Invalid character: %c\n", *badchar);
		//}

	

	// numeric-to-string______
	//char s[10];
	//float f = 3.14159;
	//// Convert "f" to string, storing in "s", writing at most 10 characters
	//// including the NUL terminator
	//snprintf(s, 10, "%f", f);
	//printf("String value: %s\n", s);

}
