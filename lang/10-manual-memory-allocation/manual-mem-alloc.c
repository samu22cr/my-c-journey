#include <stdio.h>
#include <stdlib.h>

int main(void) {


	// realloc() ------------------------------------------

	//num_floats *= 2;
	//np = realloc(p, num_floats);  // WRONG: need bytes, not number of elements!
	//np = realloc(p, num_floats * sizeof(float));  // Better!

	// realloc with NULL***************
	//trivia time! These two lines are equivalent:
	//char *p = malloc(3490);
	//char *p = realloc(NULL, 3490);	


	// an alternative: calloc() ------------------------------------------
	// calloc() == contiguous allocation
	// this func clears memory to zero (initializes to 0 on int[])
	//int *p = calloc(10, sizeof(int));
	//free(p);

	// Again, the result below is the same for both except malloc() doesn’t zero the memory by default.
	//int *p = calloc(10, sizeof(int)); // Allocate space for 10 ints with calloc(), initialized to 0
	//// ----
	//int *q = malloc(10 * sizeof(int)); // Allocate space for 10 ints with malloc(), initialized to 0:
	//memset(q, 0, 10 * sizeof(int));   // set to 0



	// allocating space for an array------------------------------------------
	//char *p = malloc(3490); // this is an array for 3490 bytes AKA a string | since each char is 1 byte
	// ^^^<<<----there is no initialization here, it's full of gargabe
	//printf("%s\n", p);
	//int *p = malloc(sizeof(int) * 10);
	//for(int i = 0; i < 10; i++) {
		//p[i] = i * 5;
		//printf("%d\n", p[i]);
	//}
	//// always deallocate manually allocated memory
	//free(p);

	// ERROR CHECKING------------------------------------------
	//int *x;
	//x = malloc(sizeof(int) * 10);
	//if(x == NULL) {
		//printf("Error allocating 10 ints\n");
		//// do something here to handle it!
	//}
	// common pattern of doing the same as above....
	//int *x;
	//if ((x = malloc(sizeof(int) * 10)) == NULL)
	    //printf("Error allocating 10 ints\n");
	    //// do something here to handle it
	//}

	// malloc() and free()------------------------------------------
//	int *p = malloc(sizeof(int));
//	*p = 12;
//	printf("%d\n", *p);
//	free(p);
	// *p = 3490 // ERROR: undefined behavior! Use after free();
	//int *p = malloc(sizeof *p);  // *p is an int, so same as sizeof(int)


}
