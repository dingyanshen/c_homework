#include<stdio.h>
int main()
{
	int x, t, i, x1, x2, x3;
	for (x = 100; x < 1000; x++)
	{
		for (t = 1, i = 2; i < x; i++)
		{
			if (x % i == 0) 
				t = 0;
		}
		if (t == 1)
		{
			x1 = x % 10;
			x2 = ((x - x1) / 10) % 10;
			x3 = x / 100;
			if ((x1 + x2) % 10 == x3)
				printf("%d\n", x);
		}
	}
	return 0;
}
