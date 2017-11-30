#include <stdio.h>
#include <stdlib.h>
#include "point_array.h"



// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
	pa->len =0;
	pa->points = malloc(sizeof(point_t));
	pa->reserved=1;

}

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
	pa->len = 0;
	pa->reserved =0;
	free(pa->points);
	free(pa);

}

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
	//check if pa is valid
	if(pa==NULL){
		return 1;
	}
	if(pa->points==NULL){
		return 1;
	}
	if(p==NULL){
		return 1;
	}
	//decrease reserved space by 1
	pa->reserved--;
	//check to see if more allocation is required, reallocate if necessary
	//array should double in length with each allocation
	if(pa->reserved == 0 && pa->len != 0){
		pa->points=realloc(pa->points, ((pa->len)*2)*sizeof(point_t));
		if(pa->points ==NULL){
			return 1;
		}
		//reserved space doubles from previous value
		pa->reserved= pa->len;
		

	}
	pa->points[pa->len]= *p;
	pa->len++;

}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){

}
