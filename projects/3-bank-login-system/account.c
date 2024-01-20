
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <string.h>

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


/*
* returns true if account exists in CSV file, false otherwise
*
* */
bool acc_exists_by_email(wchar_t *email) {

	bool exists = false;
	int num_accs = csv_count_accs();

	if (num_accs == -1) {
		log_error(L"You can't access data right now, try later...\n");
		return exists;
	}

	Account accs[num_accs];
	Account *rs_get = csv_get_accs(accs, num_accs);
	if (rs_get == NULL) {
		log_error(L"Couldn't read accounts data\n");
		return exists;
	}

	for (int i = 0; i < num_accs; i++) {
		Account iter_acc = accs[i];
		bool email_exists = wcscmp(iter_acc.email, email) == 0;
		if (email_exists) {
			exists = true;
			break;
		}
	}
	return exists;
}

/*
 * Finds account struct by email from csv and if found,
 * assigns fields from csv to passed struct pointer (acc)
* returns 
* 	- if found: pointer of desired account
* 	- if not found: NULL
*
* */
static Account* acc_find_by_email(wchar_t* email, Account *acc) {

	int num_accs = csv_count_accs();
	if (num_accs == -1) {
		log_error(L"You can't access data right now, try later...\n");
		return NULL;
	}

	Account accs[num_accs];
	Account *rs_get = csv_get_accs(accs, num_accs);
	if (rs_get == NULL) {
		log_error(L"Couldn't read accounts data\n");
		return NULL;;
	}

	for (int i = 0; i < num_accs; i++) {
		Account iter_acc = accs[i];
		bool matches = wcscmp(iter_acc.email, email) == 0;
		if (matches) {
			wcsncpy(acc->email, iter_acc.email, ACC_EMAIL_SIZE);
			wcsncpy(acc->password, iter_acc.password, ACC_PASSWORD_SIZE); //INSECURE AS HELL
			memcpy(&acc->balance, &iter_acc.balance, sizeof(float));
			return acc; // returning a POINTER to the passed arg
		}
	}
	return NULL;
}




/*
* 
* returns true if successfully logged in, false otherwise
*
* */
bool acc_login(Account *acc) {

	Account credentials_acc;
	prompt_storable_input(credentials_acc.email, ACC_EMAIL_SIZE, L"Email");
	prompt_storable_input(credentials_acc.password, ACC_PASSWORD_SIZE, L"Password");
	
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
		Account iter_acc = accs[i];
		bool same_email = wcscmp(iter_acc.email, credentials_acc.email) == 0;
		bool same_password = wcscmp(iter_acc.password, credentials_acc.password) == 0;

		if (same_email && same_password) {
			wcsncpy(acc->email, iter_acc.email, ACC_EMAIL_SIZE);
			wcsncpy(acc->password, iter_acc.password, ACC_PASSWORD_SIZE); // INSECURE AS HELL
			memcpy(&acc->balance, &iter_acc.balance, sizeof(float));
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
* Registers an account to the .csv file only if
* provided email isn't registered yet 
*/
bool acc_register(Account *acc) {

	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Account Registration\n");
	bool registered = false;

	while (true) {
		prompt_storable_input(acc->email, ACC_EMAIL_SIZE, L"Email");
		if (acc_exists_by_email(acc->email)) {
			log_warning(L"Can't use %ls, cause another account is using it\n", acc->email);
			continue;
		} else {
			break;
		}
	}

	prompt_storable_input(acc->password, ACC_EMAIL_SIZE, L"Password");
	Account *rs_save = csv_save_acc(acc);

	if (rs_save != NULL) {
		registered = true;
	} else {
		log_error(L"Couldn't register account, try again later...\n");
		return false;
	}
	return registered;
}



/*
* NOT WORKING:
* 	feature not implemented and probably NEVER will be implemented
*
*
* Transfers money from one account to another
*
* */
//void acc_transfer(Account *src_acc) {
//	wprintf(L"------------------------------------------------------\n");
//	wprintf(L"Transfer Money\n");
//
//	wchar_t dst_email[ACC_EMAIL_SIZE];
//	Account dst_acc;
//	while (true) {
//		prompt_storable_input(dst_email, ACC_EMAIL_SIZE, L"Destinaton account (email)");
//		if (acc_find_by_email(dst_email, &dst_acc) != NULL) {
//			break;
//		} else {
//			log_warning(L"Account doesn't exist\n");
//			continue;
//		}
//	}
//
//	wchar_t buff_amount[50];
//	wprintf(L"Your current balance %.2f\n", src_acc->balance);
//	float amount;
//	while (true) {
//		prompt_storable_input(buff_amount, 50, L"Amount to transfer");
//		errno = 0;
//		amount = wcstof(buff_amount, NULL);
//		if (amount == 0.0f) { // wcstof returns 0.0f on error (awful decision btw, 
//		        	      // cause what if trying to actually parse "0.0f" to float
//			log_warning(L"Can't parse tha number, try again...\n");
//			continue;
//		} else if ( errno == ERANGE) {
//			log_warning(L"Can't represent value, try again...\n ");
//			continue;
//		} else {
//			break;
//		}
//	}
//
//	if (amount > src_acc->balance) {
//		log_warning(L"Can't transfer more money than you have, dummy\n");
//		log_warning(L"Returning to menu...");
//		return;
//	}
//
//	float new_src_balance = src_acc->balance - amount;
//	memcpy(&src_acc->balance, &new_src_balance, sizeof(float));
//	dst_acc.balance += amount;
//
//
//	Account *rs_persist_src = csv_save_acc(src_acc);
//	if (rs_persist_src == NULL) {
//		log_error(L"Unable to transfer money, try again later...\n");
//		float prev_src_balance = src_acc->balance + amount;
//		memcpy(&src_acc->balance, &prev_src_balance, sizeof(float));
//		// dst_acc->balance -= amount; ON STACK
//		return;
//	}
//
//	Account *rs_persist_dst = csv_save_acc(&dst_acc);
//	if (rs_persist_dst == NULL) {
//		log_error(L"Unable to transfer money, try again later...\n");
//		float prev_src_balance = src_acc->balance + amount;
//		memcpy(&src_acc->balance, &prev_src_balance, sizeof(float));
//		//dst_acc->balance -= amount; ON STACK
//		return;
//	}
//
//	log_info(L"Successfully transfered money!\n");
//}
