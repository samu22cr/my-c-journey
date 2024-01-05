#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>
#include <wchar.h>
#include <errno.h>

#include "log.h"
#include "account.h"


/*
*
* returns number of accounts in file OR -1 if error
*
* */
int csv_count_accs() {

	wchar_t fbuff[50]; 
	FILE *accounts;
	accounts = fopen("accounts.csv", "r");

	errno = 0;
	int line = 0;
	int num_accs = 0;
	while (fgetws(fbuff, sizeof fbuff, accounts) != NULL) {

		if (line > 0) {
			num_accs++;
		}
		line++;

	}
	if (errno == EILSEQ) {
		log_error(L"Invalid character encounterd in .csv file\n");
		return -1;
	} else if (ferror(accounts)) {
		log_error(L"Had trouble reading accounts.csv file\n");
		return  -1;
	}
	fclose(accounts);
	return num_accs;
}

/*
*
* Description: fills an array of accounts
* with 'size' elements read from the .csv 
*
* returns 
* 	- on success: address of accs[]
* 	- on error: NULL
*
* */
Account* csv_get_accs(Account accs[], int size) {

	wchar_t fbuff[50]; // 1024 is way to much (???), maybe try 50 
	FILE *accounts;
	accounts = fopen("accounts.csv", "r");

	errno = 0;
	int lines = 0; 
	int num_accs = 0;
	while (fgetws(fbuff, sizeof fbuff, accounts) != NULL) {

		if (lines > 0 && num_accs <= size) { // so we don't read first line which has column names

			wchar_t * state_tkzr;
			wchar_t *sep = L",";
			wchar_t *token = wcstok(fbuff, sep, &state_tkzr);

			//wprintf(L"TOKENS: \n");
			
			int field_count = 0;
			while(token != NULL) {

				switch (field_count) {
					case 0:
						wcsncpy(accs[num_accs].email, token, ACC_EMAIL_SIZE);
						break;
					case 1:
						wcsncpy(accs[num_accs].password, token, ACC_EMAIL_SIZE);
						// don't read passwd cause insecure???
						// but I need to read password field for 
						// the "login" functionality, which is
						// obviously insecure cause storing passwds in 
						// plain text
						break;
					case 2:
						errno = 0;
						float balance = wcstof(token, NULL);
						if (errno == ERANGE) {
							log_error(L"Balance value is to big to convert, sorry!\n");
							return NULL;
							break;
						}
						accs[num_accs].balance = balance;
						break;
					default: 
						//log_error(L"Account only has 3 fields but data src has more\n");
						break;
				}
				field_count++;
				token = wcstok(NULL, sep, &state_tkzr);
			}
			num_accs++;
		} 
		lines++; 

	}

	if (errno == EILSEQ) {
		log_error(L"Invalid character encounterd.\n");
		return NULL;
	}
	else if (ferror(accounts)) {
		log_error(L"Had trouble reading accounts.csv file\n");
		return NULL;
	}
	fclose(accounts);
	return accs;
}




