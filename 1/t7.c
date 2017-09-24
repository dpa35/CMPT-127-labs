#include <stdio.h>

int main (void)
{
	float end;
	float n;
	while (end != EOF)
	{
		end = scanf("%f", &n);
		for( int i = 0; i < n; i++)
		{
			printf("#");
		}
		printf("\n");
	}
return 0;
}
