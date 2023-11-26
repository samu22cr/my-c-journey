#include <stdio.h>


int main(void) {

	
	//arrays-and-typdef-----------------------------------
	typedef int five_ints[5];
	five_ints = {11, 22, 33, 44, 55};


	//practice------------------------------------------

	//typdef and capitalization!!!!!!!!!!!!!!!!!!!!!!!
	//struct {
	    //int x, y;
	//} my_point;          // lower snake case
	//typedef struct {
	    //int x, y;
	//} MyPoint;          // CamelCase
	//typedef struct {
	    //int x, y;
	//} Mypoint;          // Leading uppercase
	//typedef struct {
	    //int x, y;
	//} MY_POINT;          // UPPER SNAKE CASE



	// struct-and-pointers!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//typedef int *intptr;
	//int a  = 10;
	//intptr x = &a; // intptr is type int*


	//typedef and other types!!!!!!!!!!!!!!!!!!!!!!!!!!
	//typedef float app_float;
	////and
	//app_float f1, f2, f3;
	//THEN CHANGING IT IN WHOLE APP IS EASIER THAN CHANGING ALL DECLARATIONS OF FLOAT VARIABLES
	//^^^^^^  voila!
	//      |---------|
	//typedef long double app_float;
	//// and no need to change this line:
	//app_float f1, f2, f3;  // Now these are all long doubles




	//  Anonymous struct! It has no name!!!!!!!!!!!!!!!!!!!!!!!
	//         |
	//         v
	//      |----|
	//typedef struct {
	    //char *name;
	    //int leg_count, speed;
	//} animal;    // <-- new name
	////struct animal y;  // ERROR: this no longer works--no such struct!
	//animal z;           // This works because "animal" is an alias



	// same delcaration on typedef-and-struct!!!!!!!!!!
	// original name
	//	     |
	//	     v
	//      |------------|
	//typedef struct animal {
		//char* name;
		//int leg_count, speed;
	//} animal; 	// <--- NEW NAME
	//struct animal y; // this works;
	//animal z; // this also works since "animal" is an alias of "struct animal"



	//// separated declaration of typedef-and-struct!!!!!!!!!!!!!
	//struct animal = {
		//char* name;
		//int leg_count, speed;
	//};
	////    original name    new name
	////	   |		   |	
	////	   |		   |	
	////	   v		   v
	//typedef struct animal   animal
	//struct animal y; // this works
	//animal z; // this also works since "animal" is an alias of "struct animal"




	// typedef-theory------------------------------------------
	// they are type aliases
	//typedef int antelope;
	//typedef int antelope, bagel, mushroom;  // These are all "int"
	//antelope x = 10;
}




