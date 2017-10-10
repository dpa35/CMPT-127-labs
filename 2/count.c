#include <stdio.h>
#include <stdlib.h>

int main (void){
	unsigned long wordCount = 0;
	unsigned long charCount = 0;
	unsigned long lineCount = 0;
	int oldChar = 0;
	int curChar = getchar();

	while (curChar != EOF){
		charCount++;
		//if current char is not a-z/A-Z/' and char before was then a word was counted
		if(!(curChar>64 && curChar<91 || curChar> 96 && curChar < 123 || curChar == 39)&&
		  (oldChar>64 && oldChar<91 || oldChar>96 && oldChar <123 || oldChar==39)){	
			wordCount++;
		  }

		
		//\n is detected
		if(curChar==10){
			lineCount++;
		}
		oldChar = curChar;
		curChar = getchar();
	}
	
	printf("%lu %lu %lu\n", charCount, wordCount, lineCount);
	return 0;
}
