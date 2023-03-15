#include<stdio.h>
#include<string.h>
typedef struct
{
	long id;//学号
    char name[10];//姓名
    char sex[2];//性别（m代表男，f代表女）
}PS;
int delete(PS *p1,int m,PS *p2,int n)
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p1[i].id==p2[j].id)
			{
				for(k=i;k<m-1;k++) p1[k]=p1[k+1];
				m--;
				break;
			}
		}
	}
	return m;
}
int merge(PS *p1,int m,PS *p2,int n)
{
	int i,j,k;
	for(j=0;j<n;j++)
	{
		if(p1[0].id>p2[j].id)
		{
			for(k=m;k>0;k--) p1[k]=p1[k-1];
			m++;
			p1[0]=p2[j];
		}
		else if(p1[m-1].id<p2[j].id)
		{
			m++;
			p1[m-1]=p2[j];
		}
		else
		for(i=0;i<m-1;i++)
		{
			if(p1[i].id<p2[j].id&&p1[i+1].id>p2[j].id)
			{
				for(k=m;k>i+1;k--) p1[k]=p1[k-1];
				m++;
				p1[i+1]=p2[j];
				break; 
			}
		}
	}
	return m;
}
void sort(PS *p,int n)
{
	int i,j;
	PS k;
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n-1-i;j++)
		{
			if(strcmp(p[j].sex,p[j+1].sex)>0)
			{
				k=p[j];
		        p[j]=p[j+1];
		        p[j+1]=k;
		    }
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n-1-i;j++)
		{
			if(strcmp(p[j].sex,p[j+1].sex)==0&&strcmp(p[j].name,p[j+1].name)>0)
			{
				 k=p[j];
		         p[j]=p[j+1];
		         p[j+1]=k;
		    }
		}
	}
}
void display(PS *p,int n)
{
	int i;
	printf("%3s%8s%6s\n","ID","NAME","SEX");
	for(i=0;i<n;i++)
	{
		printf("%3ld%8s%6s\n",p[i].id,p[i].name,p[i].sex);
	}
}
int main()
{
	int a0=5,b0=2;
	PS a[100]={{101, "tom","m"},{103,"mary","f"},{104,"mark","m"},{105,"julia","f"},{106, "sara","f"}};
	PS b[100]={{102, "mark","m"},{104,"mark","m"}};
	printf("a:\n"),display(a,a0);
	printf("b:\n"),display(b,b0);
	a0=delete(a,a0,b,b0);
	printf("a:\n"),display(a,a0);
	b0=merge(b,b0,a,a0);
	printf("b:\n"),display(b,b0);
	sort(a,a0);
	printf("a:\n"),display(a,a0);
	return 0;
}