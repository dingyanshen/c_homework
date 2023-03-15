#include<stdio.h>
int huiwen(long n)
{
	long t1, t2, t3, t4;
	if (n < 10)
		return 1;
	else if (n >= 10 && n < 100)
	{
		if (n % 11 == 0)
			return 1;
		else
			return 0;
	}
	else if (n >= 100 && n < 1000)
	{
		t1 = n % 10; t2 = n / 100;
		if (t1 == t2)
			return 1;
		else
			return 0;
	}
	else if (n >= 1000 && n < 10000)
	{
		t1 = n % 10; t2 = n / 1000;
		t3 = ((n - t1) / 10) % 10;
		t4 = (n - t2 * 1000) / 100;
		if (t1 == t2 && t3 == t4)
			return 1;
		else
			return 0;
	}
	else if (n >= 10000)
	{
		t1 = n % 10; t2 = n / 10000;
		t3 = ((n - t1) / 10) % 10;
		t4 = (n - t2 * 10000) / 1000;
		if (t1 == t2 && t3 == t4)
			return 1;
		else
			return 0;
	}
}

int huiwen(long n);
int main()
{
	int x;

	for (x = 1; x < 300; x++)
	{
		if (huiwen(x) == 1 && huiwen(x * x) == 1)
			printf("%d\n", x);
	}
	return 0;
}