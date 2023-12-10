#include <stdio.h>
#include <stddef.h>

//struct Bar { int z; };
//struct Foo { int x; int y; struct Bar bar; };
//#define MAX_PASSENGERS 8
//struct passenger {
	//char *name;
	//int covid_vaccinated; // 0 || 1
//};
//struct spaceship {
	//char *manufacturer;
	//struct passenger passenger[MAX_PASSENGERS];
//};
//
//struct foobar {
    //int a;
    //char b;
    //int c;
    //char d;
//};


#define ANTELOPE 1 // used a couple macros for demosntration purposes...
#define OCTOPUS  2 // ... but could I use ENUMS??? do enums even exist in C???
struct common {
    int type;   // <<--- common initial sequence
};
struct antelope {
    int type;   // <<--- common initial sequence
    int loudness;
};
struct octopus {
    int type;   // <<--- common initial sequence
    int sea_creature;
    float intelligence;
};
union animal {
    struct common common;
    struct antelope antelope;
    struct octopus octopus;
};

/*
	Generic function thanks to union and shared memory
	with common initial sequences of fields
*/
void print_animal(union animal *x)
{
    switch (x->common.type) {
        case ANTELOPE:
            printf("Antelope: loudness=%d\n", x->antelope.loudness);
            break;
        case OCTOPUS:
            printf("Octopus : sea_creature=%d\n", x->octopus.sea_creature);
            printf("          intelligence=%f\n", x->octopus.intelligence);
            break;
        default:
            printf("Unknown animal type\n");
    }
}


int main(void) {


	// UNIONS------------------------------------------------------------
	//union foo {
		//int a;
		//char c;
	//};
	//union foo f;
	//f.a = 52;
	//f.c = 'A';
	//printf("%d\n", f.a);
	//printf("%c\n", f.c);

	//union foo {
		//float b;
		//short a;
	//};
	//union foo x;
	//x.b = 3.14159;
	//printf("%f\n", x.b);  // 3.14159, fair enough
	//printf("%d\n", x.a);  // But what about thison foo {

	//union foo {
	    //int a, b, c, d, e, f;
	    //float g, h;
	    //char i, j, k, l;
	//};
	//union foo x;
	//int *foo_int_p = (int *)&x;
	//float *foo_float_p = (float *)&x;
	//x.a = 12;
	//printf("%d\n", x.a);           // 12
	//printf("%d\n", *foo_int_p);    // 12, again
	//x.g = 3.141592;
	//printf("%f\n", x.g);           // 3.141592
	//printf("%f\n", *foo_float_p);  // 3.141592, again


	// Common initial sequences on struct unions________________
	// this feature lets have shared info between structs
	//struct a {
	    //int x;     //
	    //float y;   // Common initial sequence
	     //
	    //char *p;
	//};
	//struct b {
	    //int x;     //
	    //float y;   // Common initial sequence
            //
	    //double *p;
	    //short z;
	//};
	//union foo {
		//struct a sa;
		//struct b sb;
	//};
	//union foo f;
	// ^^^^^^^^^^^^^^^^^^^^
	//f.sa.x is the same as f.sb.x.
		     //and
	//f.sa.y is the same as f.sb.y.
//	^^^^^<<<-----   //Also, the names of the members in the common 
			//initial sequence don’t matter—all that matters 
			//is that the types are the same.

	// COMMON INITIAL SEQUENCES DEMOSNTRATION++++++
	//union animal a = {
		//.antelope.type=ANTELOPE,
		//.antelope.loudness=12
	//};
	//union animal b = {
		//.octopus.type=OCTOPUS, 
		//.octopus.sea_creature=1,
		//.octopus.intelligence=12.8
	//};
	//print_animal(&a);
	//print_animal(&b);
	// +++++++

	// UNIONS + UNNAMED STRUCTS_________________
	//union foo {
	    //struct {       // unnamed!
		//int x, y;
	    //} a;
//
	    //struct {       // unnamed!
		//int z, w;
	    //} b;
	//};
	//union foo f;
	//f.a.x = 1;
	//f.a.y = 2;
	//f.b.z = 3;
	//f.b.w = 4;






	// BIT-FIELDS------------------------------------------------------------
	//_____________________________________
	// this feature is more used in low-level programming, 
	// like hardware level stuff or when absolute performance is 
	// needed
	//struct foo { 	
		//unsigned int a:5; // TRADEOFF: 5 bit field can only hold values 0-31
		//unsigned int b:5;
		//unsigned int c:3; // TRADEOFF: 3 bit fields can only hold values  0-7
		//unsigned int d:3;
		//// field name + : + n
		//// this syntax tell C to allocate only n number of	
		//// BITS for that field
	//};
	//struct foo f = { .a=31 };
	//printf("a = %d\n", f.a);
	//printf("b = %d\n", f.b);
	//printf("c = %d\n", f.c);
	//printf("d = %d\n", f.d);
	//_____________________________________
	// A gotcha: C will only combine adjacent bit-fields
	// If they’re interrupted by non-bit-fields, you get no savings:
	// MIGHT NOT BE WHAT I WANT 
	//struct f {
		//unsigned int a:1; 	// sizeof(strict foo) == 16 bytes (for me)
		//unsigned int b;		// since a is not adjacent to c.
		//unsigned int c:1;
		//unsigned int d;
	//}
	//// NEARER TO WHAT I PROBABLY WANT
	//struct f {
		//unsigned int a:1; 	// sizeof(strict foo) == 12 bytes (for me)
		//unsigned int c:1;	// since .a & .c are adjacent
		//unsigned int b;
		//unsigned int d;
	//}
	//_____________________________________
	// SIGNED || UNSIGNED int's
	// If you just declare a bit-field to be int,
 	// the different compilers will treat it as signed or unsigned.
	// Just like the situation with char.
	// Be specific about the signedness when using bit-fields.	
	//_____________________________________

	// UNNAMED BIT-FIELDS
	// In some specific circumstances, you might need 
	// to reserve some bits for hardware reasons, but not need to use them in code.
	//struct foo {	
		//unsigned char a:2;
		//unsigned char :5; // <-- unnamed bit-field!
		//unsigned char b:1;
	//}
	//_____________________________________
	// Zero-Width Unnamed bit-fields
	//struct foo {
	    //unsigned int a:1;
	    //unsigned int b:2;
	    //unsigned int :0;// <-- indicated new packing of bits, meaning that
	    //unsigned int c:3;//    a & b are packed in one unsigned int and 
	    //unsigned int d:4;//    c & d in another unsigned int
	//};

	// fake-OOP------------------------------------------------------------
	//struct parent {
	    //int a, b;
	//};
	//struct child {
	    //struct parent super;  // MUST be first
	    //int c, d;
	//};
	// a pointer to a struct has the same value as a
	// pointer to the first field in that struct.
	// -------------------->>>>>>>>>>vvvvvvvvvvvvvvvvvv
	//struct child c = { .super={ .a=1, .b=2 }, .c=3, .d=4 };
	//printf("%p\n", (void *)&c); // same output as below
	//printf("%p\n", (void *)&c.super); // same outout as above
	//struct Bar b = { .z=12 };
	//printf("%p\n", (void *)&b); 
	//printf("%p\n", (void *)&b.z); 

	// offsetof------------------------------------------------------------
	//printf("%zu\n", offsetof(struct foobar, a));
	//printf("%zu\n", offsetof(struct foobar, b));
	//printf("%zu\n", offsetof(struct foobar, c));
	//printf("%zu\n", offsetof(struct foobar, d));


	/// padding-bytes--------------------------------------------------------
	//printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
	//printf("%zu\n", sizeof(struct foobar));
	// flexible-array-members--------------------------------------------------------
	// ...
	// self-referential-structs-------------------------------------------------------
	//struct node {
		//int data;
		//struct node *next;
	//};

	// anonymous-structs--------------------------------------------------------
	//struct animal { char *name; int leg_count, speed; }
	//// below in above's^^ anonymous equivalent
	//struct { char *name; int leg_count, speed; }

	// this belows feels too JS 
	//struct { 
		//char *name;
		 //int leg_count, speed;
	//} a, b, c; // <-- 3 variables with type of this struct
	//a.name = "antelope";
	//a.leg_count = 4;
	//________

	//typedef struct {
		//char *name;
		//int leg_count, speed;
	//} animal;
	//animal a, b, c;
	//a.name = "antelope";
	//a.leg_count = 4;

	// initializing-nested-structs-and-arrays----------------------------------------
	//struct spaceship s = {
		//.manufacturer="General Products",
		//.passenger = {
			//// initialize a filefe at a time
			//[0].name = "Elvis Morry",
			//[0].covid_vaccinated = 0,
			//// or all at once
			//[7] = {
				//.name="Xinnia Martinez",
				//.covid_vaccinated=1
			//}
		//}
	//};
	//printf("Passengers for %s ship:\n", s.manufacturer);
	//for( int i = 0; i < MAX_PASSENGERS; i++) {
		//if(s.passenger[i].name != NULL) {
			//printf("	%s (%svaccinated)\n",
			//s.passenger[i].name,
			//s.passenger[i].covid_vaccinated ? "" : "not ");
		//}
	//}
	//struct Foo foo = { .x=0, .y=0 };
	//struct Foo foo = {	
		//.x=123,
		//.y=456,
		//.bar.z = 798,
	//};
	// below definition same as the one above
	//struct Foo foo = {	
		//.x=123,
		//.y=456,
		//.bar={ 
			//.z=789
		//}
	//};
	//printf("foo= x: %d, y: %d, x: %d\n", foo.x, foo.y, foo.bar.z);
}
