#include<stdio.h>
int change(int x)
{	
    int m = 0;
	while(x > 0)
	{
		m = m * 10 + x % 10;
		x = x / 10;
	}
    return m;
}
int prime(int x)
{
	int i, t = 0;
	if (x == 1 || x == 0)
		return 0;
	else
	{
		for (i = 2; i < x; i++)
		{
			if (x % i == 0)
				t++;
		}
		if (t > 0)
			return 0;
		else
			return 1;
	}
}
int rev_prime(int m,int n,int x[])
{
    int i,num=0;
    for(i=m;i<=n;i++)
    {
        if(prime(change(i)))
        {
            x[num]=change(i);
            num++;
        }
    }
    return num;
}
int main()
{
    FILE *fp;
    int m,n,num,i;
    int x[100];
    scanf("%d%d",&m,&n);
    num=rev_prime(m,n,x);
    fp=fopen("out.txt","w");
    for(i=0;i<num;i++)
    fprintf(fp,"%d ",x[i]);
    fclose(fp);
    return 0;
}