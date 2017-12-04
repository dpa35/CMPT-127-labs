#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image.hpp"

//look at intarr for insights

Image :: Image()
  : cols(0),//initialization 
    rows(0),
    pixels(NULL){//dont need to do any more work since all initialization has been done 
    }


Image :: ~Image(){
    if (pixels !=NULL){
        delete[] pixels; 
    }
}

 /* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/ 
  int Image :: resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
    //delete pixels
    delete [] pixels;
    //replace pixels with new pixelsw ith fill color of new dimension
    //use this pointer when looking at class' data structure
    this->rows = height;
    this->cols = width;
    //use new to declare new array instead of malloc
    uint8_t * newArr = new uint8_t[height * width];
    if(newArr == NULL){
        return 1;
    }
    int x = 0;
    for( x=0; x< (height * width); x++){
        newArr[x]= fillcolor;
    }
    this-> pixels = newArr;
    //initialize every pixel to fillcolor
    return 0;
        
    
  }

/* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
  int Image :: set_pixel( unsigned int x, unsigned int y, uint8_t color ){
      //check if (x,y) is in range (x = cols), (y= rows)
      if(x >= this->cols || y >=this->rows){
          return 1;
      }
      
      this->pixels[y*(this->rows)+x] = color;
      return 0;
  }


/* Gets the color of the pixel at (x,y) and stores at the address pointed to 
     by colorp. Returns 0 on success, else a non-zero error code. */
  int Image :: get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
        //check if (x,y is in range)
        if(x>= this->cols || y>= this->rows){
            return 1;
        }
        //check if colorp is valid
        if(colorp ==NULL){
            return 1;
        }

        *colorp = this->pixels[y*(this->rows)+x];
        return 0;


  }
 /* Saves the image in the file filename. In a format that can be
     loaded by load().  Returns 0 on success, else a non-zero error
     code. */
int Image :: save( const char* filename ){
    if(filename == NULL){
        return 1;
    }
}