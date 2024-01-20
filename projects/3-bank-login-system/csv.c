#include <stdio.h>
#include <stdlib.h>
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
		fclose(accounts);
		return -1;
	} else if (ferror(accounts)) {
		log_error(L"Had trouble reading accounts.csv file\n");
		fclose(accounts);
		return  -1;
	}
	fclose(accounts);
	return num_accs;
} /*
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
							fclose(accounts);
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
		fclose(accounts);
		return NULL;
	}
	else if (ferror(accounts)) {
		log_error(L"Had trouble reading accounts.csv file\n");
		fclose(accounts);
		return NULL;
	}
	fclose(accounts);
	return accs;
}

/*
*
* Description: create and persists account
*
* returns 
* 	- on success: address of accs
* 	- on error: NULL
* */
Account* csv_save_acc(Account *acc) {

		// append to file
		FILE *accounts;
		accounts = fopen("accounts.csv", "a");
		if (accounts == NULL) {
			log_error(L"Couldn't open accounts file\n");
			return NULL;
		}
		errno = 0;
		int appnd_rs = fwprintf(
			accounts, 
			L"%ls,%ls,%.2f,\n",
			acc->email, acc->password, acc->balance
		);
		if(appnd_rs < 0) {
			log_error(L"Couldn't write data to accounts file\n");
			fclose(accounts);
			return NULL;
		}
		fclose(accounts);
		return acc;
}



/*
*
* DOESN'T WORK:
* 	- feature not implemented yet, and no plan to implement it,
* 	probably NEVER
*
* Description: create and persists account
* if not exists or update if already exists
*
* returns 
* 	- on success: address of accs
* 	- on error: NULL
* */
//Account* csv_save_acc(Account *acc) {
//
//	if (acc_exists_by_email(acc->email)) {
//
//		// update csv
//		// 1. First find in which line of file is acc located
//		// 2. Then replace that whole line
//		// 3. Finally close file and return ptr to passed acc arg
//		// to indicate success
//
//		wchar_t fbuff[4096]; 
//		FILE *accounts;
//		accounts = fopen("accounts.csv", "a+");
//
//		if (accounts == NULL) {
//			log_error(L"Couldn't read accounts .csv file\n");
//			fclose(accounts);
//			return NULL;
//		}
//
//		if (fseek(accounts, 0, SEEK_SET) != 0) {
//			log_error(L"Trouble setting file position indicator on accounts.csv\n");
//			fclose(accounts);
//			return NULL;
//		}
//
//
//		errno = 0;
//		int crrnt_line = 0; 
//		long int cpos;
//		bool found = false;
//		while (fgetws(fbuff, sizeof fbuff, accounts) != NULL && !found) {
//
//			if (crrnt_line > 0 ) {
//			// ^^^so we don't read first line which has column names
//				wchar_t * state_tkzr;
//				wchar_t *sep = L",";
//				wchar_t *token = wcstok(fbuff, sep, &state_tkzr);
//				int field_count = 0;
//				while(token != NULL) {
//					switch (field_count) {
//						case 0:
//							wprintf(L"Chekinf if [%ls] matches with [%ls]\n", token, acc->email);
//							bool matches = wcscmp(acc->email, token) == 0;
//							if (matches) {
//
//								log_debug(L"ONE ACCOUNT MATCHES\n");
//
//								log_debug(L"MATCH AT POSITION: %ld\n");
//								if (fseek(accounts, cpos, SEEK_SET) != 0) {
//									log_error(L"Trouble setting file position indicator on accounts.csv\n");
//									fclose(accounts);
//									return NULL;
//								}
//
//								found = true;
//								wchar_t lbuff[128];
//
//								log_debug(L"CREATING RECORD\n");
//
//								int sfmt_rs = swprintf(
//									lbuff,
//									128,
//									L"%ls,%ls,%.2f,\n",
//									acc->email, acc->password, acc->balance
//								);
//								log_debug(L"record to be written: %ls", lbuff);
//								if (sfmt_rs < 0) {
//									log_error(L"Couldn't format data in order to persist it\n");
//									fclose(accounts);
//									return NULL;
//								}
//
//								log_debug(L"WRITTING RECORD\n");
//
//								//int appnd_rs = fwprintf(
//									//accounts, 
//									//L"%ls,%ls,%.2f,\n",
//									//acc->email, acc->password, acc->balance
//								//);
//								//if(appnd_rs < 0) {
//									//log_error(L"Couldn't write data to accounts file\n");
//									//fclose(accounts);
//									//return NULL;
//								//}
//								//log_debug(L"RECORD WRITTEN\n");
//
//								fputws(lbuff, accounts);
//								//size_t len_lbuff = wcslen(lbuff);
////
//								//errno = 0;
//								//int fw_rs = fwrite(
//									//lbuff,
//									//sizeof(wchar_t),
//									//len_lbuff,
//									//accounts
//								//);
////
//								//log_debug(L"fw_rs : %d\n", fw_rs);
//								//if (fw_rs != len_lbuff) {
//									//log_error(L"Couldn't properly write data\n");
//									//fclose(accounts);
//									//return NULL;
//								//}
//
//								log_debug(L"RETURNING PERSISTED ACCOUNT SUCCESSFULLY\n");
//								return acc;
//
//							}
//							break;
//						case 1:
//							break;
//						case 2:
//							break;
//						default: 
//							break;
//					}
//					field_count++;
//					token = wcstok(NULL, sep, &state_tkzr);
//				}
//			} 
//			cpos = ftell(accounts);
//			if (cpos == -1) {
//				log_error(L"Couldn't get file position indicator for accounts.csv\n");
//			}
//			crrnt_line++; 
//
//		}
//		if (errno == EILSEQ) {
//			log_error(L"Invalid character encounterd.\n");
//			fclose(accounts);
//			return NULL;
//		}
//		else if (ferror(accounts)) {
//			log_error(L"Had trouble reading accounts.csv file\n");
//			fclose(accounts);
//			return NULL;
//		}
//		if (!found) {
//			log_error(L"Couldn't found account, though it was previously found...\n");
//			fclose(accounts);
//			return NULL;
//		}
//		fclose(accounts);
//		return acc;
//	} else {
//		// append to file
//		FILE *accounts;
//		accounts = fopen("accounts.csv", "a");
//		if (accounts == NULL) {
//			log_error(L"Couldn't open accounts file\n");
//			return NULL;
//		}
//		errno = 0;
//		int appnd_rs = fwprintf(
//			accounts, 
//			L"%ls,%ls,%.2f,\n",
//			acc->email, acc->password, acc->balance
//		);
//		if(appnd_rs < 0) {
//			log_error(L"Couldn't write data to accounts file\n");
//			fclose(accounts);
//			return NULL;
//		}
//		fclose(accounts);
//		return acc;
//	}
//}
