#include <stdio.h>
#include <string.h>

int my_strlen(char *s) {
	int count = 0;
	while(s[count] != '\0') {
		count++;
	}
	return count;
}

int main(void) {

	// string-termination---------------------------------------------------------

	// last byte of string in C is called "terminator byte". It's also called
	// zero-valued byte or NUL character. Can be written in C code as \0

	// When you include a string in double quotes in your code,
 	// the NUL character is automatically, implicitly included.
	
	char *example_string = "this is a string";
	printf("length is %d\n", my_strlen(example_string));



	// string-initializers---------------------------------------------------------

	//char *s = "some actual text"; // if try to mute it causes undefined behavior
			//char *s = "Hello, world!";
			//s[0] = 'z';  // BAD NEWS: tried to mutate a string literal!
	// ^^^^ this is a pointer to string literal (i.e. a pointer to the first char of the string)

	//char t[] = "some other text"; // can mute it via accessing its chars with [index] notation
	//  ^^^^ this one is a mutable copy of the string that we can change at will:

	//printf("The string is %zu bytes long.\n", strlen(t));


	
	// string-variables---------------------------------------------------------
	
	// string variables as arrays
	// nearly equivalent to the below char* usage:
	//char s[9] = "some text";
	// or, if we were properly lazy and have the compiler
	// figure the length for us:
	//	char s[] = "Hello, world!";
	//for(int i = 0; i < 9; i++) {
		//printf("%c\n", s[i]);
	//}

	//char *s = "Hello, world!";   // char* here
	//for (int i = 0; i < 13; i++)
		//printf("%c\n", s[i]);    // But still use arrays here...?


	//char *s = "some text";	
	// ^^^^^T he string variable s is actually a
	// pointer to the first character in that string, namely the "s".
	//printf("%s\n", s); // prints "some text"


	// string-literals---------------------------------------------------------

	// string literals = they are sequences of characters in double quotes (").
	//printf("This is a string and this are \"escaped quotes\"";
	
		

}	
