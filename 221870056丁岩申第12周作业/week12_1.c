#include<stdio.h>
#include<string.h>
int fun(char a[])
{
int i,j,n=0;
for(i=j=0;i<=strlen(a);i++)
	if(a[i]>'9'||a[i]<'0')
		a[j++]=a[i];
	else
		n++;
return n;
}
int main()
{
	int n=0;
	char a[100];
	gets(a);
	n=fun(a);
	printf("%d:",n);
	puts(a);
return 0;
}