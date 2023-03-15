#include<stdio.h>
int main()
{
	int left;
	for (left = 4;; left = left + 4)
	{
		int leftpeach, monkey;
		leftpeach = left;
		for (monkey = 5; monkey > 1; monkey--)
		{
			int peach;
			peach = (leftpeach / 4) * 5 + 1;
			if (peach % 4 != 0)
				break;
			else 
				leftpeach = peach;
		}
		if (monkey == 1)
		{
			printf("%d", (leftpeach / 4) * 5 + 1);
			break;
		}
	}
	return 0;
}
