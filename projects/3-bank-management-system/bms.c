#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>

#include "log.h"
#include "utils.h"
#include "auth.h"

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
 *		- Able to transfer money to accounts by account ID
 *		- Check credit and debit amounts of money
 *				
 * */



void menu_landing(void) {
	wprintf(L"------------------------------------------------------\n");
	wprintf(L"Welcome to BMS (bank management system)\n");
	wprintf(L"-1.Help		---	print this menu\n");
	wprintf(L"0.Exit		---	leave this program\n");
	wprintf(L"1.Log in	---	log into your existing account\n");
	wprintf(L"2.Register	---	create a new account\n");
}


int main(void)  {

	setlocale(LC_ALL, "");
	menu_landing();

	while (true) {

		int opt;
		wprintf(L"Option? (-1 for help): ");

		if (!prompt_option(&opt)) {
			continue; }

		switch (opt) {
			case -1:
				menu_landing();
				break;
			case 0:
				wprintf(L"Bye bye...\n");
				exit(0);
				break;
			case 1:
				wprintf(L"on LOGIN\n");
				// ask for credentials
				break;
			case 2:
				// ask for info
				register_account();
				break;
			default:
				log_warning(L"Invalid option number!\n");
				break;
		}

	}



}
