
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>

#include "utils.h"
#include "log.h"
#include "auth.h"

/*
*
* Not gonna check for duplicated emails cause this is only an
* example and it doesn't need to be that realistic
*
* if input has a ","  then it's invalid cause data is stored in
* a csv and don't want to corrupt data, so this func checks for 
* this and in case of it:
* 	- logs error
*
*/
bool register_account(Account *acc) {

	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Account Registration\n");
	wchar_t email_buff[50];
	wchar_t password_buff[50];
	bool registered = false;

	do { wprintf(L"Email: "); }
	while (prompt_wchar(email_buff, 50) == NULL );
	if (wcschr(email_buff, L',') != NULL) {
		log_warning(L"Email can't contain commas(,), try again...\n");
		return registered;
	}

	do { wprintf(L"Password: "); }
	while (prompt_wchar(password_buff, 50) == NULL );
	if (wcschr(password_buff, L',') != NULL) {
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
	int appnd_rs = fwprintf(accounts, L"%ls,%ls,%.2f,\n", email_buff, password_buff, 0.0);
	if(appnd_rs < 0) {
		log_error(L"Couldn't write data to accounts file\n");
		return registered;
	}
	fclose(accounts);


	acc->email = email_buff;
	//acc->password = password_buff; // DON'T store passwd in memory
				         // cause it's insecure
	registered = true;
	return registered;
}

/*
*
* Sets Account struct fields to zero or NULL values
*
* */
void clear_account(Account *acc) {
	acc->email = NULL;
	acc->password = NULL;
	acc->balance = 0.0;
}


