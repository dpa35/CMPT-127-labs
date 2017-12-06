#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image3.hpp"

int main (){

    Image * test = new Image();

    int i = test->cols;
    printf("col is size %i \n", i);


    test-> resize(20, 20, 45);

    int j = test->cols;
    printf("col is size %i \n", j);
    int x = 0; 
    int y = 0;

    for (x=0; x<20; x++){
        printf("[");
        for(y=0; y<20; y++){
            printf(" %d ", test->pixels[x][y]);
        }
        printf("]\n");
    }

    test->resize(10,10, 50);
    printf("im working\n");
    int r = 0; 
    int s = 0;

    for (r=0; r<10; r++){
        printf("[");
        for(s=0; s<10; s++){
            printf(" %d ", test->pixels[r][s]);
        }
        printf("]\n");
    }

    printf("im working\n");

}