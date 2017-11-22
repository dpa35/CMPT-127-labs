#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ){
	//JSON- Javascript object notation
	//print things in a human-readable manner
	//i.e "index 0 = ..."
	//i.e "index 1 = ..."
	if(ia==NULL){
		printf("array null");
		return 1;
	}
	if(ia->data==NULL){
		printf("null data");
		return 1;
	}
	FILE * f = fopen( filename, "w");
	if(f==NULL){
		printf("failed file opening");
		return 1;
	}
	//desired output [ a, b,... z]
	
	fprintf(f, "[");
	int x=0;
	//if len = 0, prints empty array
	//missing comma?
	if((ia->len)>0){
		for(x=0;x<ia->len;x++){
			if(x==(ia->len-1)){
				fprintf(f, "%i", ia->data[x]);
			}
			else{
				fprintf(f, "%i, ", ia->data[x]);
			}
		}
	}
	fprintf(f, "]");
	fclose(f);
	return 0;
	
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename ){
	//must convert from char to int
	//create an index	
	if(filename==NULL){
		printf("file error\n");
		return NULL;
	}


}
