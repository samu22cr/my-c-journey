
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>

#include "utils.h"
#include "log.h"
#include "account.h"




/*
*
* Sets Account struct fields to zero/empty/NULL values
*
* */
void acc_clear(Account *acc) {
	wmemset(acc->email, L'\0', ACC_EMAIL_SIZE);
	wmemset(acc->password, L'\0', ACC_PASSWORD_SIZE);
	acc->balance = 0.0;
}

void acc_transfer(Account *acc) {
	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Transfer Money\n");
}

/*
*
*
*
* */
static void acc_prompt_credentials(Account *acc) {

	bool valid_email = false;
	bool valid_pass = false;
	while(true) {

		if (!valid_email) {

			do { wprintf(L"Email: "); }
			while (prompt_wchar(acc->email, ACC_EMAIL_SIZE) == NULL );

			if (wcschr(acc->email, L',') != NULL) {
				log_warning(L"Email can't contain commas(,), try again...\n");
				continue;
			} 
			else if (iswsblank(acc->email)) {
				log_warning(L"Email can't be blank, try again...\n");
				continue;
			} 
			else {
				valid_email = true;
			}
		}

		if(!valid_pass) {

			do { wprintf(L"Password: "); }
			while (prompt_wchar(acc->password, ACC_PASSWORD_SIZE) == NULL );

			if (wcschr(acc->password, L',') != NULL) {
				log_warning(L"Password can't contain commas(,), try again...\n");
				continue;
			}
			else if (iswsblank(acc->password)) {
				log_warning(L"Password can't be blank, try again...\n");
				continue;
			}
			else {
				valid_pass = true;
				break;
			}
		}
	}
}



bool acc_login() {

	// get user credentials
	Account acc;
	acc_prompt_credentials(&acc);



}

/*
* 	PENDING: CHECK FOR DUPLICATED EMAILS while registering
*
*
*/

bool acc_register(Account *acc) {

	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Account Registration\n");
	bool registered = false;

	do { wprintf(L"Email: "); }
	while (prompt_wchar(acc->email, ACC_EMAIL_SIZE) == NULL );
	if (wcschr(acc->email, L',') != NULL) {
		log_warning(L"Email can't contain commas(,), try again...\n");
		return registered;
	}

	do { wprintf(L"Password: "); }
	while (prompt_wchar(acc->password, ACC_PASSWORD_SIZE) == NULL );
	if (wcschr(acc->password, L',') != NULL) {
		log_warning(L"Password can't contain commas(,), try again...\n");
		return registered;
	}

	FILE *accounts;
	accounts = fopen("accounts.csv", "a");
	if (accounts == NULL) {
		log_error(L"Couldn't open accounts file\n");
		return registered;
	}

	errno = 0;
	int appnd_rs = fwprintf(accounts, L"%ls,%ls,%.2f,\n", acc->email, acc->password, 0.0);
	if(appnd_rs < 0) {
		log_error(L"Couldn't write data to accounts file\n");
		return registered;
	}
	fclose(accounts);
	registered = true;
	return registered;
}


