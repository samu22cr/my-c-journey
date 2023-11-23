#include <stdio.h>

void hello(void); // this is the prototype
int plus_one(int t); // this is the prototype
void increment(int z); // this is the prototype

int main(void) {
	int i = 10;
	increment(i);
	printf("i = %d\n", i); // should print 10
}


void hello(void) {
// This function takes no arguments and returns no value:
    printf("Hello, world!\n");
}

int plus_one(int n) { // <--- function definition
	return n + 1;
}


void increment(int a) {
	a++;
}


//int main(void) {
    //int i = 10, j;
    //
    //j = plus_one(i);  // The "call"
    //printf("i + 1 is %d\n", j);
//}

