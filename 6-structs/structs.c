#include <stdio.h>

struct car {
	char *name;
	float price;
	int speed;
};

void set_price(struct car *c, float new_price) {
	// THE-ARROW-OPERATOR--------------------------------------------------
	// (*c).price = new_price;  // Works, but is ugly and non-idiomatic :(
	// ^^^^ The line above is 100% equivalent to the one below:
	c->price = new_price;
}


int main(void) {

	// comparing-structs----------------------------------------------------
	/*
		There's only one safe way to do it: compare each field one at a time.

		You might think you could use memcmp(), but that doesn’t handle 
		the case of the possible padding bytes that might be in there.

		If you clear the struct to zero first with memset(), then it might work,
		though there could be weird elements that might not compare as you expect.
	*/
	

	// copying-and-returning-structs----------------------------------------
	// struct car a,b;
	// a = b; // Shallow COPY of struct
	// ^^^ This is not a “deep copy”.
	//  All fields are copied as-is, including pointers to things.
	// And returning a struct (as opposed to a pointer to one) 
	// from a function also makes a similar copy to the receiving variable.
		// A deep copy follows pointers in the struct and copies the data they 
		// point to, as well. A shallow copy just copies the pointers, but not 
		// the things they point to. C doesn’t come with any built-in deep 
		// copy functionality.


	// passing-structs-to-functions----------------------------------------
	//struct car saturn = {.speed=175, .name="Saturn SL/2"};
	//// Pass a pointer to this struct car, along with a new, more realistic, price:
	//set_price(&saturn, 799.99);
	//printf("Price: %f\n", saturn.price);


	// struct-initializers-----------------------------------------------

	// Now with an initializer! Same field order as in the struct declaration:
	//struct car saturn = {
		//"Saturn SL/2",
		//16000.99,
		//175
	//};
	//struct car saturn = {
		//.speed = 175,
		//.name = "Saturn SL/2"
		//// Similar to array initializers,
		//// any missing field designators 
		//// are initialized to zero (in this
		//// case, that would be .price, which
		//// I’ve omitted).
	//};
	//printf("Name:           %s\n", saturn.name);
	//printf("Price (USD):    %f\n", saturn.price);
	//printf("Top Speed (km): %d\n", saturn.speed);

	
	// struct-declaration-----------------------------------------------
	//struct car saturn; // Variable "saturn" of type "struct car"
	//saturn.name = "Saturn SL/2";
	//saturn.price = 15999.99;
	//saturn.speed = 175;
	//printf("Name:           %s\n", saturn.name);
	//printf("Price (USD):    %f\n", saturn.price);
	//printf("Top Speed (km): %d\n", saturn.speed);
	//struct some {
		//int integer;
	//};
	//struct some thing;
	//thing.integer = 12;
	//printf("thing's integer equals %d\n", thing.integer);

}
