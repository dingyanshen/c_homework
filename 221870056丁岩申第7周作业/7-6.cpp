#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int main()
{
	initgraph(700, 500);
	outtextxy(300, 100, _T("1.圆形"));
	outtextxy(300, 140, _T("2.矩形"));
	outtextxy(300, 180, _T("3.椭圆"));
	outtextxy(300, 220, _T("4.扇形"));
	outtextxy(300, 260, _T("0.退出"));
	char c = _getch();
	while (c != '0')
	{
		switch (c)
		{
		case '1':cleardevice(); circle(350, 180, 100); break;
		case '2':cleardevice(); rectangle(200, 100, 500, 260); break;
		case '3':cleardevice(); ellipse(200, 100, 500, 260); break;
		case '4':cleardevice(); pie(220, 130, 480, 390, 1, 3); break;
		}
		_getch();
		cleardevice();
		outtextxy(300, 100, _T("1.圆形"));
		outtextxy(300, 140, _T("2.矩形"));
		outtextxy(300, 180, _T("3.椭圆"));
		outtextxy(300, 220, _T("4.扇形"));
		outtextxy(300, 260, _T("0.退出"));
		c = _getch();
	}
	closegraph();
	return 0;
}