#include<stdio.h>
#include<string.h>
int replace_str(char *s,char *t,char *g)
{
		int i,j,k,position=-1;
		char tempstr[80];
		for(i=0;s[i]!='\0';i++)
		{
			for(j=i,k=0;s[j]==t[k]&&t[k]!='\0';j++,k++);
			if(t[k]=='\0')
			{
				position=i;
				break;
			}
		}
		if(position==-1)
			return 0;
		k=strlen(t);
		strcpy(tempstr,s+position+k);
		s[position]='\0';
		strcat(s,g);
		strcat(s,tempstr);
		return 1;
}
int main()
{
	char s[100],t[20],g[20];
	int count=0,n=1;
	scanf("%s%s%s",s,t,g);
	for(;n!=0;)
	{
		n=replace_str(s,t,g);
		count=count+n;
	}
	puts(s);
	printf("count=%d\n",count);
return 0;
}