#include <stdio.h>
#include <stdlib.h>
#include "list.h"


//based off of bobby's LL quicksort lectures
void list_sort(list_t * intlist){
    //base case
    if(intlist->head == intlist->tail){
        return;
    }
    //split list into roughtly 2 equal pieces with a pivot 
    //remove head from list (pivot)
    int pivot = intlist->head->val;
    element_t * pivotEl = intlist->head;
    intlist->head = intlist->head->next;

//partition with pivot
    //smaller than pivot and larger than pivot
    list_t * small = list_create();
    list_t * large = list_create();

    //set up current and next for loop

    element_t * curr = intlist->head;
    element_t * next;

    while(curr !=NULL){//not end of list
        next = curr->next;
        curr->next = NULL;
        if(curr-> val <=pivot){
            list_append(small, curr->val);
        }
        else if(curr->val > pivot){
            list_append(large, curr->val);
        }
        curr=next;
    }
    intlist->head = NULL;
    intlist->tail= NULL;
    
    list_sort(small);
    list_sort(large);

    //join
    LLcatenate(intlist, small);
    list_append(intlist, pivotEl->val);
    LLcatenate(intlist, large);


}

void LLcatenate(list_t * list1, list_t * list2){
    //check if list2 is empty
if(list2->head == NULL){
    assert(list2->tail == NULL);
    free(list2);
}
//check if list1 is empty, if it is copy L2
if(list1->head==NULL){
    assert(list1->tail==NULL){
        *list1= *list2;
    }
}
//both list1 and list2 are not empty
if(list2!=NULL){
    list1->tail->next= list2->head;
    list1->tail=list2->tail;
    free(list2);
}

}