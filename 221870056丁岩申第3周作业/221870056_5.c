#include<stdio.h>
int main()
{
	int x,a,b,c,d,y;
	printf("������һ����λ����");
scanf("%d", &x);
a = x % 10;
b = ((x - a) / 10) % 10;
c= (((x - a) / 10 - b) / 10) % 10;
d = ((((x - a) / 10 - b) / 10) - c) / 10;
y = a * 1000 + b * 100 + c * 10 + d;
	printf("����λ���ķ�����Ϊ��%d", y);
	return 0;
}
