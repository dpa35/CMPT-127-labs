#include <stdio.h>
#include <stdlib.h>

int main (void){
	unsigned long wordCount = 0;
	unsigned long charCount = 0;
	unsigned long lineCount = 0;
	int curChar = getchar();

	while (curChar != EOF){
		charCount++;
		if(curChar>64 && curChar<91 || curChar> 96 && curChar < 123 || curChar == 39){
			wordCount++;
		}
		if(curChar==10){
			lineCount++;
		}
		curChar = getchar();
	}
	printf("%lu %lu %lu\n", charCount, wordCount, lineCount);
	return 0;
}
