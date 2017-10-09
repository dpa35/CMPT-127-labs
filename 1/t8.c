#include <stdio.h>
#include <math.h>

int main (void){

int width = 0;
int height = 0;
int breath = 0;
int x = 0;
int y = 0;

int test = scanf("%d%d%d", &width, &height, &breath);

while( test != EOF){
	for (x = 0; x<width; x++){	
		printf("#");
	}
	printf("\n");
	for(x = 0; x<(height-2); x++){
		printf("#");
		for(y=0; y<(width-2); y++){
			printf(".");
		}
		printf("#\n");
	}
	if(!(height<2)){
		for(x=0; x<width; x++){
			printf("#");
		}
		printf("\n");
	}
	

	
	test = scanf("%d%d%d", &width, &height, &breath);
	

}
}
