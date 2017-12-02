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
	pa->reserved--;
	//initial append (empty array)
	//malloc 2 slots (1 for intial point_t and 1 for reserved point_t increase reserve)
	if(pa->reserved ==0 && pa->len ==0){
		pa->points = malloc(2 * sizeof(point_t));
		if(pa->points==NULL){
				return 1;
		}
		pa->reserved= 1;
		printf("I'm working\n");
	}
	
	//decrease reserved space by 1
	//check to see if more allocation is required, reallocate if necessary
	//array should double in length with each allocation
	if(pa->reserved == 0 && pa->len != 0){
		pa->points=realloc(pa->points, ((pa->len)*2)*sizeof(point_t));
		if(pa->points ==NULL){
			return 1;
			printf("im working\n");
		}
		//reserved space doubles from previous value by making it length
		pa->reserved= pa->len;
		

	}
	pa->points[pa->len]= *p;
	pa->len++;

}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
	//sounds like unstable remove again
	//add 1 to reserve and decrease len since space is already allocated
	if(pa==NULL){
		return 1;
	}
	if(pa->points==NULL){
		return 1;
	}
	//check for empty array and valid index
	if(pa->len ==0){
		return 1;
	}
	if(pa->len <= i){
		return 1;
	}
	//unstable remove space is already allocated
	pa->points[i]=pa->points[((pa->len)-1)];
	//empty array 
	if(pa->points==NULL && pa->len ==0){
		return 1;
	}
	pa->len--;
	pa->reserved++;

	return 0;

}
