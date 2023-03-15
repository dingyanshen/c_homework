#include<stdio.h>
int huiwen(long p);
int fun(long n,long *hw);	
int huiwen(long p)
{
	int m = 0, q;
	q = p;
	while(q>0)
	{
		m = m * 10 + q % 10;
		q = q / 10;
	}
	if (m == p)
		return 1;
	else
		return 0;
}
int fun(long n,long *hw)
{
	int m, t, d = 0;
	while(huiwen(n)==0&&d<=10000)
	{
		m = 0; t = n;
	while(t>0)
	{
		m = m * 10 + t % 10; t = t / 10;
	}
	n = n + m; d = d + 1;
	}
	if (d == 10000)
		return -1;
	else
	{
		*hw = n;
		return d;
	}
}
int main()
{
	int a, b, c;
	scanf("%d", &a);
	c = fun(a, &b);
	if (c == -1)
		printf("error");
	else
		printf("%d,%d\n", b, c);
	return 0;
}