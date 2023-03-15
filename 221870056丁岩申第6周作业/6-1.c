#include<stdio.h>
int main()
{
double a,b,c,d,e;
scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);
if(a>=b&&b>=c&&c>=d&&d>=e)
	printf("NO");
else
	printf("YES");
return 0;
}