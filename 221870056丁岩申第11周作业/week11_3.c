//3 6 4 17 8 5 9 10 9 19 7 20 4 14 21 23
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
	int x[4][4], i, j, num = 10;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", *(x + i) + j);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			if (j <= i && prime(x[i][j]) == 0)
			{
				num--;
				x[i][j] = 0;
			}
		}
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			if (j <= i && prime(x[i][j]) == 1)
			{
				int p;
				for (p = x[i][j] + 1;; p++)
				{
					if (prime(p) == 1 )
					{
						x[i][j] = p; break;
					}
				}
			}
		}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d ", *(*(x + i) + j));
		printf("\n");
	}
	printf("count=%d", num);
	return 0;
}