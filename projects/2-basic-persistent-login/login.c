#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NAME_LEN 20

/*
	- basic (non-secure) login should be able to:
		- read users from file
		- let user authenticate via username/password
		- let user create accounts
	- there isn't error checking on some stuff I still don't know
	how to check (example: how to get strings with whitespaces when using scanf()
*/


struct user {
	char *name;
	char *password;
};


void print_home_menu(void) {
	printf("---------------------------------------------------\n");
	printf("0. Exit\n");
	printf("1. Login\n");
	printf("2. Create Account\n");
	printf("---------------------------------------------------\n");
}

void print_logged_in_menu(void) {
	printf("---------------------------------------------------\n");
	printf("0. Exit\n");
	printf("1. Log out\n");
	printf("---------------------------------------------------\n");
}


void login_prompt(struct user *u) {

	char username[NAME_LEN];
	printf("Username: ");
	scanf("%s", username);
	u->name = strdup(username);

	char password[NAME_LEN];
	printf("Password: ");
	scanf("%s", password);
	u->password = strdup(password);
}



bool authenticate(struct user *u) {

	FILE* fp;
	fp = fopen("users.txt", "r");
	char username[NAME_LEN];
	char password[NAME_LEN];
	int count = 0;

	bool authd = false;
	while (fscanf(fp, "%s %s", username, password) != EOF) {

		bool same_name = strcmp(u->name, username) == 0;
		bool same_password = strcmp(u->password, password) == 0;

		if(same_name && same_password) {
			authd = true;
			printf("authenticated!!!\n");
			break;
		} 
	}
	if(!authd) {
		printf("No usernames/passwords match, sorry...\n");
	}
	fclose(fp);
	return authd;
}


void persist_user(struct user *u) {
	FILE *fp;
	fp = fopen("users.txt", "a");
	fprintf(fp,"%s %s\n", u->name, u->password);
	fclose(fp);
}

int main(void) {
	
	bool prompting = true;
	bool session  = false; // 0 = unauthenticated, 1 = authenticated	
	print_home_menu();

	while(prompting) {

		int mode;
		printf("Option? (-1 for help): ");
		scanf("%d", &mode);
		struct user u;
		
		if(!session) {
			switch(mode) {
				case -1:
					print_home_menu();
					break;
				case 0:
					printf("Bye bye!\n");
					prompting = false;
					break;
				case 1:
					login_prompt(&u);
					session = authenticate(&u);
					if(session) {
						print_logged_in_menu();
					}
					break;
				case 2:
					printf("Creating account...\n");
					login_prompt(&u);
					persist_user(&u);
					session = true;
					print_logged_in_menu();
					break;
				default: 
					printf("Invalid option!\n");
					break;
				
			}
		} else {
			switch(mode) {	
				case -1:
					print_home_menu();
					break;
				case 0:
					printf("Bye bye!\n");
					prompting = false;
					break;
				case 1:
					printf("Logging out...!\n");
					print_home_menu();
					session = false;
					break;
			}
		}
		
	}



}


