#include <wctype.h>

#ifndef LOG_H
#define LOG_H

void log_warning(wchar_t *fmt, ...);
void log_error(wchar_t *fmt, ...);
void log_info(wchar_t *fmt, ...);
void log_debug(wchar_t *fmt, ...);

#endif
