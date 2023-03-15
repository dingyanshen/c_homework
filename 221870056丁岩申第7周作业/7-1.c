#include<stdio.h>
int main()
{
	int x, n = 1;
	scanf("%d", &x);
	while (x - x % 10 != 0)
	{
		x = x / 10;
		n = n + 1;
	}
	printf("%d", n);
	return 0;
 } 
