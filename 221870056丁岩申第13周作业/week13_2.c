#include<stdio.h>
#include<string.h>
void count(char a[], char w[][10], int n, int b[])
{
    int i=0,j=0,m=0,judge=0,alp=0;
    for(m=0;m<n;m++)//w����n�����ʱ���
    {
        for(i=0;a[i]!='\0';)//a�ַ���ÿ���ַ�����
        {
            judge=0;
			alp=0;
            for(j=i;;)//j=i��ʼ���ʱ���
            {
                if(!(a[j]>='a'&&a[j]<='z')&&alp==0)//����������ķ���ĸ�ַ�
                {
                    j++;
                    judge--;
                    break;
                }
                else if(!(a[j]>='a'&&a[j]<='z')&&alp>0&&j-i==strlen(w[m]))//����ǵ��ʽ�β�ķ���ĸ�ַ� ��a�е��ʵȳ���w�е���
                {
                    j++;
                    break;
                }                
				else if(!(a[j]>='a'&&a[j]<='z')&&alp>0&&j-i!=strlen(w[m]))//����ǵ��ʽ�β�ķ���ĸ�ַ� ��a�е��ʲ��ȳ���w�е���
                {
                    j++;
                    judge--;
                    break;
                }
                if(j-i+1>strlen(w[m]))//���a�е��ʳ���w�е���
                {
                    j++;
                    judge--;
                    alp++;
                }
                else if(j-i+1<=strlen(w[m])&&a[j]!=w[m][j-i])//�����ͬ
                {
                    j++;
                    judge--;
                    alp++;
                }
                else if(j-i+1<=strlen(w[m])&&a[j]==w[m][j-i])//�����ͬ
                {
                    j++;
                    alp++;
                }
			}
			i=j;
            if(judge==0)//���ȫ����ͬ��a�е��ʵȳ���w�е���
            b[m]++;
        }
    }
}
int main() 
{
    char a[]="this is a book, that is an apple";
    char w[][10]={{"is"},{"that"}};
    int m=0,n=2;
    int b[2]={0};
    count(a,w,n,b);
    for(m=0;m<n;m++)
    printf("%s:%d  ",w[m],b[m]);
    return 0;
}
