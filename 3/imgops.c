/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
	int x = 0;
  for (x=0;x< (cols*rows);x++){
	array[x]= 0;
	}
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
  return NULL;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  int x=0;
  int smallest = 255;
  for(x=0; x<(cols*rows); x++){
	if(array[x] < smallest){
		smallest = array[x];
	}
  }
  return smallest;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  // your code here
  int x = 0;
  int largest= 0;
  for(x=0; x<(cols*rows);x++){
	if(array[x]>largest){
		largest = array[x];
	}
  }
  return largest;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  // your code here
	int x = 0;
	for (x=0;x<(cols*rows);x++){
		if(array[x]==pre_color){
			array[x]=post_color;
		}
	}
	return;
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  // your code here
	//need to reverse each row individually
	//maintain two indexes that converge with a loop going throw the entire array
	int x = 0;
	int y = 0;
	int z = 0;
	uint8_t temp = 0;

	for(x=0;x<rows;x++){
		y= (cols * x);
		z = (x*cols) + (cols-1);
		while(y<z){
			temp = array[y];
			array[y] = array[z];
			array[z] = temp; 
			y++;
			z--;

		}
	}
			
		
	
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
    // your code here
	//need to reverse each coloumn individually
	//keep 2 index values and go through coloumns with loop
	int x = 0;
	int y = 0;
	int z = 0;
	uint8_t temp = 0;
	int i = 0;
	while ( i< cols){
		for (x = 0; x<((rows-1)/2); x++){
			y= (cols * x);
			z = (rows-x -1) * (cols);
			if (y<z){
				temp = array[y+i];
				array[y+i] = array[z+i];
				array[z+i] = temp;
				
			

			}
		}
		i++;
	}
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // your code here
	//go through array. find color. return x and y pos
	//keep track of what coloumn and row were in
	
	int z = 0;
	//try using counters for rows/columns
	int col_count=0;
	int row_count=0;
	for( z=0; z<(rows*cols); z++){
		if(array[z]==color){
			*x= col_count;
			*y=row_count;
			return 1;
		}
		if(col_count==cols){
			col_count=0;
			row_count++;
		}
		col_count ++;
		
	

	}
	
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // your code here
	int x = 0;
	for (x=0; x<(rows*cols);x++){
		array[x] = 255-array[x];
	}
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  // your code here
	int x =0;
	for(x=0; x<(cols*rows);x++){
	//multiply elements by scale_factor
		if (scale_factor * array[x] > 255){
			array[x]=255;
		}
		else{
		array[x]= round(scale_factor * array[x]);
		//set threshold
		
		}
	}

}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
	//find max and min for scaling factor
	uint8_t lightest = max(array, cols, rows);
	uint8_t darkest = min(array, cols, rows);
	//go through array to change every element
	int x=0;
	//difference in lightest/darkest(causes rounding error??
	
	float test2= lightest-darkest;
	float test = 0.0;
	for(x=0;x<(cols*rows); x++){
	//translate by min and use scaling factor => (b-a)(x-min)/(max-min) +a
	//where a and b are desired min and max respectively
	//off by one may be truncation error prior to rounding ??? make float
		test = (255)*(array[x]-darkest)/(test2);
		array[x] = round(test);
	
	}
    // your code here
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  //declare array and allocate memory for it (original size of array unknown)
	uint8_t *arrayB = malloc((cols/2)*(rows/2) * sizeof(uint8_t));
	
//insert values at p,q with avges of values indicated
//p =(x*(cols/2)) & q = y and y<(rows/2)(loop)

	int x = 0;
	int y = 0;
	float total = 0.0;
	float average = 0.0;
	for(x=0; x<(rows/2); x++){
		for( y=0; y<(cols/2);y++){
//sum up arrays by subbing in vales into p and q formula
//failed assert???
			total = array[ (2*x)*cols + (2*y)] +
		    		array[(2*x+1)*cols + (2*y)] +
				array[(2*x+1)*cols + (2*y+1)] +
				array[(2*x)*cols +(2*y +1)] ;
			average = (total/4.0);
//average total
			arrayB[x*(cols/2)+y]= round(average);
			     
			
		}
	
	
	}
	return arrayB;



	// your code here*/
 
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
	if(right==left && bottom ==top){
		return;
	}
	int x = 0;
	int y= 0;
	for(x=0;x<rows;x++){
		for(y=0;y<cols;y++){
			if(x>=top && x<bottom && y>=left && y<right){
				array[(x*cols)+y]=color;
			}
		}
	}
	
    // your code here
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
	unsigned long int sum =0; 
	if(right ==left && bottom == top){
		return sum;
	}
    int x=0;
    int y=0;
	for(x=0;x<rows;x++){
		for(y=0;y<cols;y++){
			if(x>=top && x<bottom && y>=left && y<right){
				sum += array[(x*cols)+y];
			}
		}
	}
    return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
	//empty region
	if(((right-left) * (top-bottom))==0){
		return NULL;
	}
    // your code here
	//allocate enough memory in heap for region
	uint8_t* arrayB= malloc((right-left)*(bottom-top)*sizeof(uint8_t));
	int x=0;
	int y=0;
	int z=0;
	//if in region, copy pixel into new array
	for(x=0;x<rows;x++){
		for(y=0;y<cols;y++){
			if(x>=top && x<bottom && y>=left && y<right){
				arrayB[z]=array[(x*cols)+y];
				z++;
			}
		}
	}
	return arrayB;
	
}


