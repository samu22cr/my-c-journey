#include <stdio.h>
#include <stdlib.h>


void on_exit_normal(void) { printf("Normal exit -- This won't be called on quick_exit(int exit_status)\n"); }
void on_exit_1(void) { printf("Exit handler 1 called!\n"); }
void on_exit_2(void) { printf("Exit handler 2 called!\n"); }
void on_quick_exit_1(void) { printf("Quick exit handler 2 called!\n"); }
void on_quick_exit_2(void) { printf("Quick exit handler 2 called!\n"); }

int main(void) {

//	exit() -------------------------------------------------------
//	A call to atexit() with the handler function name register it.
//	You can register multiple exit handlers, and they’ll be called in 
//	the reverse order of registration.
//	atexit(on_exit_1); // called last
//	atexit(on_exit_2); // called first
//	exit(13);


//	quick_exit() -------------------------------------------------------
//	This is similar to a normal exit, except:
//		- Open files might not be flushed.
//		- Temporary files might not be removed.
//		- atexit() handlers won’t be called.
//	But there is a way to register exit handlers: call at_quick_exit() 
//	analogously to how you’d call atexit().
	//at_quick_exit(on_quick_exit_1);
	//at_quick_exit(on_quick_exit_2);
	//atexit(on_exit_normal);  // This won't be called
	//printf("About to quick exit...\n");
	//quick_exit(0);

//	_Exit() -------------------------------------------------------
//	Exists program inmediately, no on-exit callback handlers, files
//	don't get flushed && temp files don't get removed
//	_Exit(34);


//	assert() -------------------------------------------------------
//	int n = 123;
//	assert(n > 0); // if expression resolves to false program exits 
		       // with a non-user-friendly response, might be
		       // better to right some custom MACROS for this 
		       // situation


//	abort() -------------------------------------------------------
//		- won't necessarily cleanup open files || remove temp files
//		- used when something goes terribly wrong and I want to 
//		indicate the situation as much as possible to the outsie
//		environment
//	abort();
	

//	--------------------------------------------------------------
	// vv<<------ implicit return when finishing the main() func
	// return 0 || return EXIT_SUCCESS
}
