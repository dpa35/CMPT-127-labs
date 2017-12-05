#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image3.hpp"


Image :: Image ()
    : cols (0),
      rows (0),
      pixels(NULL){{}{}}

Image :: ~Image ()
{
    if(pixels != NULL){
        int x =0;
        //delete[] deletes every element in array 
        for(x=0; x< this->rows; x++){
                delete [] this->pixels[x];
        }
    }
    delete[] this->pixels;

}

int Image :: resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
    //delete pixels
    int x = 0;
    for(x=0; x< this->rows; x++){
        delete[] this->pixels[x];
    }
    delete [] this->pixels;
    //replace pixels with new pixelsw ith fill color of new dimension
    //use this pointer when looking at class' data structure

    this->rows = height;
    this->cols = width;
    //use new to declare new array instead of malloc
    //using 2d array this time 
    uint8_t ** newArr = new uint8_t*[height];
    for(int x =0; x<width; x++){
        newArr[x] = new uint8_t[width];
    }
    if(newArr == NULL){
        return 1;
    }
    this-> pixels = newArr;
    int y = 0;
    for(x=0; x< this->rows; x++){
        for(y=0; y< this->cols; y++){
            this->pixels[x][y] = fillcolor;
        }
    

    }
    
    
    //initialize every pixel to fillcolor
    return 0;
        
    
  }


int Image :: set_pixel( unsigned int x, unsigned int y, uint8_t color ){
      //check if (x,y) is in range (x = cols), (y= rows)
      if(x >= this->cols || y >=this->rows){
          return 1;
      }
      
      this->pixels[y][x] = color;
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

        *colorp = this->pixels[y][x];
        return 0;


  }

/* Saves the image in the file filename. In a format that can be
     loaded by load().  Returns 0 on success, else a non-zero error
     code. */
int Image :: save( const char* filename ){
    //write the contents of filename into a format that can be saved and loaded
    //LAB 6 has most of algorithm
    printf("i got here\n");
    if(filename == NULL){
        return 1;
    }
    printf("I got to this part\n");

    FILE * f = fopen(filename, "w");
    if(f==NULL){
        printf("failed to open\n");
        return 1;
    }
    //if image is blank write a blank file
    if(this->pixels ==NULL){
        fclose(f);
        return 0;
        printf("empty file\n");

    }
    //write onto f from contents of filename
    //write len, cols, rows, pixel info
    int len = (this->cols * this-> rows);
    fwrite(&len, sizeof(int), 1, f);
    printf("wrote len\n");

    fwrite(&(this->rows), sizeof(int), 1, f);
    printf("wrote rows\n");

    fwrite(&(this->cols), sizeof(int), 1 , f);
    printf("wrote cols\n");
    //adjust to deal with 2d array 
    int x =0;
    int y = 0;

    for(x=0; x< this->rows; x++){
        for(y=0; y<this->cols; y++){
            fwrite(&(this->pixels[x][y]), sizeof(uint8_t),1, f);
        }
    }
    
    printf("wrote pixels\n");

    fclose(f);
    return 0;

}
/* Load the an image from the file filename, replacing the current
     image size and data. The file is in a format that was saved by
     save().  Returns 0 success, else a non-zero error code . */
  int Image::load( const char* filename ){
    if(filename == NULL){
        return 1;
    }

    FILE * f = fopen(filename, "r");
    if(f==NULL){
        return 1;
    }
    //read from filename replacing data/pixels
    int len2 = 0;
    //check length if 0, reset and return
    fread(&len2, sizeof(int), 1, f);
    if(len2==0){//empty filename
        this->cols = 0;
        this->rows = 0;
        this->pixels =NULL;
        fclose(f);
        return 0;

    }
    //read and store row/col vals
    //should not be 0, empty already dealt with
    int row2 = 0;
    int col2 = 0;
    fread(&row2, sizeof(int), 1, f);
    fread(&col2, sizeof(int), 1, f);

    //resize pixel size based off filename pixel size
    this->resize(col2, row2, 0);
    //adjust for 2d array
    int x =0;
    int y=0;
    for(x=0; x< this->rows;x++){
        for(y=0; y<this->cols; y++){
            fread(&(this->pixels[x][y]), sizeof(uint8_t), 1, f);
        }
    }
    if(this->pixels == NULL){
        return 1;
    }

    fclose(f);
    return 0;
    //
  }

