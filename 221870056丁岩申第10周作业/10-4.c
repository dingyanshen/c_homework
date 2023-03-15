#include<stdio.h>
int Del_findgcd(int a[], int n, int* f);
int gcd(int x, int y);
int main()
{
	int i, a[999], num, f, j, l;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", &a[i]);
	}
	l = Del_findgcd(a, num, &f);
	for (j = 0; j < l-1; j++)
	{
		printf("%d ", a[j]);
	}
	printf(", max common divisor is %d.", f);
	return 0;
}
int Del_findgcd(int a[], int n, int* f)
{
	int i, j, k;
	if (n % 2 == 0)
	{
		for (i = 0; i <= (n - 2) / 2; i++)
			a[i] = a[2 * i];
	}
	else
	{
		for (i = 0; i <= (n - 1) / 2; i++)
			a[i] = a[2 * i];
	}
	k = a[0];
	for (j = 0; j <= i-1; j++)
	{
		k = gcd(k, a[j]);
	}
	*f = k;
	return (i + 1);
}
int gcd(int x, int y)
{
	int p;
	while ((p = x % y) != 0)
		x = y,y = p;
	return y;
}
