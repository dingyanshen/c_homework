#include<stdio.h>
int main()
{char x,y;
printf("Please input first character:");
scanf("%c",&x);
switch(x)
{  case 'M':printf("Monday");break;
   case 'm':printf("Monday");break;
   case 'W':printf("Wednesday");break;
   case 'w':printf("Wednesday");break;
   case 'F':printf("Friday");break;
   case 'f':printf("Friday");break;
   case 'T':{printf("Please input second character:");
			scanf(" %c",&y);
			if(y=='u')
			    printf("Tuesday\n");
			else if(y=='U')
		     	printf("Tuesday\n");
		    else if(y=='h')
		     	printf("Thursday\n");
			else if(y=='H')
		     	printf("Thursday\n");
			else printf("Illegal input£¡");	break;}
   case 't':{printf("Please input second character:");
			scanf(" %c",&y);
			if(y=='u')
			    printf("Tuesday\n");
			else if(y=='U')
		     	printf("Tuesday\n");
		    else if(y=='h')
		     	printf("Thursday\n");
			else if(y=='H')
		     	printf("Thursday\n");
			else printf("Illegal input£¡");	break;}
   case 'S':{printf("Please input second character:");
	   			scanf(" %c",&y);
			if(y=='a')
				printf("Saturday\n");
			else if(y=='A')
				printf("Saturday\n");
			else if(y=='u')
				printf("Sunday\n");
			else if(y=='U')
				printf("Sunday\n");
			else printf("Illegal input£¡");break;}
   case 's':{printf("Please input second character:");
	   			scanf(" %c",&y);
			if(y=='a')
				printf("Saturday\n");
			else if(y=='A')
				printf("Saturday\n");
			else if(y=='u')
				printf("Sunday\n");
			else if(y=='U')
				printf("Sunday\n");
			else printf("Illegal input£¡");break;}
   default:printf("Illegal input£¡");}
return 0;
}
