#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
		
	int x = 0;
	int y=0;	
	int count = 0;
	int phrase1 = strlen(argv[1]);
	int phrase2 = strlen(argv[2]);

	while(x<(phrase1-1) && count != (phrase2)){
		if(argv[1][x]==argv[2][y]){
			count++;
			y++;
			x++;
		}
		else if (argv[1][x] != argv[2][y]){
			count = 0;
			y=0;
			x++;
		}
		if (count == (phrase2-1)){
			printf("true\n");
		}
		else
		printf("false\n");
	}
	

}
