#include <stdio.h>
#include <math.h>

int main(void)
{
	float i;
	scanf("%f", &i);
	printf("%.0lf %.0lf %.0f\n", floor(i), round(i), ceil(i));
	return 0;
}
