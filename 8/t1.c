#include <stdio.h>
#include <stdlib.h>
#include "point_array.h"

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
	//check if pa is valid
	if(pa != NULL){
	//intialize all points to 0
	//allocate enough space for pointer 
		pa-> len = 0;
		pa-> points = malloc(sizeof (point_t *));
		pa->reserved = 0;
	}
	

}

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
	//check if pa is valid
	//for every malloc you need a free. 
	if(pa != NULL){
	pa->len = 0
	pa->reserved = 0
	free(pa->points);
	free(pa);
	
	}

}

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
	//valid array
	if(pa ==NULL){
		return 1;
	}
	//valid new element
	if(p == NULL){
		return 1;
	}
	//realloc space for new array len +1 increase len by 1
	if(!(pa->points = realloc((pa->points), sizeof(point_t)*(pa->len+1)))){
		return 1;
	}
	pa->points[(pa->len)+1]= *p;
	pa->len ++;
	return 0;

}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){

}
