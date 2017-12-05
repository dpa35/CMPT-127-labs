#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image3.hpp"

int main (){

    Image * test = new Image();

    int i = test->cols;
    printf("col is size %i \n", i);


    test-> resize(100, 100, 72);

    int j = test->cols;
    printf("col is size %i \n", j);
    int x = 0; 
    int y = 0;

    for (x=0; x<100; x++){
        printf("[");
        for(y=0; y<100; y++){
            printf(" %d ", test->pixels[x][y]);
        }
        printf("]\n");
    }



}