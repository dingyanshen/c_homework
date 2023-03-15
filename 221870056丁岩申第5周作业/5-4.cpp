#include <stdio.h>
#include <graphics.h>	
#include <conio.h>
	int main()
	{
		int el, et, er, eb, rl, rt, rr, rb, pl, pt, pr, pb, ps, pe;
		initgraph(1024, 768);
		printf("rectangle:");
		scanf("%d %d %d %d", &rl, &rt, &rr, &rb);
		rectangle(rl, rt, rr, rb);
		_getch();
		printf("pie:");
		scanf("%d %d %d %d %d %d", &pl, &pt, &pr, &pb, &ps, &pe);
		pie(pl, pt, pr, pb, ps, pe);
		_getch();
		printf("ellipse:");
		scanf("%d %d %d %d", &el, &et, &er, &eb);
		ellipse(el, et, er, eb);
		_getch();
		closegraph();
		return 0;
	}