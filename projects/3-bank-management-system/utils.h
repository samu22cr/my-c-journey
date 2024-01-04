
#include <stdbool.h>
#include <wctype.h>

#ifndef UTILS_H
#define UTILS_H

wchar_t* prompt_wchar(wchar_t*, int);
bool prompt_option(int*);

bool iswsblank(wchar_t*);

#endif // end of "if defined UTILS_H"
