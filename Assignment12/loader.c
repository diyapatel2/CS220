#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
/* loader.c */


int main(int argc, char *argv[]){
	/*  Declare an array large enough to hold the raw bytes. Raw bytes are best stored in byte-addressable arrays. Pick the appropriate type. Call it "raw_bytes"*/
	unsigned char *raw_bytes; 
	/*  Declare a function pointer type that matches the calc function's type. Call it  "Calc_fptr" */
	typedef int (*Calc_fptr)(char, int, int); 
	FILE *fp;

	Calc_fptr calculator;

	/* if number of arguments is not 4 (5 including program name)*/
	if(argc != 5){
		printf("Usage %s <filename> <uint> <operation> <uint>\n", argv[0]);
		exit(1);
	}
	/*  Open and read the binary file into raw_bytes. Use fopen and fread. */
	fp = fopen(argv[1], "rb");	

	/*if the file does not open, properly exit*/
	if(fp == NULL){
		printf("File is not opening\n");
		exit(1);
	}
	/*get the size of the file*/
	unsigned int size; 
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	/*allocate memory*/
	raw_bytes = (unsigned char*)malloc(size); 
	/*check for trouble allocating memory for the file */
	if(!raw_bytes){
		printf("Error allocating memory for file\n");
		exit(1); 
	}
	/*set memory, dont forget to free*/
	memset(raw_bytes, 0xc3, size*sizeof(char));
	/*make the page*/
	mprotect(raw_bytes, size,  PROT_EXEC | PROT_READ | PROT_WRITE);
	fread(raw_bytes, size, 1, fp);
	/*calculate results*/ 
	int input_one, input_three;
	 char op;
	input_one = atoi(argv[2]);
	input_three = atoi(argv[4]);
	op = *argv[3];
	calculator = (Calc_fptr) raw_bytes;
	int ret; 
	ret = calculator(op, input_one, input_three);
	fclose(fp);
	printf("%d %c %d = %d\n", input_one, op, input_three, ret);  
	free(raw_bytes);
	return 0;
}
