#include <stdio.h>
#include <math.h>

int main(void)
{
	float i;
	
//to ensure that result does not have a random intial value and that it is not 0//
	int b;
	b = scanf("%f", &i);
	if(b == 1)
	{
		printf("%.0lf %.0lf %.0f\n", floor(i), round(i), ceil(i));
	}
	else
	{
		printf("scanf error: (%d)\n", b);
	}
	return 0;
}
