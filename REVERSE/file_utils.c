#include "file_utils.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int read_file( char* filename, char** buffer){

	char ch;
	FILE *in;
	in = fopen(filename, "r");
	if(in == NULL){
		fprintf(stderr, "File could not be opened\n");
		return 0;
	}
	

	//find out size of file
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	//printf("Size of input file: %d\n", size);
	
	//allocating memory for the new array
	*buffer = (char*) malloc(size * sizeof(char));
	

	fread(*buffer,size,1,in);
	if(!buffer){
		fprintf(stderr, "The memory was not allocated for the input array");
	}
	fclose(in);
	return size;
}

int write_file( char* filename, char* buffer, int size){

	char* ch;
	FILE *out;
	if(out == NULL){
		fprintf(stderr, "The output file was unable to be accessed");
	}
	out = fopen(filename, "w");


	fwrite(buffer, size, 1, out);
	
	fclose(out);	
	return size;

}
