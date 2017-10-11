#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int letter[26]={};
	float letterCount[26]={};
	int curChar = getchar();
	float totalCount = 0.0;
	int x = 0;
	//establish each letter element spot in array(Uppercase:because they show up first in ASCII
	while(x<26){
		letter[x] = 97+x;
		x++;
	}
	
	//checking to see if curChar is a letter, if lowercase subtract 32 
	while (curChar != EOF){
		if (curChar>64 && curChar <91 || curChar>96 && curChar<123){
		  if(curChar < 96){
			curChar += 32;
		  }
		for (x=0; x<26; x++){
			if (letter[x]==curChar){
				letterCount[x] += 1.0;
		totalCount += 1.0;
			}	
		}
		}																	
		curChar =getchar();
	}
	float freq = 0.0;
	for(x=0; x<26; x++){
		if(letterCount[x] != 0){
			freq = (letterCount[x])/totalCount;
			printf("%c %.4f\n", letter[x], freq);
		}
	}

}	 

