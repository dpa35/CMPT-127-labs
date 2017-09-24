#include <stdio.h>
#include <math.h>

int main (void)
{
	int result;
	//while loop until EOF indicator detected//
	while (result != EOF)
	{
		float i;
		result = scanf("%f", &i);
		if(sizeof(i)==4)
		{
		printf("%.0lf %.0lf %.0f\n", floor(i), round(i), ceil(i));
		}
		else
		{
		printf("scanf error: (%0.0lf)", i);
		}
	}
	printf("Done.\n");
	return 0;
}
