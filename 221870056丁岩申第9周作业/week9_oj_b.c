#include<stdio.h>
int prime(int n)
{
	int i, h = 1;
	if (n == 1)h = 0;
	for (i = 2; i < n; i++)
{
		if (n % i == 0)
			h = 0;
}
	return h;
}
int prime(int n);
int main()
{
	int m, n, t, i, o = 0;
	scanf("%d %d", &m, &n);
	if(m>n)
	{
		t = m; m = n; n = t;
	}
	for (i = m; i <= n - 2; i++)
	{
		if (prime(i) == 1 && prime(i + 2) == 1)
		{
			printf("(%d,%d)\n", i, i + 2); o = o + 1;
		}
	}
	if (o > 0)
		printf("t=%d\n", o);
	else
		printf("该区间内无孪生素数\n");
	return 0;
}