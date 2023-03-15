#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main()
{
	initgraph(1000, 600);
	outtextxy(150, 100, _T("1.圆形"));
	outtextxy(150, 140, _T("2.矩形"));
	outtextxy(150, 180, _T("3.椭圆"));
	outtextxy(150, 220, _T("4.扇形"));
	outtextxy(150, 260, _T("0.退出"));
	char c=_getch();
	switch (c)
	{case '1':circle(650, 180, 100); break;
	case '2':rectangle(500, 100, 800, 260); break;
	case '3':ellipse(500, 100, 800, 260); break;
	case '4':pie(520, 130, 780, 390, 20, 40); break;
	case '0':closegraph(); break;}
	_getch();
	closegraph();
	return 0;
}