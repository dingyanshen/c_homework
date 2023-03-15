#include<stdio.h>
int main()
{
	int x, i = 1, sum = 0;
	for (x = 1; x <= 1000; x++)
	{
		for (i = 1; i < x; i++)
		{
			if (x % i == 0)
				sum = sum + i;
		}
		if (sum == x)
			printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}
