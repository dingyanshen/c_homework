#include<stdio.h>
int main()
{unsigned long i;
printf("Please input Profit:");
scanf("%lu",&i);
printf("Reward:");
switch(i/100000)
{  case 0:printf("%.2lf",0.1*i);break;
   case 1:printf("%.2lf",10000+0.075*(i-100000));break;
   case 2:printf("%.2lf",17500+0.05*(i-200000));break;
   case 3:printf("%.2lf",17500+0.05*(i-200000));break;
   case 4:printf("%.2lf",27500+0.03*(i-400000));break;
   case 5:printf("%.2lf",27500+0.03*(i-400000));break;
   case 6:printf("%.2lf",33500+0.015*(i-600000));break;
   case 7:printf("%.2lf",33500+0.015*(i-600000));break;
   case 8:printf("%.2lf",33500+0.015*(i-600000));break;
   case 9:printf("%.2lf",33500+0.015*(i-600000));break;
   default:printf("%.2lf",39500+0.01*(i-1000000));}
return 0;
}
