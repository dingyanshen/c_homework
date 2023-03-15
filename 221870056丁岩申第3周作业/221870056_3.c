#include<stdio.h>
int main()
{
	int a,b,c,v;
	printf("请输入长方体的长，宽，高(用逗号隔开)：");
		scanf("%d,%d,%d",&a,&b,&c);
		v = a * b * c;
	printf("该长方体的体积为：%d\n", v);
	return 0;
}
