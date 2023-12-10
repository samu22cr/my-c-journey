#include <stdio.h>
#include <threads.h>



int main(void) {

	//char t = '\'';
	//printf("Use \\n for newline\n");  // Use \n for newline
	//printf("Say \"hello\"!\n");       // Say "hello"!
	//printf("%c\n", '\'');             // '
	//printf("\a");




	//for(int i = 10; i >= 0; i--) {
		////printf("\rT minus %d second%s... \b", i, i == 1? "" : "s");
		//printf("\rT minus %d second%s... \b", i, i == 1? "" : "s");
		//fflush(stdout); // force output to update
		//// sleep for 1 sec
		//thrd_sleep(&(struct timespec){.tv_sec=1}, NULL);
	//}
	//printf("\rLiftoff!			\n");
	
	// Bullet character__________
	// Embedding UTF-8 bytes:
	//printf("\xE2\x80\xA2 Bullet 1\n");
	//printf("\xE2\x80\xA2 Bullet 2\n");
	//printf("\xE2\x80\xA2 Bullet 3\n");

	// Unicode(16-bit) [must have 4 digits, so padd strng with necessary leading 0s always]
	//printf("\u2022 Bullet 1\n");
	//printf("\u2022 Bullet 2\n");
	//printf("\u2022 Bullet 3\n");

	// Unicode(32-bit) [must have 8 digits, so padd strng with necessary leading 0s always]
	printf("\U00002022 Bullet 1\n");
}
