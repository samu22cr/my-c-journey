#include <stdio.h>
#include <stdbool.h>

/*
	- Should be able to
		- sum 
		- substract
		- multiply
		- divide
		- determine if # is even or odd
	NOTE:
		- Floats don't work since I
		don't know how to use doubles
		or floats yet!
*/

// Some prototypes...
void show_opt_menu(void);
void prompt_nums(int *num1, int *num2);
int sum(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);

int main(void) {
	bool prompting = true;
	show_opt_menu();
	while(prompting) {
		int opt;
		printf("Option? (-1 for help): ");
		scanf("%d", &opt);
		int num1;
		int num2;
		switch(opt) {
			case -1:	
				show_opt_menu();
				break;
			case 0:
				printf("Ok, bye!\n");
				prompting = false;
				break;
			case 5:	
				printf("Enter desired #: ");
				scanf("%d", &num1);
				if(opt % 2 == 0) {
					printf("%d is even!\n", num1);
				} else {
					printf("%d is odd!\n", num1);
				}
				break;
			default:
				if (
					opt == 1 || 
					opt == 2 || 
					opt == 3 || 
					opt == 4
				) {
					prompt_nums(&num1, &num2);
					switch(opt) {
						case 1:	
							printf("%d + %d = %d\n", num1, num2, sum(num1, num2));
							break;
						case 2:	
							printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
							break;
						case 3:	
							printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
							break;
						case 4:	
							printf("%d / %d = %d\n", num1, num2, divide(num1, num2));
							break;
					}
					break;
				} else {
					printf("Invalid option! try again...\n");
					break;
				} 
		}

	}
}


void prompt_nums(int *num1, int *num2) {
	printf("Enter first number: ");
	scanf("%d", num1);
	printf("Enter second number: ");
	scanf("%d", num2);
}


void show_opt_menu(void) {
	printf("--------------------------------------------------------\n");
	printf("Select option number:\n");
	//printf("-1. Show menu\n");
	printf("0. Exit\n");
	printf("1. Sum\n");
	printf("2. Substract\n");
	printf("3. Multiply\n");
	printf("4. Divide\n");
	printf("5. Even or odd ?\n");
	printf("--------------------------------------------------------\n");
}

// Created these basic functions 
// just for the sake of using
// functions in a C program
int sum(int num1, int num2) { return num1 + num2; }
int subtract(int num1, int num2) { return num1 - num2; }
int multiply(int num1, int num2) { return num1 * num2; }
int divide(int num1, int num2) {
	// don't revise for 0 division
	// errors cause don't know how
	// to handle errors/exceptions 
	// yet
	return num1 / num2;
}

