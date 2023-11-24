#include <stdio.h> 

#define COUNT 5


// prototypes
void foo(int x[12]);

void times2(int *arr, int len);
void times3(int arr[], int len);
void times4(int arr[5], int len);
void double_array(int *a, int len);
void print_2D_array(int a[2][3]);


// ARRAYS
int main(void) { 

	// Arrays and Pointers------------------------------------------------

	//passing multidimensional-arrays to functions
	//int a[2][3] = 
	//{
		//{0, 1, 0},
		//{0, 1, 0}
	//};
	//print_2D_array(a);

	//void print_2D_array(int a[2][3])
	//void print_2D_array(int a[][3])
	// ^^^^ this 2 are equivalent, since C needs 
	// to know all the dimensions (except the first 
	// one) so it has enough information to know 
	// where in memory to look to find a value.


	//changing arrays in functions
	//int x[5] =  { 1, 2, 3, 4, 5 };
	//double_array(x, 5);
	//for(int i = 0; i < 5; i++) {
		//printf("%d\n", x[i]);
	//}
	

	//passing arrays to functions
	//int x[5] = { 11, 22, 33, 44, 55 };
	//times2(x, 5);
	//printf("-------\n");
	//times3(x, 5);
	//printf("-------\n");
	//times4(x, 5);
	

	// getting the pointer to the first element of an array
	//int a[] = { 112, 2, 3, 4, 5 };
	//int *p = NULL;
	//p = &a[0];
	//printf("%d\n", *p); // prints "112"
	// this is so common to do in C that the language allows us a shorthand:
	//p = &a[0];  // p points to the array
	// is the same as:
	//p = a;      // p points to the array, but much nicer-looking!
	//printf("%d\n", *p); // prints "112"
	//printf("%p\n", p); // prints the address of the first element of a[]


	// multidimensional arrays / matrix--------------------------------------------
	//int row, col;
	//int a[3][9] = // initialize 3D array
	//{
		//{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		//{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		//{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
	//};
	//for (row = 0; row < 3; row++) {
		//for(col = 0; col < 9; col++) {
			//printf("(%d,%d) = %d\n", row, col, a[row][col]);
		//}
	//}

	//initialize matrix with explicit indices
	//int a[3][3] = 
	//{
		//[0][0]=1,
		//[1][1]=1,
		//[2][2]=1
	//};
	//for(int row = 0; row < 3; row++) {
		//for(int col = 0; col < 3; col++) {
			//printf("%d ", a[row][col]);
		//}
		//printf("\n");
	//}
	

	// out of bounds------------------------------------------------
	// This is called UNDEFINED BEHAVIOR and should be avoided
	//int i;
	//int a[5] = {22, 37, 3490, 18, 95};
	//for (i = 0; i < 10; i++) {  // BAD NEWS: printing too many elements!
		//printf("%d\n", a[i]);
	//}


	// array initializers------------------------------------------------

	// can let compiler compute size of the array 
	// from the initializer,just by leaving the 
	// size off the array variable declaration
	//int a[3] = {22, 37, 3490};
	//// is the same as:
	//int a[] = {22, 37, 3490};  // Left the size off!

	// can put simple constant expressions in initializers
	//int a[COUNT] = { [COUNT - 3]=3, 2, 1 };

	// below we use "[]" to initialize specific indices
	//int a[20] = {0, 1, 2, [10]=55, [15]=-2312, 3 };
	//// ^^^^ rest that's not specified is initialized 
	//// 	as 0s
	//for(int i = 0; i < 20; i++) {
		//printf("%d\n", a[i]);
	//}

	//int a[100] = {0}; // all 0s
	//int a[100] = {1}; // index 0 = 1 and rest are 0s
	//for(int i = 0; i < 100; i++) {
		//printf("%d\n", a[i]);
	//}
	

	//int a[5] = {22, 37, 3490};
	//// is the same as:
	//int a[5] = {22, 37, 3490, 0, 0};

	//Catch: initializer values must be constant terms. Can’t throw variables in there.
	//int i;
	//int arr[5] = { 1, 2, 3, 4, 5 }; // initialize with this values
	//for( i = 0; i < 5; i++) {
		//printf("%d\n", arr[i]);
	//}

	// length of an array------------------------------------------------
	//size_t z = sizeof(double [48]);
	//printf("%zu\n", z);

	// only works in same scope the array was defined:
	//int x[12];  // 12 ints
	//printf("%zu\n", sizeof x);     // 48 total bytes
	//printf("%zu\n", sizeof(int));  // 4 bytes per int
	//printf("%zu\n", sizeof x / sizeof(int));  // 48/4 = 12 ints!

	// basic-example-----------------------------------------------------
	//int i;
	//float f[4];  // Declare an array of 4 floats
	//f[0] = 3.14159;  // Indexing starts at 0, of course.
	//f[1] = 1.41421;
	//f[2] = 1.61803;
	//f[3] = 2.71828;
	//for(i = 0; i < 4; i++) {
		//printf("%f\n", f[i]);
	//}

}



void times2(int *arr, int len) {
	for(int i = 0; i < len; i++) {
		printf("%d\n", arr[i] * 2);
	}
}

void times3(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		printf("%d\n", arr[i] * 3);
	}
}

void times4(int arr[5], int len) {
	for(int i = 0; i < len; i++) {
		printf("%d\n", arr[i] * 4);
	}
}

void double_array(int *a, int len) {
	// Multiply each element by 2
	//
	// This doubles the values in x[] in main() since x[] and a[] both point
	// to the same array in memory!
	for(int i = 0; i < len; i++) {
		a[i] *= 2;
	}
}


void print_2D_array(int a[2][3]) {
	for(int row = 0; row < 2; row++) {
		for(int col = 0; col < 3; col++) {
			printf("%d ", a[row][col]);
		}
		printf("\n");
	}
}





