#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>
#include <wchar.h>
#include <errno.h>

#include "log.h"


int main(void) {


	wchar_t fbuff[50]; // 1024 is way to much (???), maybe try 50 
	FILE *accounts;
	accounts = fopen("accounts.csv", "r");

	int count = 0; // !DELETE THIS

	errno = 0;
	while (fgetws(fbuff, sizeof fbuff, accounts) != NULL) {

		wchar_t * state_tkzr;
		wchar_t *sep = L",";
		wchar_t *token = wcstok(fbuff, sep, &state_tkzr);

		wprintf(L"TOKENS: \n");
		while(token != NULL) {
			wprintf(L"%ls\n", token);
			token = wcstok(NULL, sep, &state_tkzr);
		}

		count++; // !DELETE THIS
	}

	if (errno == EILSEQ) {
		log_error(L"Invalid character encounterd.\n");
	} 
	else if (ferror(accounts)) {
		log_error(L"Had trouble reading accounts.csv file\n");
	}

	fclose(accounts);
}
