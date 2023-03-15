#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,e;
	double A, B, C, D, E;
	scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
	A = fabs(a);
	B = fabs(b);
	C = fabs(c);
	D = fabs(d);
	E = fabs(e);
	printf("           x           |x|\n");
	printf("%12f %12.2f\n", a, A);
	printf("%12f %12.2f\n", b, B);
	printf("%12f %12.2f\n", c, C);
	printf("%12f %12.2f\n", d, D);
	printf("%12f %12.2f\n", e, E);
	return 0;
}