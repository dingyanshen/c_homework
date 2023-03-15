#include<stdio.h>
int main()
{
	int x1, x2, x3, i;
	for (x1 = 100, i = 0; x1 < 1000; x1++)
		if (x1 % 37 == 0)
	  {
			x2 = (x1 - x1 % 10) / 10 + (x1 % 10) * 100;
			x3 = (x2 - x2 % 10) / 10 + (x2 % 10) * 100;
			if (x2 % 37 == 0 && x3 % 37 == 0)
			{
				printf("%5d", x1);
				i = i + 1;
				if (i % 5 == 0)
					printf("\n");
			}
			else
				printf("wrong");
	  }
	return 0;
 } 
