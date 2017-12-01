#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
  double x, y, z; // location in 3D space
} point_t;

typedef struct 
{
  size_t len;      // number of points in the array
  point_t* points; // an array of len point_t structs
size_t reserved; 

} point_array_t;

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa );

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa );

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p );

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i );