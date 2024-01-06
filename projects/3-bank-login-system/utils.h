
#include <stdbool.h>
#include <wctype.h>

#ifndef UTILS_H
#define UTILS_H

wchar_t* prompt_wcs(wchar_t*, int);
bool prompt_option(int*);
void prompt_storable_input(wchar_t* buff, int size, wchar_t* label);

bool iswsblank(wchar_t*);

#endif // end of "if defined UTILS_H"
