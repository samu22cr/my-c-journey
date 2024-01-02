#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>

#include "log.h"

/*
*
* returns:
* 	- true if success assiging &char
* 	- false if mf hasn't entered valid opt OR
* 	if reached EOF (aka mf presses enter key)
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
	return tmpbuff;
}

/*
*
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