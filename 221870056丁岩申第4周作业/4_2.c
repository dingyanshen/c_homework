#include<stdio.h>
int main()
{
	double a = 100.453627;
	double x, y, z, w;
	int X, Y, Z, W;
	double m, n, p, q;

	x = a * 10;
	X = x + 0.5;
	m = (double)X / (double)10;


	y = a * 100;
	Y = y+ 0.5;
	n = (double)Y / (double)100;


	z = a * 1000;
	Z = z + 0.5;
	p = (double)Z / (double)1000;


	w = a * 10000;
	W = w + 0.5;
	q = (double)W / (double)10000;

	printf("%lf\n", m);
	printf("%lf\n", n); 
	printf("%lf\n", p); 
	printf("%lf\n", q);
	return 0;
}