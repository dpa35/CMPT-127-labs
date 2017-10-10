#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
		
	int x = 0;
	int y=0;	
	int count = 0;
	int phrase1 = strlen(argv[1]);
	int phrase2 = strlen(argv[2]);


	for(x=0;x<(phrase1-1);x++){
		if(argv[1][x]==argv[2][y] && count != (phrase2-1)){
			count++;
			y++;	
		}
		else if(argv[1][x] != argv[2][y] && count != (phrase2-1)){
			count = 0;
			y=0;
		}
	}
	if(count == (phrase2-1)){
		printf("true\n");
	}
	else if(count != (phrase2-1)){
		printf("false\n");
	}
	

}
