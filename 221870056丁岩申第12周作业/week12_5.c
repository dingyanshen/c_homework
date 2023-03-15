#include<stdio.h>
int Union(int(*a)[6], int res[25])
{
    int i, j, m, flag, num = 0;
    for (i = 0; i < 5; i++)
        for (j = 1; j < *(*(a + i)) + 1; j++)
            res[num++] = *(*(a + i) + j);
    for (i = 1; i < num; i++)
    {
        flag = 0;
        for (j = 0; flag == 0 && j < i; j++)
            if (res[i] == res[j])
            {
                for (m = i; m < num - 1; m++)
                    res[m] = res[m + 1];
                num--;
                flag++;
            }
        if (flag > 0)
            i--;
    }
    return num;
}
int main()
{
    int sec[5][6] = { {4,12,35,3,9},{3,2,35,9},{5,35,12,0,1,9},{1,90},{2,9,0} }, res[25];
    int i, num;
    num = Union(sec, res);
    for (i = 0; i < num; i++)
        printf("%5d", res[i]);
    printf("\n");
    return 0;
}
