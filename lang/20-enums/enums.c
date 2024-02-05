#include <stdio.h>

int main(void) {
	
	//enum {
		//ONE=1,
		//TWO=2
	//};
	//printf("%d %d\n", ONE, TWO);

	// enums are automatically numbered unless overriden
	//enum {
	    //SHEEP,  // Value is 0
	    //WHEAT,  // Value is 1
	    //WOOD,   // Value is 2
	    //BRICK,  // Value is 3
	    //ORE     // Value is 4
	//};
	//printf("%d %d\n", SHEEP, BRICK);  // 0 3

	//enum {
	  //X=2,
	  //Y=18,
	  //Z=-2
	//};
	
	// duplicated values are not a problem
	//enum {
	  //X=2,
	  //Y=2,
	  //Z=2
	//};


	// if values are omitted, numbering continues counting 
	// in the positive direction from whichever value was last specified. For example:
	//enum {
	  //A,    // 0, default starting value
	  //B,    // 1
	  //C=4,  // 4, manually set
	  //D,    // 5
	  //E,    // 6
	  //F=3   // 3, manually set
	  //G,    // 4
	  //H     // 5
	//}


	//enum {
	  //X=2,
	  //Y=18,
	  //Z=-2,   // <-- Trailing commas are perfectly fine
	//}

	// Named enum, type is "enum resource"
	//enum resource {
	    //SHEEP,
	    //WHEAT,
	    //WOOD,
	    //BRICK,
	    //ORE
	//};
	//// Declare a variable "r" of type "enum resource"
	//enum resource r = BRICK;
	//if (r == BRICK) {
	    //printf("I'll trade you a brick for two sheep.\n");
	//}

	// typedef'ing enums....
	//typedef enum {
	    //SHEEP,
	    //WHEAT,
	    //WOOD,
	    //BRICK,
	    //ORE
	//} RESOURCE;
	//RESOURCE r = BRICK;

	// Declare an enum and some initialized variables of that type:
	//enum {
	    //SHEEP,
	    //WHEAT,
	    //WOOD,
	    //BRICK,
	    //ORE
	//} r = BRICK, s = WOOD;

	// Declare an enum and some initialized variables of that type:
	//enum resource {   // <-- type is now "enum resource"
	    //SHEEP,
	    //WHEAT,
	    //WOOD,
	    //BRICK,
	    //ORE
	//} r = BRICK, s = WOOD;
//
//}












