#include<stdio.h>
#define price 30
int main()
{
	double r,h,p,v,w;
	scanf("%lf %lf %lf", &r,&h,&p);
	v = h * r * r * 3.14159;
	printf("%lf\n", v);
	w = price * v * p;
	printf("%lf\n", w);
	return 0;
}