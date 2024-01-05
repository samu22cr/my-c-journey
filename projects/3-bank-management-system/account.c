
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>

#include "utils.h"
#include "log.h"
#include "account.h"
#include "csv.h"




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
* Sets Account credentials to valid input
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

void acc_logout(Account *crrnt_acc) {
	free(crrnt_acc.balance); // previously dynamically allocated on acc_login() func
	acc_clear(crrnt_acc); // necessary???
	wprintf(L"Bye bye...\n");
}

/*
* 
* returns true if successfully logged in, false otherwise
* */

bool acc_login(Account *crrnt_acc) {

	Account acc;
	acc_prompt_credentials(&acc);
	int num_accs = csv_count_accs();
	bool authd = false;

	if (num_accs == -1) {
		log_error(L"Sorry, we can't log you in right now, try later...\n");
		return authd;
	}

	Account accs[num_accs];
	Account *rs_get = csv_get_accs(accs, num_accs);

	if (rs_get == NULL) {
		log_error(L"Couldn't read accounts data\n");
		return authd;
	}

	for (int i = 0; i < num_accs; i++) {

		Account curr_acc = accs[i];
		bool same_email = wcscmp(curr_acc.email, acc.email) == 0;
		bool same_password = wcscmp(curr_acc.password, acc.password) == 0;

		if (same_email && same_password) {
			
			// set crrnt_acc with logged in account values and break loop

			wcsncpy(crrnt_acc->email, acc.email, ACC_EMAIL_SIZE);

			float *heap_balance = malloc(sizeof(float));
			heap_balance = &acc.balance;
			crrnt_acc->balance = *heap_balance; // need to free() when logging out

			authd = true;
			break; // learned today that you can 
			       // also break for loops, what the flip
		} 
	}
	if (!authd) {
		log_warning(L"Not logged in, try again...\n");
	}
	return authd;
}


/*
* returns true if account exists in CSV file, false otherwise
*
* */
static bool acc_exists(Account *acc) {

	int num_accs = csv_count_accs();
	Account accs[num_accs];


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

	acc_prompt_credentials(acc);

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


