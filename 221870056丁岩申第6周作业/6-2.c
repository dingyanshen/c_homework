#include<stdio.h>
int main()
{
char a,b;
double x1,y1,z1,m1,x2,y2,z2,m2;
scanf("%c %lf %lf %lf",&a,&x1,&y1,&z1);
scanf(" %c %lf %lf %lf",&b,&x2,&y2,&z2);
m1=x1+y1+z1,m2=x2+y2+z2;
printf("\n***************************************************************\n");
printf("%3s%11s%13s%14s%7s%14s\n","NAME","MATH","PHYSICS","CHEMISTRY","SUM","AVERAGE");
printf("%3c%12.1lf%12.1lf%12.1lf%10.1lf%12.1lf\n",a,x1,y1,z1,m1,m1/3);
printf("%3c%12.1lf%12.1lf%12.1lf%10.1lf%12.1lf\n",b,x2,y2,z2,m2,m2/3);
printf("***************************************************************\n");
return 0;
}
