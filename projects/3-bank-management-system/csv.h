#include <stdbool.h>
#include "account.h"


#ifndef CSV_H
#define CSV_H

int csv_count_accs();
Account* csv_get_accs(Account accs[], int size);

#endif
