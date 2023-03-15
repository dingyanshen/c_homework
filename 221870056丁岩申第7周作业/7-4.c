#include<stdio.h>
int main()
{
	int x, i;
	scanf("%d", &x);
	printf("%d=", x);
	for (i = 2; i <= 100; i = i + 1)
	{
		while (x % i == 0)
			printf("%d*",i), x = x / i;
	}
	printf("\b ");
	return 0;
}
