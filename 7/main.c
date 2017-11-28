#include <stdio.h>
#include <stdlib.h>

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

//t2.c => element_create doesn't set el->next to NULL
//t3.c => element_index doesnt check if list is empty
//t4.c => list_prepend doesnt check if the list is empty, if list is empty doesn't assign list tail to an element
//t5.c


  	//t1.c => list index doesnt check if list is empty


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
