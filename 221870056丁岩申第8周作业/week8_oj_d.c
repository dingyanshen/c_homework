#include<stdio.h>
int main()
{
	int x1 = 2, x2 = 3, i;
	printf("%d ", x1);
    printf("%d ", x2);
	for (i = 1; i <= 18; i++)
	{
		if (i % 2 == 1)
		{
			x1 = x1 + x2;
			printf("%d ", x1);
		}
		else 
		{
			x2 = x2 - x1;
			printf("%d ", x2);
		}
	}
	return 0;
}
