#include <stdio.h>

int main (void) {

	// integer constants------------------------------------------------

	// binary------------------------------------------------
	//int x = 0b101010;    // Binary 101010
	//printf("%d\n", x);   // Prints 42 decimal	


	// hexadecimal and octal------------------------------------------------
	//int x = 11111;  // Decimal 11111
	//int y = 00111;  // Decimal 73 (Octal 111)
	//int z = 01111;  // Decimal 585 (Octal 1111)

	// hexadecimal
	//int a = 0x1A2B;   // Hexadecimal
	//int b = 0x1a2b;   // Case doesn't matter for hex digits
	//printf("%x", a);  // Print a hex number, "1a2b"

	// octal
	//int a = 012;
	//printf("%o\n", a);  // Print an octal number, "12"




	// more integer types------------------------------------------------

	//// These two lines are equivalent:
	//long long int x;
	//long long x;
	//// And so are these:
	//short int x;
	//short x;



	// character types------------------------------------------------
	//char c = 'B';
	//printf("%c\n", c);
	//printf("%d\n", c);
	//char a;           // Could be signed or unsigned
	//signed char b;    // Definitely signed
	//unsigned char c;  // Definitely unsigned	

	// math with chars since they are just ints under the hood
	//char a = 10, b = 20;
	//printf("%d\n", a + b);  // 30!

	//char a = 12;
	//printf("%c\n", a);
	//char b = 'B';  // ASCII value 66
	//printf("%d\n", a + b);  // 76!
	
	// signed and unsigned INTs------------------------------------------------
	//int a;           // signed
	//signed int a;    // signed
	//signed a;        // signed, "shorthand" for "int" or "signed int", rare
	//unsigned int b;  // unsigned
	//unsigned c;      // unsigned, shorthand for "unsigned int"
	
	

}
