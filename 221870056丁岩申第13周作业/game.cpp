//何进飞 丁岩申 合作完成
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void print(int i, int j, int c)//在(i,j)绘图 0(未落子) 1(×) 2(〇)
{
	if (c == 1)
	{
		line(20 + 230 * j, 20 + 230 * i, 230 * (j + 1), 230 * (i + 1));
		line(20 + 230 * j, 230 * (i + 1), 230 * (j + 1), 20 + 230 * i);
	}
	else if (c == 2)
		circle(125 + 230 * j, 125 + 230 * i, 100);
}
void highlight(int i, int j, int c)//(i,j)高亮显示 0(未落子) 1(×) 2(〇)
{
	solidrectangle(20 + 230 * j, 20 + 230 * i, 230 * (j + 1), 230 * (i + 1));
	setlinecolor(BLACK);
	print(i, j, c);
	setlinecolor(WHITE);
}
void recover(int i, int j, int c)//(i,j)恢复非高亮显示 0(未落子) 1(×) 2(〇)
{
	clearrectangle(20 + 230 * j, 20 + 230 * i, 230 * (j + 1), 230 * (i + 1));
	print(i, j, c);
}
void control(int* x, int* y, int* z, char cmd)//通过上下左右控制改变当前坐标(i,j)位置
{
	int i = *x, j = *y, c = *z;
	recover(i, j, c);
	switch (cmd)
	{
	case 72:
	case 'w':
		i--;
		if (i < 0)
			i = 0;
		break;
	case 80:
	case 's':
		i++;
		if (i > 2)
			i = 2;
		break;
	case 75:
	case 'a':
		j--;
		if (j < 0)
			j = 0;
		break;
	case 77:
	case 'd':
		j++;
		if (j > 2)
			j = 2;
		break;
	}
	*x = i, * y = j, * z = c;
}
void start()//初始化
{
	cleardevice();
	settextcolor(YELLOW);
	settextstyle(40, 0, _T("幼圆"));
	outtextxy(480, 730, _T("井字棋游戏"));
	settextcolor(WHITE);
	settextstyle(18, 0, _T("宋体"));
	//字体
	TCHAR s0[] = _T("[方向键]或[WASD]控制位置  [回车键]确定");
	outtextxy(20, 730, s0);
	//提示
	int i;
	for (i = 0; i < 5; i++)
		rectangle(10 + i, 10 + i, 700 - i, 700 - i);
	//棋盘
	line(240, 10, 240, 700);
	line(470, 10, 470, 700);
	line(10, 240, 700, 240);
	line(10, 470, 700, 470);
	//井字
	solidrectangle(20, 20, 230, 230);
	highlight(0, 0, 1);
	TCHAR s1[] = _T("状态：轮到×落子了！");
	outtextxy(20, 760, s1);
	//初始位置
}
int judge(int(*a)[3])//判断是否获胜 0(平局) 1(×) 2(〇)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (a[i][1] == a[i][2] && a[i][1] == a[i][0] && a[i][1] != 0)
		{
			if (a[i][1] == 1)	
			{
				setlinecolor(RED);
				print(i, 0, 1);
				print(i, 1, 1);
				print(i, 2, 1);
				setlinecolor(WHITE);
				return 1;
			}
			else if (a[i][1] == 2)
			{
				setlinecolor(RED);
				print(i, 0, 2);
				print(i, 1, 2);
				print(i, 2, 2);
				setlinecolor(WHITE);
				return 2;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (a[1][i] == a[2][i] && a[1][i] == a[0][i] && a[1][i] != 0)
		{
			if (a[1][i] == 1)
			{
				setlinecolor(RED);
				print(0, i, 1);
				print(1, i, 1);
				print(2, i, 1);
				setlinecolor(WHITE);
				return 1;
			}
			else if (a[1][i] == 2)
			{
				setlinecolor(RED);
				print(0, i, 2);
				print(1, i, 2);
				print(2, i, 2);
				setlinecolor(WHITE);
				return 2;
			}
		}
	}
	if (a[1][1] == a[2][2] && a[1][1] == a[0][0] && a[1][1] != 0)
	{
		if (a[1][1] == 1)
		{
			setlinecolor(RED);
			print(0, 0, 1);
			print(1, 1, 1);
			print(2, 2, 1);				
			setlinecolor(WHITE);
			return 1;
		}
		else if (a[1][1] == 2)
		{
			setlinecolor(RED);
			print(0, 0, 2);
			print(1, 1, 2);
			print(2, 2, 2);				
			setlinecolor(WHITE);
			return 2;
		}
	}
	if (a[1][1] == a[2][0] && a[1][1] == a[0][2] && a[1][1] != 0)
	{
		if (a[1][1] == 1)
		{
			setlinecolor(RED);
			print(0, 2, 1);
			print(1, 1, 1);
			print(2, 0, 1);				
			setlinecolor(WHITE);
			return 1;
		}
		else if (a[1][1] == 2)
		{
			setlinecolor(RED);
			print(0, 2, 2);
			print(1, 1, 2);
			print(2, 0, 2);				
			setlinecolor(WHITE);
			return 2;
		}
	}
	else
		return 0;
}
int main()
{
start:
	int i = 0, j = 0, c = 0;
	int J = 0, ju = 0, turn = 0;
	int E = 0;
	int a[3][3] = { 0 };
	char cmd;
	initgraph(710, 800);
	settextcolor(YELLOW);
	settextstyle(60, 0, _T("幼圆"));
	outtextxy(210, 250, _T("井字棋游戏"));
	settextcolor(WHITE);
	rectangle(100, 100, 610, 600);
	settextstyle(25, 0, _T("宋体"));
	outtextxy(248, 360, _T("[回车键]开始游戏"));
	outtextxy(248, 390, _T("[ESC键] 退出游戏"));
	settextstyle(18, 0, _T("宋体"));
	//窗口
	int home;
	char ok;
	for (home = 0;; home++)
	{
		ok = _getch();
		if (ok == '\r')
			break;
		else if (ok == 27)
			goto end;
	}
	start();
	//初始化
	for (turn = 0; turn < 9; turn++)
	{
		int n = 0;
		for (n = 0;; n++)
		{
			int k = (turn % 2) + 1;//1(×) 2(〇)
			cmd = _getch();
			control(&i, &j, &c, cmd);//通过上下左右控制改变当前坐标(i,j)位置
			highlight(i, j, k);//高亮显示
			c = a[i][j];
			if (cmd == '\r' && c == 0)break;//按下回车键且此处未落子
		}
		if (turn % 2 == 0)
			c = a[i][j] = 1;
		else if (turn % 2 == 1)
			c = a[i][j] = 2;
		J = judge(a);
		//判断输赢 J=0,1,2代表平,×,〇
		if (J == 1)
		{
			ju = 1;
			break;
		}//×
		else if (J == 2)
		{
			ju = 2;
			break;
		}//〇
		else if (turn % 2 == 0)//该〇了！
		{
			if (turn < 9)//不是最后一子
			{
				TCHAR s[] = _T("状态：轮到〇落子了！");
				outtextxy(20, 760, s);
			}
		}
		else if (turn % 2 == 1)//该×了！
		{
			TCHAR s[] = _T("状态：轮到×落子了！");
			outtextxy(20, 760, s);
		}
	}
	clearrectangle(20 + 230 * j, 20 + 230 * i, 230 * (j + 1), 230 * (i + 1));
	if (ju != 0)
	setlinecolor(RED);
	print(i, j, c);
	//取消所有高亮显示
	settextcolor(0x00CCCC);
	outtextxy(20, 760, _T("[ESC键]退出  [回车键]重新开始"));
	settextcolor(0xFF69B4);
	settextstyle(40, 0, _T("幼圆"));
	if (ju == 1)
		outtextxy(480, 730, _T("   ×赢了！ "));
	else if (ju == 2)
		outtextxy(480, 730, _T("   〇赢了！ "));
	else if (ju == 0)
		outtextxy(480, 730, _T("    和棋!   "));
	//显示结果
	char get;
	for (E = 0;; E++)
	{
		get = _getch();
		if (get == 27)
			break;
		else if (get == '\r')
			goto start;
	}
	//按ESC退出
end:;
}