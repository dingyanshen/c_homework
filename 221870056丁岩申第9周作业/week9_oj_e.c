#include <stdio.h>
int print(int x)
{
	char ch;
	if (x < 10)
		ch = 48 + x;
	else if (x >= 10)
	{
		ch = 65 + x - 10;
	}
	return ch;
}
void f(int x, int n)
{
	int p;
	p = x % n;
	x = x / n;
	if (x < n&&x!=0)
		printf("%c", print(x));
	else if(x==0){;}
	else
		f(x, n);
		printf("%c", print(p));
}
int print(int x);
void f(int x, int n);
int main()
{
	int x, n, r=0, m=0;
	scanf("%d %d", &x, &n);
	if (x < 0)
	{
		printf("-");
		x=-x;
		f(x, n);
	}
	else
		f(x, n);
	return 0;
}
