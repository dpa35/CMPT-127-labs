#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <assert.h>

int main(void){

    list_t * test = list_create();
    list_append(test, 50);
    list_append(test, 40);
    list_append(test, 30);
    list_append(test, 20);
    list_append(test, 10);
    list_print(test);
    list_sort(test);
    list_print(test);

}