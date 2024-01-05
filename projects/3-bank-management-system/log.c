
#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#include <wctype.h>


enum LogLevel {
	//EMERGENCY = 0,
	//ALERT = 1,
	//CRITICAL = 2,
	ERROR = 3,
	WARNING = 4,
	//NOTIFICATION = 5,
	INFO = 6,
	DEBUG = 7,
};


void log_warning(wchar_t *fmt, ...) {
	va_list var_args;
	va_start(var_args, fmt);
	wprintf(L"\033[33m[WARNING]: \033[0m");
	vwprintf(fmt, var_args);
	va_end(var_args);
}

void log_error(wchar_t *fmt, ...) {
	va_list var_args;
	va_start(var_args, fmt);
	wprintf(L"\033[0;31m[ERROR]: \033[0m"); 
	vwprintf(fmt, var_args);
	va_end(var_args);
}

void log_info(wchar_t *fmt, ...) {
	va_list var_args;
	va_start(var_args, fmt);
	wprintf(L"\033[0;32m[INFO]: \033[0m"); 
	vwprintf(fmt, var_args);
	va_end(var_args);
}


void log_debug(wchar_t *fmt, ...) {
	va_list var_args;
	va_start(var_args, fmt);
	wprintf(L"\033[0;34m[DEBUG]: \033[0m"); 
	vwprintf(fmt, var_args);
	va_end(var_args);
}

