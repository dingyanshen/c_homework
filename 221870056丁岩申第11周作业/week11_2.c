//1 4 2 3 4 1 2 5 5 9
#include<stdio.h>
int main()
{
	int a[10], b[10], i, n = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", a + i);
	for (i = 0; i < 10; i++)
	{
		int m, t = 0;
		for (m = 0; m < 10; m++)
		{
			if (b[m] == a[i])
				t++;
		}
		if (t != 0)
			n++;
		else
			b[i - n] = a[i];
	}
	for (i = 0; i < 10 - n; i++)
		a[i] = b[i];
	for (i = 0; i < 10 - n; i++)
		printf("%d ", a[i]);
	return 0;
}