
// Std h files
#include <stdio.h>
#include <stdlib.h>

// Wide Character
#include <wchar.h>
#include <wctype.h>
#include <uchar.h> // for char16_t && char32_t "wide char" types

// Others...
#include <string.h>
#include <locale.h>

int main(void) {
	// When escaping code points, must padd with leading zeros (0)
	// if necessary to reach the max # of bits being escaped (16 || 32)
	//
	// char *s = "\u20AC1.23"; // 16-bit max unicode code points
	//char *s = "\U0001D4D1"; // 32-bit max unicode code points
	//printf("%s\n", s);

	
	//--------------------------------------------------------------
	// Wide Character(s) declaration -------------------------------
 	//wchar_t *s = L"Hello, world!";
	//wchar_t c = L'B';
	//printf("%ls %lc\n", s, c);

	// -------------------------------------------------------------
	// NON-PORTABLE ------------->>>>vvvvvvvvvvvvvvvv
	// Only on POSIX-compliant systems --------------------------
	// Only returns length in chars && doesn't actually convert strings...
	//setlocale(LC_ALL, "");
	//// The following string has 7 characters
	//size_t len_in_chars = mbstowcs(NULL, "§¶°±π€•", 0);
	//printf("%zu\n", len_in_chars);  // 7

	// -------------------------------------------------------------
	// EXAMPLE: Wide Character conversion --------------------------
	//// Get out of the C locale to one that likely has the euro symbol
	//setlocale(LC_ALL, "");
	//// Original multibyte string with a euro symbol (Unicode point 20ac)
	//char *mb_string = "The cost is \u20ac1.23";  // €1.23
	//size_t mb_len = strlen(mb_string);
	//// Wide character array that will hold the converted string
	//wchar_t wc_string[128];  // Holds up to 128 wide characters
	//// Convert the MB string to WC; this returns the number of wide chars
	//size_t wc_len = mbstowcs(wc_string, mb_string, 128);
	//// Print result--note the %ls for wide char strings
	//printf("multibyte: \"%s\" (%zu bytes)\n", mb_string, mb_len);
	//printf("wide char: \"%ls\" (%zu characters)\n", wc_string, wc_len);




// 	Wide Character && Multibyte Conversions 
//			mb: multibyte
//			wc: wide character
//			mbs: multibyte string
//			wcs: wide character string
// 	from wchar.h...
//	mbtowc() 	Convert a multibyte character to a wide character.
//	wctomb() 	Convert a wide character to a multibyte character.
//	mbstowcs() 	Convert a multibyte string to a wide string.
//	wcstombs() 	Convert a wide string to a multibyte string.


// 	Wide Character IO funcs (include stdio.h and wchar.h)
//	wprintf() 	Formatted console output.
//	wscanf() 	Formatted console input.
//	getwchar() 	Character-based console input.
//	putwchar() 	Character-based console output.
//	fwprintf() 	Formatted file output.
//	fwscanf() 	Formatted file input.
//	fgetwc() 	Character-based file input.
//	fputwc() 	Character-based file output.
//	fgetws() 	String-based file input.
//	fputws() 	String-based file output.
//	swprintf() 	Formatted string output.
//	swscanf() 	Formatted string input.
//	vfwprintf() 	Variadic formatted file output.
//	vfwscanf() 	Variadic formatted file input.
//	vswprintf() 	Variadic formatted string output.
//	vswscanf() 	Variadic formatted string input.
//	vwprintf() 	Variadic formatted console output.
//	vwscanf() 	Variadic formatted console input.
//	ungetwc() 	Push a wide character back on an output stream.
//	fwide() 	Get or set stream multibyte/wide orientation.


// 	Wide Character CONVERSION funcs (include wchar.h)
//	wcstod() 	Convert string to double.
//	wcstof() 	Convert string to float.
//	wcstold() 	Convert string to long double.
//	wcstol() 	Convert string to long.
//	wcstoll() 	Convert string to long long.
//	wcstoul() 	Convert string to unsigned long.




// 	Wide Character String&Memory COPYING funcs (include wchar.h)
//	wcscpy() 	Copy string.
//	wcsncpy() 	Copy string, length-limited.
//	wmemcpy() 	Copy memory.
//	wmemmove() 	Copy potentially-overlapping memory.
//	wcscat() 	Concatenate strings.
//	wcsncat() 	Concatenate strings, length-limite



// 	Wide Character String&Memory COMPARING funcs (include and wchar.h)
//	wcscmp() 	Compare strings lexicographically.
//	wcsncmp() 	Compare strings lexicographically, length-limited.
//	wcscoll() 	Compare strings in dictionary order by locale.
//	wmemcmp() 	Compare memory lexicographically.
//	wcsxfrm() 	Transform strings into versions such that wcscmp() behaves like wcscoll()165.


// 	Wide Character STRING SEARCHING funcs (include wchar.h)
//	wcschr() 	Find a character in a string.
//	wcsrchr() 	Find a character in a string from the back.
//	wmemchr() 	Find a character in memory.
//	wcsstr() 	Find a substring in a string.
//	wcspbrk() 	Find any of a set of characters in a string.
//	wcsspn() 	Find length of substring including any of a set of characters.
//	wcscspn() 	Find length of substring before any of a set of characters.
//	wcstok() 	Find tokens in a string.


// 	Wide Character LENGTH/MISCELLANEOUS funcs (include wchar.h)
//	wcslen() 	Return the length of the string. (in character count)
//	wmemset() 	Set characters in memory.
//	wcsftime() 	Formatted date and time output.



//	Wide Character CLASSIFICATION funcs (include wctype.h) <<<---
//	iswalnum() 	True if the character is alphanumeric.
//	iswalpha() 	True if the character is alphabetic.
//	iswblank() 	True if the character is blank (space-ish, but not a newline).
//	iswcntrl() 	True if the character is a control character.
//	iswdigit() 	True if the character is a digit.
//	iswgraph() 	True if the character is printable (except space).
//	iswlower() 	True if the character is lowercase.
//	iswprint() 	True if the character is printable (including space).
//	iswpunct() 	True if the character is punctuation.
//	iswspace() 	True if the character is whitespace.
//	iswupper() 	True if the character is uppercase.
//	iswxdigit() 	True if the character is a hex digit.
//	towlower() 	Convert character to lowercase.
//	towupper() 	Convert character to uppercase.


// 	Restartable Version of the WC CONVERSION funcs
// 	(safe on multithreaded envs, unlike the regular versions of this funcs)
//	mbrtowc()—multibyte to wide character
//	wcrtomb()—wide character to multibyte
//	mbsrtowcs()—multibyte string to wide character string
//	wcsrtombs()—wide character string to multibyte string



//	force C to UTF-8 encode a string with this variable declaration
//	char *s = u8"Hello, world!";
//	printf("%s\n", s);   // Hello, world!--if you can output UTF-8
	

// 	char16_t && char32_t "wide char" types
//	char16_t *s = u"Hello, world!";
//	char16_t c = u'B';
//	char32_t *t = U"Hello, world!";
//	char32_t d = U'B';

//	converting char16_t || char32_t to and from multibyte strings
//	mbrtoc16() 	Convert a multibyte character to a char16_t character.
//	mbrtoc32() 	Convert a multibyte character to a char32_t character.
//	c16rtomb() 	Convert a char16_t character to a multibyte character.
//	c32rtomb() 	Convert a char32_t character to a multibyte character.
//
	

//	3rd Party libraries (CHECK this OUT)
//	- iconv
//		- Internationalization Conversion, a common 
//		POSIX-standard API available on the major platforms.
//	- utf8-proc
//	- ICU 
//		- International Components for Unicode. At least one 
//		blogger found this easy to use.
//


}
