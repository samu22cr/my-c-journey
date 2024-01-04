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
 * Bank CLI tool that manages bank data from an EMPLOYESS persective
 * 	- NOTES:
 * 		- For future projects, need to learn to
 * 		read from a file format (csv, json, db, whatever)
 * 		to make persistence more flexible;
 *
 *	- Features:
 *		- Login Functionality 
 *			- credentials not stored securely btw
 *		- Account management
 *			- Create account
 *			- Delete account
 *		- Able to transfer money to accounts 
 *		- Check credit and debit amounts of money
 *				
 * */



static void menu_landing(void) {
	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Welcome to BMS (bank management system)\n");
	wprintf(L"-1.Help		---	print this menu\n");
	wprintf(L"0.Exit		---	leave this program\n");
	wprintf(L"1.Log in		---	log into your existing account\n");
	wprintf(L"2.Register		---	create a new account and log in\n");
}

static void menu_logged(Account *acc) {
	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Welcome (logged as %ls) \n", acc->email);
	wprintf(L"-1.Help		---	print this menu\n");
	wprintf(L"0.Exit		---	leave this program\n");
	wprintf(L"1.Log out		---	end this session\n");
	wprintf(L"2.Transfer money 	---	transference\n");
	wprintf(L"3.Check balance 	---	money money money\n");
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
					acc_clear (&crrnt_acc); // necessary???
					wprintf(L"Bye bye...\n");
					exit(EXIT_FAILURE);
					break;
				case 1:
					acc_clear(&crrnt_acc);
					session = false;
					menu_landing();
					break;
				case 2:
					// transfer money
					acc_transfer(&crrnt_acc);
					break;
				case 3:
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
					session = acc_login();
					break;
				case 2:
					session = acc_register(&crrnt_acc);
					menu_logged(&crrnt_acc);
					break;
				default:
					log_warning(L"Invalid option number!\n");
					break;
			}
		}
	}
}
