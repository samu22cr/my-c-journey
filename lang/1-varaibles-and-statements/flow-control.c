

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void) {


	// switch statements------------------------------
	
	// CAN use char types cause they're secretely integers themselves
	char c = 'a';
	switch (c) {
		case 'a':
			printf("It's 'a'!\n");
			break;
		case 'b':
			printf("It's 'b'!\n");
			break;
		case 'c':
			printf("It's 'c'!\n");
			break;
	}

	// next code is not gonna work!!!
	//	float f = 12.1;
	//	char *chars = "dsadasdsa";
	//	switch (chars) {
	//		case "dsa":
	//			printf("it's 1");
	//			break;
	//		case "123":
	//			printf("it's 2");
	//			break;
	//		default: 
	//			printf("it is not 1 nor 2");
	//			break;
	//	}

//	int goat_count = 0;
//	printf("Enter a goat count: ");
//	scanf("%d", &goat_count);
//	switch (goat_count) {
//		case 0:
//			printf("You have no goats.\n");
//			break;
//		case 1:
//			printf("You have a singular goat.\n");
//			break;
//		case 2:
//			printf("You have a brace of goats.\n");
//			break;
//		default:
//			printf("You have a bona fide plethora of goats!\n");
//			break;
//	}
	

	// for statements------------------------------
	//for(int i = 0; i < 10; i++) {
		//printf("i = %d\n", i);
	//}

	//for-loop fun fact!
	//You can use the comma operator to do multiple things in each clause of the for loop!
	//for (int i = 0, j = 999; i < 10; i++, j--) {
	    //printf("%d, %d\n", i, j);
	//}

	// infinite for-loop
	//for(;;) {  // "forever"
	    //printf("I will print this again and again and again\n" );
	    //printf("for all eternity until the heat-death of the universe.\n");
//
	    //printf("Or until you hit CTRL-C.\n");
	//}


	// do-while statements-----------------------	
	//int r;
	//do {
		//r = rand() % 100;
		//printf("%d\n",r);
	//} while (r != 37);
	//printf("%d\n", rand());

	//int i = 10;
	//// this is not executed because i is not less than 10:
	//while(i < 10) {
	    //printf("while: i is %d\n", i);
	    //i++;
	//}
	//// Using a do-while statement:
	//i = 10;
	//// this is executed once, because the loop condition is not checked until
	//// after the body of the loop runs:
	//do {
	    //printf("do-while: i is %d\n", i);
	    //i++;
	//} while (i < 10);
	//printf("All done!\n");

	// while statements-----------------------	
	//int i = 0;
	//while(i < 10) {
		//printf("i is now %d\n", i);
		//i++;
	//}
	//printf("All done!\n");
	//while(1) {
		//printf("1 is always true, so this repeats forever.\n");
	//}
	
	// if-else statements-----------------------
	//int i = 10;
	//if (i > 10) {
	    //printf("Yes, i is greater than 10.\n");
	    //printf("And this will also print if i is greater than 10.\n");
	//}
	//if (i <= 10) printf("i is less than or equal to 10.\n");	

	//int i = 99;
	//if (i == 10)
	    //printf("i is 10!\n");
	//else {
	    //printf("i is decidedly not 10.\n");
	    //printf("Which irritates me a little, frankly.\n");
	//}
	//int i = 99;
	//if (i == 10) printf("i is 10!\n");
	//else if (i == 20)
	    //printf("i is 20!\n");
	//else if (i == 99) {
	    //printf("i is 99! My favorite\n");
	    //printf("I can't tell you how happy I am.\n");
	    //printf("Really.\n");
	//}
	//else printf("i is some crazy number I've never heard of.\n");


}


