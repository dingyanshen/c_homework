#include<stdio.h>
int* count(char* ch_p)
{
	static int num = 0;
	if (*ch_p >= 'A' && *ch_p <= 'Z')
		*ch_p = *ch_p + 'a' - 'A';
	printf("%c", *ch_p);
	if (*ch_p == 'a' || *ch_p == 'e' || *ch_p == 'i' || *ch_p == 'o' || *ch_p == 'u')
		num++;
	return &num;
}
int* count(char* ch_p);
int main()
{
	char ch;
	int* p = NULL;
	ch = getchar();
	while (ch != '\n')
	{
		p = count(&ch);
		ch = getchar();
	}
	if (p != NULL)
		printf(",\t%d\n", *p);
	else 
		printf(",\t0\n");
	return 0;
}