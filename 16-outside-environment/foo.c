#include <stdio.h>
#include <stdlib.h>

//#include <unistd.h>


// COMMAND LINE ARGUMENTS---------------------------------------------
//int main(int argc, char *argv[]) {
//
	//////for(int i = 0; i < argc; i++) {
		//////printf("arg %d: %s\n", i, argv[i]);
	//////}
//
	//int total = 0;
	//for(int i = 1; i < argc; i++) {
		//int value = atoi(argv[i]);
		//total += value;
	//}
	//printf("%d\n", total);
//}
//int main(int argc, char **argv) {
	//int total = 0;
	//for(char **p = argv + 1; *p != NULL; p++) {
		//int value = atoi(*p);
		//total += value;	
	//}
	//printf("%d\n", total);
//}


// EXIT STATUS --------------------------------------------------------
//int main(int argc, char **argv) {
    //if (argc != 3) {
        //printf("usage: mult x y\n");
        //return EXIT_FAILURE;   // Indicate to shell that it didn't work
    //}
    //printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
    //return 0;  // same as EXIT_SUCCESS, everything was good.
//}



// Environment Variables-----------------------------------------------------------

//extern char **environ; // MUST be extern AND named "environ"
// NON-PORTABLE WAY TO ACCESS env vars^^^^^


//int main(void) {
//
	//// getenv() is the most STANDARD compliant way to access env vars
	// ^^^ MOST PORTABLE WAY TO GET ENV VARS
	//// Getting them______
	////char *val = getenv("FROTZ");  // Try to get the value
	////// Check to make sure it exists
	////if (val == NULL) {
		////printf("Cannot find the FROTZ environment variable\n");
		////return EXIT_FAILURE;
	////}
	////printf("Value: %s\n", val);
	//// Setting them______
	//// Unix-like OSs
		////putenv();
		////setenv();
		////unsetenv();
	//// Windows
		////_putenv();
//
//
	//// UNIX-like alternative environment variables
	//// NON-PORTABLE WAY TO ACCESS env vars^^^^^
	////for(char **p = environ; *p != NULL; p++) {
		////printf("%s\n", *p);
	////}
	//// or u could iterate over them with array notation
	////for(int i = 0; environ[i] != NULL; i++) {
		////printf("%s\n", environ[i]);
	////}
//
//}

//// Another NON-STANDARD way to access env vars in Unix-land______
//int main(int argc, char **argv, char **env) { // <-- env!  
//// NON-PORTABLE WAY TO ACCESS env vars^^^^^
    //for (char **p = env; *p != NULL; p++) {
        //printf("%s\n", *p);
    //}
//
//}
//





