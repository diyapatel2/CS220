#include "file_recognizer.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
	int file;
	/*if the number of arguments when running the program is not 2 then print invalid input*/
	if(argc != 2)
	{
		printf("Invalid input.\n");
		exit(1);
	
	}

	/*calling helper funciton*/
	file = getFile((char *)argv[1]);
	/*switch statement between all file types*/
	switch(file)
	{
		
		case -2:
		printf("Invalid input. \n");
		break;
		
		case -1:
		printf("File type unknown. \n");
		break;

		case 0: 
		case 1:
		printf("This is an GIF file. \n");
		break;

		case 2: 
		printf("This is an Elf file. \n");
		break;

		case 3:
		printf("This is a PDF file. \n");
		break;
		
		case 4:
		printf("This is a ZIP file. \n");
		break;

		case 5:
		printf("This is a Java class file. \n");

		case 6:
		printf("This is a PNG file. \n");
		break;

		default:
		printf("File type unknown. \n");
		break;
	
	}

  return file;
}
int getFile(char *file_input){
	FILE *fin;
	unsigned char input_size[10];
	int i, j, found, ret = -1; 
	int res; 
	/*PROVIDING SIGNATURES FOR EACH RESPECTIVE FILE TYPE*/
	const unsigned char FILE_SIGNATURE[7][9] ={
		{0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x0}, /*Type for GIF Image*/
		{0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x0}, /*Type for GIF Image*/
		{0x7F, 0x45, 0x4C, 0x46, 0x0}, /*Type for ELF File*/
		{0x25, 0x50, 0x44, 0x46, 0x0}, /*Type for PDF File*/
		{0X50, 0x4B, 0x0}, /*Type for ZIP File*/
		{0xCA, 0xFE, 0xBA, 0xBE, 0x0}, /*Type for JAVA Class File*/
		{0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0X0A, 0x0} /*Type for PNG File*/

	};
	/*open file*/
	fin = fopen(file_input, "r");
	/*File unable to open */
	if(!fin){
		return -2; 
	}
	/*Inputing characters from file into the array */
	
	if(fin != NULL){
		res = fread(input_size, 1, 10,fin);
	
	}
	/*iterate through array to find header match */
	for(i = 0; i < sizeof(FILE_SIGNATURE); i++){
		found = 1; 
		for(j = 0; FILE_SIGNATURE[i][j] != 0x0; j++){
			if(input_size[j] != FILE_SIGNATURE[i][j]){
				found = 0; 
				break;
			}
		
		}

		if(found)
		{
			ret = i;
			break;
		}

	}
	/*closing the file*/
	fclose(fin);
	return ret;
}
