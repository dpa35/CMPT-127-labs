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

  // now test all the other functions (except list_print) to see if
  // they do what they are supposed to
//t1.c => list index doesnt check if list is empty
//t2.c => element_create doesn't set el->next to NULL
//t3.c => element_index doesnt check if list is empty
//t4.c => list_prepend doesnt check if the list is empty, if list is empty doesn't assign list tail to an element
//t5.c


  //check to see if create element works 
  
	/*element_t * el = element_create(69);
	//check value
	if(el->val != 69){
		printf("val is not correct!\n");
		return 1;
	}
	//check next pointer points to NULL
	if(el->next != NULL){
		printf("element create: next is not null!\n");
		return 1;
	}
	list_append(list, 70);
	if(list->tail->next != NULL){
		printf("t2 fail");	
		return 1;
	}*/

	list_t * list2 = list_create();
	list2->head = NULL;
	//empty list return a el pointing to NULL
	element_t * el = list_index(list2, 10);
		if(el ==NULL){
			printf("list is empty\n");
			return 1; 
		}
	 
	//testing list destroy
	list_destroy(list2);
	//t1.c =>list index doesnt check if list is empty


  printf("this is working\n");
  return 0; // tests pass
}
