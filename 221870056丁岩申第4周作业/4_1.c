#include<stdio.h>
int main()
{
	double num, x;
	printf("please input:");
	scanf("%lf", &num);

	printf("sign:");
	if (num <= 0)
	{
		x = -num;
		printf("-\n");
	}
	else
	{
		x = num;
		printf("+\n");
	}

	printf("integral part:%d\n", (int)x);
	printf("decimal fraction part:%lf\n", (float)(x - (int)x));
	return 0;
}