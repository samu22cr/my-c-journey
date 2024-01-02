#include <stdio.h>
#include <wchar.h>
#include <wctype.h>


void log_warning(wchar_t *msg) {
	wprintf(L"\033[33m[WARNING]: %ls\033[0m", msg);
	//wprintf(L"\033[33m[WARNING]: %ls\033[0m\n", msg); // no implicit \n
}

void log_error(wchar_t *msg) {
	wprintf(L"\033[0;31m"); 
	wprintf(L"[ERROR]: %s", msg); 
	wprintf(L"\033[0m"); 
}
