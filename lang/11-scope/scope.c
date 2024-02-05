

void main123(void) {

	// FOR-LOOP SCOPE---------------------------------------------------

	//for(int i = 0; i < 10; i++) {
	    //printf("%d\n", i);
	//}
	//printf("%d\n", i);  // ILLEGAL--i is only in scope for the for-loop


	//If the loop body is enclosed in a block, the variables defined in the for-loop are visible from that inner scope.
	//Unless, of course, that inner scope hides them. This crazy example prints 999 five times:
	//for (int i = 0; i < 5; i++) {
		//int i = 999;  // Hides the i in the for-loop scope
		//printf("%d\n", i);
	//}
	 


	
	// BLOCK SCOPE------------------------------------------------------
	//int i = 10; // here i's value is 10
	//{
		//// variables here hide from the outer scope
		//int i = 20; // here i's value is 20
	//}
	//// here i's value is 10
}


// FILE SCOPE------------------------------------------------
//int shared = 10;    // File scope! Visible to the whole file after this!
//void func1(void) { shared += 100; } // Now shared holds 110 
//void func2(void) { printf("%d\n", shared); } // Prints "110" 
//int main(void) { func1(); func2(); }

// ^^^^^^^^^^^^^^<<<<<<<<<<<<---------------------vvvvvvvvvvvv
// note that if shared were declared at the bottom of the file,
// it wouldn’t compile. It has to be declared before any functions use it.
