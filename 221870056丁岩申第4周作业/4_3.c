#include<stdio.h>
#include<math.h>
int main()
{
	long double x,y;
	long double a, b, c, d, e;

	printf("please input x and y:");
	scanf("%lf,%lf", &x,&y);
	a = sin(x);
	b = cos(x);
	c = fabs(x);
	d = exp(x);
	e = pow(x,y);
	printf("results:\n%lf\n%lf\n%lf\n%lf\n%lf\n", a, b, c, d, e);
	return 0;
}