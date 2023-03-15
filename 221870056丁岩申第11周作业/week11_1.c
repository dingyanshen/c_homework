//108 4 19 7 23 66 49 13 33 35
#include<stdio.h>
int prime(int x)
{
	int i, t = 0;
	if (x == 1 || x == 0)
		return 0;
	else
	{
		for (i = 2; i < x; i++)
		{
			if (x % i == 0)
				t++;
		}
		if (t > 0)
			return 0;
		else
			return 1;
	}
}
int main()
{
	int x[10], i;
	for (i = 0; i < 10; i++)
		scanf("%d", x + i);
	int m = 0, n = 9;
	for (m = 0; m < 10; m++)
	{
		if (m < n && prime(x[m]) == 1)
		{
			for (; n >= 0;n--)
				if (prime(x[n]) == 1)
				{
					int t;
					t = x[m];
					x[m] = x[n];
					x[n] = t;
					n--;
					break;
				}
		}
		else if (m >= n)
			break;
	}
	for (i = 0; i < 10; i++)
		printf("%d ", x[i]);
	return 0;
	}