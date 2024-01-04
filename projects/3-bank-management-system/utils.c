#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>

#include "log.h"

/*
*
* returns:
* 	- a pointer to the recently assigned buff
*
*/
wchar_t* prompt_wchar(wchar_t *buff, int size) {
	errno = 0;
	wchar_t *tmpbuff = fgetws(buff, size, stdin);
	if (tmpbuff == NULL) { 
		log_error(L"Error: Couldn't read from stdin\n");
		if (errno == EILSEQ) {
			log_warning(L"Invalid character encounterd.\n");
		} else if (feof(stdin)) {
			// nothing, just reached the fucking WEOF
		} else {
			log_warning(L"Some error ocurrend while reading input\n");
		}
	} 
	// this removes \n for the tmp buffer
	// 	- this happens cause cause fgetws() 
	// 	func reads from current stream position
	// 	TO AND INCLUDING the FIRST NEW LINE CHAR,
	//
	//	As a result wcslen(wchar_t[] - 1)
	//	is a newline character (LN, CR, 
	//	LNCR, etc..).
	//
	//	- wchar_t end if a NUL WIDE CHAR(\0)
	//	so above \n can't be last)
	//	
	//
	tmpbuff[wcslen(tmpbuff) - 1] = L'\0';
	//wprintf(L"%ls", tmpbuff);
	return tmpbuff;
}

/*
* Description:
* 	- Prompts from an integer value
* 	from stdin and assigns it to the pointer
* 	passed as arg
* returns:
* 	- true if success assiging &opt
* 	- false if mf hasn't entered valid opt OR
* 	if reached EOF (aka mf presses enter key)
*
*/
bool prompt_option(int *opt) {

	wchar_t buff[10];
	errno = 0;
	
	if (fgetws(buff, 10, stdin) == NULL) { 
		wprintf(L"Error: Couldn't read from stdin\n");
		if (errno == EILSEQ) {
			log_warning(L"Invalid character encounterd.\n");
		} else if (feof(stdin)) {
			// nothing, just reached the fucking WEOF
		} else {
			log_warning(L"Some error ocurrend while reading input\n");
		}
	} else {
		// could read input, now to do some fucking convertion
		errno = 0; 
		bool success =  false;
		int scan_rs = swscanf(buff, L"%d", opt); 

		if (errno == EINVAL) {
			log_error(L"Invalid argument for swscanf func\n"); 
		}

		if (scan_rs == 1) {
			success = true;
		} else if (scan_rs == EOF) {
			// mf pressed enter so shuld re-prompt on caller func
		} else {
			log_warning(L"Invalid option, try entering a number...\n");
		}
		return success;
	}

}
