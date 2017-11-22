#include <stdio.h>
#include "intarr.h"
#include <stdlib.h>
#include <string.h>



/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ){
	//assert that ia points to an intarr and has an array of data
	if (ia==NULL){
		printf("NULL array");
		return 1;
	}
	if(ia->data==NULL){
		printf("NULL data");
		return 1;
	}

	//open filename

	FILE * f = fopen( filename, "w");
	//check to see if file opened for writing
	//if (f ==NULL){
		//printf("Failed to open image");
		//return 0;
	//}

	//array of length 0 -> output file of an empty array
	if(ia->len==0){
		fclose(f);
		return 0;
	}
	
	
	//write into filename using pointers to len and data of ia
	//return 2 if it fails
	//len first because its size 1
	if( fwrite(&(ia->len), sizeof(int), 1, f) !=1){
		printf("failed to write len into filename");
		return 2;
	}
	//return 3 if it fails. 
	if( fwrite(ia->data, sizeof(int), ia->len, f) !=(ia->len)){
		printf("failed to copy array into filename");
		return 3;
	}
	fclose(f);
	return 0;
	
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ){

	//open filename for reading
	FILE * f= fopen(filename, "r");
	if(f==NULL){
		printf("failed to open file");
		return NULL;
	}
	//create new allocated intarr_t

	intarr_t * catBus = malloc(sizeof(intarr_t));
	//find length of array
	//fread() copies length bytes onto destination
	fread(&(catBus->len), sizeof(int), 1, f);
	
	//allocate space for array
	catBus->data= malloc((catBus->len)*sizeof(int));

	//copy data from f onto array
	int x=0;
	for(x=0; x<(catBus->len); x++){	
		fread(&(catBus->data[x]), sizeof(int), 1, f);
		
	}
	fclose(f);
	return catBus;
}
