#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "image3.hpp"

int main(){
  Image* img = new Image();
  
    img->resize(20, 20, 30);
    printf("size of rows: %i \n", img->rows);
    printf("size of cols: %i \n", img->cols);


    


  delete img;


}