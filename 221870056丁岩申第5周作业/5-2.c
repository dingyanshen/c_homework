#include<stdio.h>
int main()
{
	int a, b, c, d;
	int x, y, z, w, m, n;
	printf("Please input complex number one\n");
	printf("realpart:");
	scanf("%d", &a);
	printf("imagpart:");
	scanf("%d", &b);
	printf("Please input complex number two\n");
	printf("realpart:");
	scanf("%d", &c);
	printf("imagpart:");
	scanf("%d", &d);
	x = a + c, y = b + d;
	z = a - c, w = b - d;
	m = a * c - b * d, n = a * d + b * c;
	printf("(%d+%di)+(%d+%di)=%d+%di\n", a, b, c, d, x, y);
	printf("(%d+%di)-(%d+%di)=%d+%di\n", a, b, c, d, z, w);
	printf("(%d+%di)*(%d+%di)=%d+%di\n", a, b, c, d, m, n);
	return 0;
}