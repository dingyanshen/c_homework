#include<stdio.h>
int main()
{
	int x,a,b,c,d,y;
	printf("请输入一个四位数：");
scanf("%d", &x);
a = x % 10;
b = ((x - a) / 10) % 10;
c= (((x - a) / 10 - b) / 10) % 10;
d = ((((x - a) / 10 - b) / 10) - c) / 10;
y = a * 1000 + b * 100 + c * 10 + d;
	printf("该四位数的反序数为：%d", y);
	return 0;
}
