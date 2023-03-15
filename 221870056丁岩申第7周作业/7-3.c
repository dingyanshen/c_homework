#include<stdio.h>
int main()
{
	int x, x1 = 0, x2 = 0, x3 = 0, t, i, max, min;
	while (x1 == x2 && x1 == x3)
	{
		scanf("%d", &x);
		x1 = x % 10;//¸ö
		x2 = ((x - x1) / 10) % 10;//Ê®
		x3 = (x - (x % 100)) / 100;//°Ù
	}
		printf("%d ", x);
	for (i = 0; i < 7; i++)
	{
	    x1 = x % 10;
		x2 = ((x - x1) / 10) % 10;
		x3 = (x - (x % 100)) / 100;
		if (x1 < x2)
		{
			t = x2, x2 = x1, x1 = t;
			if (x3 > x1)
				t = x1, x1 = x3, x3 = x2, x2 = t;
			else if (x1 > x3 && x3 > x2)
				t = x2, x3 = x2, x2 = t;
		}
		else
		{
			if (x3 > x1)
				t = x1, x1 = x3, x3 = x2, x2 = t;
			else if (x1 > x3 && x3 > x2)
				t = x2, x3 = x2, x2 = t;
		}
		max = x1 * 100 + x2 * 10 + x3;
		min = x1 + x2 * 10 + x3 * 100;
		x = max - min;
		printf("%d ", x);
		if (x == 495) 
			break;
	}
	return 0;
}
