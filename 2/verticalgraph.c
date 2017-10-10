#include <stdio.h>
#include <stdlib.h>

int main(void){
	//create array to contain up to 80 values
	int input[80];
	int i = 0;
	int x = 0;
	int largestValue = 0; 
	int currentValue = 0;
	while((i== 0) || (i<80 && currentValue != EOF)){
		currentValue = scanf("%d", &input[i]);
		i++;
	}
	
	//find largest value in array to determine # of rows
	
	for(x=0; x<i; x++){
		if(input[x] > largestValue){
			largestValue = input[x];
		}
	}
	//find number of columns via elements in array
	int column = i; 
	//print lines. " " when input[]<x(largestvalue) "#" otherwise	
	int y = 0;
	for(x=largestValue; x>0;x--){
		for(y=0; y<column; y++){
			if((x-input[y])<= 0){
				printf("#");
			}
			else if((x-input[y])> 0){
				printf(" ");
			}
		
		}
	printf("\n");
	}

	return 0;


	


}
