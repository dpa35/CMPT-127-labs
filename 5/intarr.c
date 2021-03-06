//DO NOT add a main() function- server's test will not link file
//make sure that each function name matches exactly the header function name


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"


//task 1

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.

intarr_t* intarr_create( unsigned int len ){
	//code here
	//intarr_t holds data and an int for length
	//allocate space for intarr_t
	intarr_t* intarrA = malloc(sizeof(intarr_t));
	//allocate space for data in intarr_t
	intarrA -> data= malloc((len)*sizeof(unsigned int));
	//unsuccessful memory allocation
	if(intarrA==0){
		return NULL;
	}
	//assign len to len 
	intarrA -> len = len;
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

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val ){

	if (ia==NULL){
		return INTARR_BADARRAY;
	}
	//check if index is out of range, if so return badarray
	if(index < 0 || index > ((ia->len)-1)){
		return INTARR_BADINDEX;
		
	}
	//index should be in range now
	
	ia->data[index]= val;
	return INTARR_OK;

}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i ){
	if(ia ==0){
		return INTARR_BADARRAY;
	}
	if(index<0 || index> ((ia->len)-1) || i==NULL){
		return INTARR_BADINDEX;
	}
	*i = ia->data[index];
		return INTARR_OK;
	
		
	

	
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia ){
	if (ia==0){
		return NULL;
	}
	//create new struct
	intarr_t* copycat= malloc(sizeof(intarr_t));
	//shallow copy
	*copycat = *ia;
	//allocate new data array to perform deep copy
	copycat->data= malloc(ia->len*sizeof(unsigned int));
	//copy data from original array to copy
	memcpy(copycat->data, ia->data, (copycat->len)*sizeof(int));
	if(copycat==NULL){
		return NULL;
	}
	return copycat;


}
/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){
	if(ia==0){
		return INTARR_BADARRAY;
	}
	//based off selection sort, well i guess it is selection sort.
	int x=0;
	int y=0;
	int testvalue=0;
	for(x=1;x<ia->len;x++){
		y=x-1;
		testvalue = ia->data[x];
		while(y>=0 && testvalue<(ia->data[y])){
			ia->data[y+1]=ia->data[y];
			y--;
		}
		ia->data[y+1]=testvalue;
		
	}
	return INTARR_OK;

}

/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
	if(ia==0){
		return INTARR_BADARRAY;
	}
	int x=0;
	for(x=0; x<(ia->len);x++){
		if(ia->data[x]==target && !(i==NULL)){
			*i = x;
			//printf("found\n");
			return INTARR_OK;
			
		}
	}
	return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ){
	if(ia==0){
		return INTARR_BADARRAY;
	}
	//increase len value in len to 1 to hold new val
	//printf("%d\n", ia->len);
	//ia->len+=1;
	//printf("%d\n", ia->len);
	//create a new array to insert into data (same data + val)
	int* temp= malloc(((ia->len)+1)* sizeof(int));
	if(temp==0){
		return INTARR_BADALLOC;
	}
	int x=0;
	for(x=0;x<(ia->len);x++){
		temp[x]= ia->data[x];
	//printf("im in loop\n");
	
	}
	temp[x]=val;
	//printf("%d\n", temp[x]);
	
	//printf("%d\n", ia->len);
	ia->len+=1;
	//printf("%d\n", ia->len);
	//insert into ia
	ia->data=temp;
	
	//printf("%d\n", ia->data[x]);
	
	return INTARR_OK;
	

}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){

	if(ia==0){
		return INTARR_BADARRAY;
	}
	if((ia->len ) ==0){
		return INTARR_BADINDEX;
	}
	//create a new array without the highest index- same as appending but in reverse
	int* temp= malloc(((ia->len)-1)*sizeof(int));
	//if(temp==0){
	//	return INTARR_BADARRAY;
	//}
	int x=0;
	for(x=0;x<((ia->len)-1);x++){
		temp[x]=ia->data[x];
	}
	
	if(!(i==NULL)){
		*i=ia->data[x];
		//printf("%i\n", *i);
	}
	//printf("%d\n", ia->len);
	ia->len-=1;
	//printf("%d\n", ia->len);
	ia->data=temp;
	return INTARR_OK;
	

}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
	if(ia==0){
		return INTARR_BADARRAY;
	}
	if(newlen<(ia->len)){
		int diff = (ia->len)-newlen;
		int * temp= malloc(((ia->len)-diff)*sizeof(int));
		
		int x=0;
		for(x=0; x<(ia->len)-diff;x++){
			temp[x]=ia->data[x];
		}
		ia->len -=diff;
		ia->data=temp;
		return INTARR_OK;
	}
	if(newlen>(ia->len)){
	int diff = newlen-(ia->len);
	int*temp = malloc(((ia->len)+diff)*sizeof(int));
	int x = 0; 
		for(x=0; x<(ia->len)+diff;x++){
			if(x<ia->len){
				temp[x]=ia->data[x];
			}
			else{
				temp[x]=0;
			}
		}
		ia->len +=diff;
		ia->data=temp;
	}
	
	return INTARR_OK;


}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last ){
	if(ia==0 || first<0 || last > (ia-> len)-1 || last<first){
		return NULL;
	}
	intarr_t* newMe = malloc(sizeof(intarr_t));
	newMe->data= malloc((last-first+1)*sizeof(int));
	int x = 0;
	int y=0;
	for(x=0;x<ia->len;x++){
		if(x>=first && x<=last){
			//printf("im walking over here\n");
			newMe->data[y]=ia->data[x];
			y++;
		}
	}
	newMe->len=(last-first+1);
	
	return newMe;
}
