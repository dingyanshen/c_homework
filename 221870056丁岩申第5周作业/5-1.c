#include<stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	if (a > b)
		c = a, a = b, b = c;
	d = b % a;
	if (d == 0)
		printf("%d can be divided by %d", b, a);
	else
		printf("%d cannot be divided by %d", b, a);
	return 0;
}