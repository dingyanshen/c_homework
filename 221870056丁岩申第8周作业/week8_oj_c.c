#include<stdio.h>
#include<math.h>
int main()
{
	double x, a = 1, xm, y, un = 1;
	int m, sign = 1;
	scanf("%lf", &x);
	xm = x;
	y = x;
	for (m = 3; fabs(a) >= 1e-8; m = m + 2)
	{
		xm = xm * x * x;
		un = un * (m - 1) * m;
		sign = sign * -1;
		a = sign * xm / un;
		y = y + a; 
	}
	printf("%.1lf", y);
	return 0;
}
