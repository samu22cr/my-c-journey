#include <stdio.h>
#include <locale.h>


int main(void) {
	setlocale(LC_ALL, "");  // Use this environment's locale for everything
	struct lconv *x = localeconv();
}
