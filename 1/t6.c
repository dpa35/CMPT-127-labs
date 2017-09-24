#include <stdio.h>
#include <math.h>

int main (void)
{
	int result;
	float i;
	float smallest;
	float largest = 0; 
	float total = 0;
	float count = 0;
	//while loop until EOF indicator detected//
	while (result != EOF)
	{
		total += i;
		count ++;
		result = scanf("%f", &i);
		//input value is in range and floating point value
		if(sizeof(i)==4 && i>= -100000 && i<=100000)
		{	
			if( count == 1)
			{
			smallest = i;
			}
			if(i <= smallest)
			{
			smallest = i; 
			}
			if(i >= largest)
			{
			largest = i; 
			}

		
		}
		
	}
	printf("%.2f %.2f %.2f\n", smallest, largest, (total/(count-1)) );
	
	return 0;
}
