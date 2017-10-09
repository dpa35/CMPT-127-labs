#include <stdio.h>
#include <math.h>

int main (void)
{
	int result;
	float i;
	result = scanf("%f", &i);
	//while loop until EOF indicator detected//
	while (result == 1)
	{
		
		printf("%.0lf %.0lf %.0f\n", floor(i), round(i), ceil(i));
		result = scanf("%f", &i);
	}
		
	if (result == EOF){
		printf("Done.\n");
	}
	else{
		printf("scanf error: (%0.0lf)", i);
	}
	
	return 0;
}
