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
	printf("%.0lf %.0lf %.0f\n", floor(i), round(i), ceil(i));
	}
	printf("Done.\n");
	return 0;
}
