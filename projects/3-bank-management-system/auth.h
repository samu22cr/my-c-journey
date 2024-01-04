#include <stdbool.h>

#ifndef AUTH_H
#define AUTH_H

typedef struct {
	wchar_t *email;
	wchar_t *password;
	float balance;
} Account;

bool register_account(Account *acc);
void clear_account(Account *acc);

#endif 
