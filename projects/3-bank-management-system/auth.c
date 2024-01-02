
#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>
#include <wctype.h>

#include "utils.h"
#include "log.h"

struct Account {
	wchar_t *email;
	wchar_t *password;
	float balance;
};


/*
*
* Not gonna check for duplicated emails cause this is only an
* example and it doesn't need to be that realistic
*
*/
void register_account(void) {

	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Account Registration\n");
	wchar_t email_buff[50];
	wchar_t password_buff[50];

	do { wprintf(L"Email: "); }
	while (prompt_wchar(email_buff, 50) == NULL );
	do { wprintf(L"Password: "); }
	while (prompt_wchar(password_buff, 50) == NULL );

	struct Account a = {
		.email = email_buff,
		.password = password_buff
	};

	FILE *accounts;
	accounts = fopen("accounts.txt", "a");

	wprintf(L"%ls %ls %f\n", email_buff, password_buff, 0.000);

//	int print_rs = fwprintf(accounts, L"%ls %ls %f\n", a.email, a.password, a.balance);
//
//	if (print_rs < 0) {
//		log_error(L"Couldn't persist account, try again later\n");
//	} else {
//		wprintf(L"Successfully created account!\n");
//	}
	fclose(accounts);

}
