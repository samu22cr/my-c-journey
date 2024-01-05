#include <stdbool.h>

#ifndef ACCOUNT_H
#define ACCOUNT_H

#define ACC_EMAIL_SIZE 50
#define ACC_PASSWORD_SIZE 50

typedef struct {
	wchar_t email[ACC_EMAIL_SIZE];
	wchar_t password[ACC_PASSWORD_SIZE];
	float balance;
} Account;

void acc_clear(Account *acc);
void acc_transfer(Account *acc);
bool acc_login(Account *acc);
bool acc_register(Account *acc);
bool acc_exists_by_email(wchar_t*);

#endif 




