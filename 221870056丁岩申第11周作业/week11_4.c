//1 4 5 7 3 5 7 8 9 10 2 3 1 3 4 2 1 2 1 1
#include<stdio.h>
#include<stdlib.h>
void line_sort(int a[][4], int b[], int n)
{
	int i, j, k, ta, tb, flag;
	for (i = 0; i < n; i++)
		b[i] = a[i][0] + a[i][1] + a[i][2] + a[i][3];
	for (i = 0; i < n - 1; i++)
	{
		flag = 1;
		for (j = 0; j < n - 1 - i; j++)
			if (*(b + j) > *(b + j + 1))
			{
				for (k = 0; k < 4; k++)
				{
					ta = a[j][k];
					a[j][k] = a[j + 1][k];
					a[j + 1][k] = ta;
				}
				tb = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tb;
				flag = 0;
			}
		if (flag)
			break;
	}
}
int main()
{
	int x[5][4],y[5];
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", *(x + i) + j);
	line_sort(x, y, 5);
	getchar(); 
		for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d ", *(*(x + i) + j));
		printf("\n");
	}
	printf("sum\n");
	for (i = 0; i < 5; i++)
		printf("%d ", y[i]);
	return 0;
}