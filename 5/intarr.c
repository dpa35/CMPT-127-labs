//DO NOT add a main() function- server's test will not link file
//make sure that each function name matches exactly the header function name


#include <stdio.h>
#include <stdlib.h>



// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ){
	//code here
	//allocate space for intarr_t
	intarr_t* intarrA = malloc(sizeof(intarr_t));
	//allocate space for data in intarr_t
	intarrA -> data= malloc((len)*sizeof(unsigned int));
	if(intarrA==NULL){
		return NULL;
	}
	return intarrA;
	
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
	if(ia==NULL || ia-> data==NULL){
		return;
	}
	free(ia);
}
