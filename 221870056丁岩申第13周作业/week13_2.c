#include<stdio.h>
#include<string.h>
void count(char a[], char w[][10], int n, int b[])
{
    int i=0,j=0,m=0,judge=0,alp=0;
    for(m=0;m<n;m++)//w数组n个单词遍历
    {
        for(i=0;a[i]!='\0';)//a字符串每个字符遍历
        {
            judge=0;
			alp=0;
            for(j=i;;)//j=i开始单词遍历
            {
                if(!(a[j]>='a'&&a[j]<='z')&&alp==0)//如果是连续的非字母字符
                {
                    j++;
                    judge--;
                    break;
                }
                else if(!(a[j]>='a'&&a[j]<='z')&&alp>0&&j-i==strlen(w[m]))//如果是单词结尾的非字母字符 且a中单词等长于w中单词
                {
                    j++;
                    break;
                }                
				else if(!(a[j]>='a'&&a[j]<='z')&&alp>0&&j-i!=strlen(w[m]))//如果是单词结尾的非字母字符 且a中单词不等长于w中单词
                {
                    j++;
                    judge--;
                    break;
                }
                if(j-i+1>strlen(w[m]))//如果a中单词长于w中单词
                {
                    j++;
                    judge--;
                    alp++;
                }
                else if(j-i+1<=strlen(w[m])&&a[j]!=w[m][j-i])//如果不同
                {
                    j++;
                    judge--;
                    alp++;
                }
                else if(j-i+1<=strlen(w[m])&&a[j]==w[m][j-i])//如果相同
                {
                    j++;
                    alp++;
                }
			}
			i=j;
            if(judge==0)//如果全部相同且a中单词等长于w中单词
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
