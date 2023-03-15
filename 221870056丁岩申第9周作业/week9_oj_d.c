#include <stdio.h>
#include <math.h>
double integral(double a, double b, long n, double (*p)(double))
{
	double h, s, x;
	int i;
	h = (b - a) / n;
	s = (p(a) + p(b)) / 2;
	x = a;
	for (i = 1; i < n; i = i + 1)
	{
		x = x + h;
		s = s + p(x);
	}
	return s * h;
}
double f(double x)
{
	return 2 * x + 1;
}
double integral(double a, double b, long n, double (*p)(double));
double f(double x);
int main()
{
	double a, b, y;
	long n;
	double (*p)(double);
	scanf("a=%lf,b=%lf,n=%ld", &a, &b, &n);
	p = cos, y = integral(a, b, n, *p);
	printf("integral cos:%.6lf\n", y);
	p = sin, y = integral(a, b, n, *p);
	printf("integral sin:%.6lf\n", y);
	p = f, y = integral(a, b, n, *p);
	printf("integral 2x+1:%.6lf", y);
	return 0;
}
