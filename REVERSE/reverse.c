#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

	FILE *inputF, *outputF;
	char* in;
	char* out;
	char* inArr;
	char* outArr;
	int size;

	if(argc < 3){
//	printf("There are not enough arguments.");
	return 1;
	}

//	//Stores command line arguments as Char* (Strings)
	in = argv[1];
//	printf("Input file: %s\n", in);
	out = argv[2];
//	printf("Output file: %s\n", out);	
	
	
	size = read_file( in, &inArr);
//	printf("Size of input file: %d\n", size);
	
	outArr = malloc(size);

//	This is what I was working on (counting up)	
/*	int i;
	int tempSize = size;
	for(i=0; i<tempSize; i++){
		outArr[i] = inArr[tempSize-1];
//		printf("%c\n", outArr[i]);
		tempSize--;
	}
	*/

//	I got the idea to count down from Mazen
//
	for(int i = size-1; i>=0;i--){
	outArr[size-i] = inArr[i];
	}


	write_file( out,outArr , size);

return 0;
}
