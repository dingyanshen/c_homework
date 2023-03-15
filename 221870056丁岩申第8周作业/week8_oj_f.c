#include<stdio.h>
#include<math.h>
double f(double x)
{
	return exp(x) + x;
}
int main()
{
	double a = -1, b = 1, c, x, eps = 1e-6;
	if (fabs(f(a)) < eps)
		x = a;
	else if (fabs(f(a))< eps)
		x = b;
	else {
		c = (a + b) / 2;
			while (fabs(f(c)) > eps && fabs(b - a) > eps) {
				if (f(a) * f(c) < 0)
					b = c;
				else
					a = c;
					c = (a + b) / 2;
			}
		x = c;
	}
	printf("x=%.6lf", x);
	return 0;
}
