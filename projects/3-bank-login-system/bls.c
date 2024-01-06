#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>

#include "log.h"
#include "utils.h"
#include "account.h"

/*
 * 
 * Kinda basic bank CLI tool that manages bank data from accounts
 * 	- NOTES:
 * 		- accounts.csv should
 * 			- be comma separated
 * 			- first line should be name of columns 
 * 			- one record per line
 *	- FEATURES:
 *		- Login Functionality -> DONE
 *			- credentials not stored securely btw
 *		- Account management
 *			- Create account -> DONE
 *		- Check balance of account -> DONE
 * */



static void menu_landing(void) {
	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Welcome to BLS (bank login system)\n");
	wprintf(L"-1.Help\n");
	wprintf(L" 0.Exit\n");
	wprintf(L" 1.Log in\n");
	wprintf(L" 2.Register\n");
}

static void menu_logged(Account *acc) {
	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Welcome (logged as %ls) \n", acc->email);
	wprintf(L"-1.Help\n");
	wprintf(L" 0.Exit\n");
	wprintf(L" 1.Log out\n");
	wprintf(L" 2.Check Balance\n");
}



int main(void)  {

	setlocale(LC_ALL, "");

	menu_landing();
	bool session = false;
	Account crrnt_acc;

	while (true) {

		int opt;
		wprintf(L"Option? (-1 for help): ");
		if (!prompt_option(&opt)) {
			continue; 
		}

		if (session) {

			switch (opt) {
				case -1:
					menu_logged(&crrnt_acc);
					break;
				case 0:
					exit(EXIT_FAILURE);
					break;
				case 1:
					acc_clear(&crrnt_acc); // necessary???
					wprintf(L"Bye bye...\n");
					menu_landing();
					break;
				case 2:
					wprintf(L"Balance: $%.2f\n", crrnt_acc.balance);
					break;
				default:
					log_warning(L"Invalid option number!\n");
					break;
			}
		} else {
			switch (opt) {
				case -1:
					menu_landing();
					break;
				case 0:
					wprintf(L"Bye bye...\n");
					exit(EXIT_FAILURE);
					break;
				case 1:
					session = acc_login(&crrnt_acc);
					if (session) {
						menu_logged(&crrnt_acc);
					} 
					break;
				case 2:
					session = acc_register(&crrnt_acc);
					if (session) {
						menu_logged(&crrnt_acc);
					} else {
						menu_landing();
					}
					break;
				default:
					log_warning(L"Invalid option number!\n");
					break;
			}
		}
	}
}
