#include <stdio.h>


//function that checks to see if 2 arrays are identical
int identical( int a[], int b[], unsigned int len){
	int i = 0;
	for(i=0; i<len; i++){
		if(a[i]!=b[i]){
		return 0;
		}

	}
	return 1;
	
}
