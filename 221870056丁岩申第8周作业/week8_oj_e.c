#include<stdio.h>
#include<math.h>
int main()
{
	double x, x1, eps=1e-6, f, f1;
	x = 1.0;
	do
	{
		x1 = x;
		f = cos(x1) - x1;
		f1 = -sin(x1) - 1;
		x = x1 - f / f1;
		f= cos(x) - x;
	} while (fabs(f)>=eps&&fabs(x-x1)>=eps);
	printf("x=%.6f\n",x);
	printf("f(x)=%.6f", fabs(cos(x) - x));
	return 0;
}
