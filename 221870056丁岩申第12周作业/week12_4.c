#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int stoi(char *s,int *i)//wrong 1
{	   
	long n=0;
	while(isdigit(s[*i]))
	n=n*10+(s[(*i)++]-'0');//wrong 2
	return n;
}
long add(char *s)
{	
	int i=0,*pi;
	char op;	
	long a=0,b=0,c;
	pi=&i;//wrong 3
	a=stoi(s,pi);
	op=s[i++];
	b=stoi(s,pi);
	switch(op) {
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':if(b==0) {printf("div!0");exit(0);}//wrong 4
		         return a/b;
		default: printf("operator error!");exit(0);
	}
}
int main(void)
{	
	char s[80];
	gets(s);
	printf("%s=",s);
	printf("%ld\n",add(s));
	return 0;
}