#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

int main( int argc, char* argv[] )
{
  // test the create function
  list_t* list = list_create();
	

  // check to see if the create function did everything it was supposed to
  if( list == NULL )
    {
      printf( "create: create failed to malloc\n" );
      return 1;
    }

  if( list->head != NULL )
    {
      printf( "create: head is not null!\n" );
      return 1;
    }

  if( list->tail != NULL )
    {
      printf( "create: tail is not null!\n" );
      return 1;
    }


//t3.c => element_index doesnt check if list is empty

//t5.c


  	//t1.c => list index doesnt check if list is empty
	list_t * list1 =list_create();
	
	
	list_destroy(list1);
	printf("blah\n");
	//element_t * el = list_index(list1, 10);
	//if( el==NULL){
		//printf("blah\n");
	//}
	
	
	
	//t2.c => element_create doesn't set el->next to NULL
	
	list_t * listBoots = list_create();
	int x = 0;
	for(x=0; x<1000; x++){
		list_append(listBoots, 8008135);
	}
	list_destroy(listBoots);
	list_t * list2 = list_create();
	element_t * test = element_create(10);
	element_t * test2 = element_create(20);
	test2->next = test;
	free(test2);
	list_append(list2, 10);
	if(list2->tail->next != NULL){
		printf("t2 failed. Did not set new element tail to NULL\n");
		return 1;
		assert(list->tail->next==NULL);
	}
	//t3.c => element_index doesnt check if list is empty
	//now index starts at 1. skips first element
	list_t * list3 = list_create();
	
	for(x=0; x<5;x++){
		list_append(list3, x);
	}
	element_t * el3 = list_index(list3, 0);
	if(el3->val !=0){
		printf("t3 failed. Wrong index value returned.\n");
		return 1;
	}


	//t4.c =>list prepend doesnt check if list is empty to set tail to new element
	list_t * list4 = list_create();
	list_prepend(list4, 69);
	if(list4->tail != list4->head){
		printf("t4 failed. Did not set tail to new element (Empty List).\n");
		return 1;
	}
	/*if( el==NULL){
		printf("list is empty, t1 fail\n");
		return 1;
	}*/
	
		
	
	

  printf("this is working\n");
  return 0; // tests pass
}
