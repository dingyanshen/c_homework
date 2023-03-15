#include<stdio.h>
int main()
{
	int x, y, y1, y2, y3, y4, y5, y6, Y3, Y5;
	for (x = 317; x * x <= 999999; x++)
	{
		y = x * x;
		y1 = y % 10;
		y2 = ((y - y1) / 10) % 10;
		Y3 = ((y - y1) / 10 - y2) / 10; y3 = Y3 % 10;
		y4 = ((Y3 - y3) / 10) % 10;
		Y5 = ((Y3 - y3) / 10 - y4) / 10; y5 = Y5 % 10;
		y6 = y / 100000;
		if (y1 == y6 && y2 == y5 && y3 == y4)
			printf("%d\n", y);
	}
	return 0;
}