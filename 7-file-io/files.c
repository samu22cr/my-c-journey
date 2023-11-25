#include <stdio.h>

int main(void) {

	// structs-and-numbers-caveats--------------------------------------------------
	// caveats = "advertencias"

	// binary-file-I/O--------------------------------------------------
	
	// read binary!
	//FILE *fp;
	//unsigned char c;
	//fp = fopen("output.bin", "rb"); // rb mode for "read binary"
	//while(fread(&c, sizeof(char), 1, fp) > 0) { // fread returns 0 on EOF
		//printf("%d\n", c);
	//}

	// write binary!
	//FILE *fp;
	//unsigned char bytes[6] = { 7, 37, 0, 88, 255, 12 };
	//fp = fopen("output.bin", "wb"); // wb mode for "write binary"
	//// In the call to fwrite, the arguments are:
	//// * Pointer to data to write
	//// * Size of each "piece" of data
	//// * Count of each "piece" of data
	//// * FILE*
	//fwrite(bytes, sizeof(char), 6, fp);
	//fclose(fp);





	// writting-text-files----------------------------------------------

	//FILE *fp;
	//int x = 32;
	//fp = fopen("output.txt", "w"); // "w" ovewrites whole file
	////fp = stdout ; // stdout is just a file (stream)
	////fp = stderr ; // stderr is just a file (stream)
	//fputc('B', fp);
	//fputc('\n', fp); // just a simple newline char
	//fprintf(fp, "x = %d\n",x);
	//fputs("Hello, world!\n", fp);
	//fclose(fp);


	// formatted-input--------------------------------------------------
	//FILE *fp;
	//char name[1024]; // Big enough for any line this program will encounter
	//float length;
	//int tonnes;
	//int counter = 0;
	//fp = fopen("whales.txt", "r");
	//while(fscanf(fp, "%s    %f %d	", name, &length, &tonnes) != EOF) {
		//printf("WHALE #%d: name=\"%s\", length=%.1f meters, mass=%d tonnes\n", ++counter, name, length, tonnes);
	//}
	//fclose(fp);

	// fscanf() return EOF on end-of-file

	// reading-a-LINE-at-a-time-----------------------------------------
	//FILE *fp;
	//char s[1024];
	//int linecount = 0;
	//fp =  fopen("quote.txt", "r");
	//while(fgets(s, sizeof s, fp) != NULL) {
		//printf("%d: %s", ++linecount, s);
	//}
	//fclose(fp);
	


	// EOF(End of File)-------------------------------------------------
	
	// There is a special character defined as a macro: EOF.
	// This is what fgetc() will return when the end of the
	// file has been reached and you’ve attempted to read another character. 
	//FILE *fp;
	//int c;
	//fp = fopen("hello.txt", "r");
	//while( (c = fgetc(fp)) != EOF) { printf("%c", c); } 
	//fclose(fp);
	

	// reading-text-files----------------------------------------------

	//FILE *fp;
	//fp =  fopen("hello.txt", "r"); // fopen() returns NULL if something goes wrong
	//int c = fgetc(fp);
	//printf("%c\n", c);
	//fclose(fp);

	// the FILE* data type----------------------------------------------

	

}
