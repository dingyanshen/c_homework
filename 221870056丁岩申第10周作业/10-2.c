#include<stdio.h>
#include<math.h>
double f(double x)
{
	return x * x / 4 - sin(x);
}
double root(double a, double b)
{
	if (fabs(f(a)) < 1e-6)
		printf("x=%lf\n", a);
	else if (fabs(f(b)) < 1e-6)
		printf("x=%lf\n", b);
	else if (f((a + b) / 2) * f(b) > 0)
		root(a, (a + b) / 2);
	else
		root((a + b) / 2, b);
}
double f(double x);
double root(double a, double b);
int main()
{
	if (f(1) * f(2) > 0)
		printf("no root");
	else root(1, 2);
	return 0;
}