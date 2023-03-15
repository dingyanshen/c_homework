//�ν��� ������ �������
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void print(int i, int j, int c)//��(i,j)��ͼ 0(δ����) 1(��) 2(��)
{
	if (c == 1)
	{
		line(20 + 230 * j, 20 + 230 * i, 230 * (j + 1), 230 * (i + 1));
		line(20 + 230 * j, 230 * (i + 1), 230 * (j + 1), 20 + 230 * i);
	}
	else if (c == 2)
		circle(125 + 230 * j, 125 + 230 * i, 100);
}
void highlight(int i, int j, int c)//(i,j)������ʾ 0(δ����) 1(��) 2(��)
{
	solidrectangle(20 + 230 * j, 20 + 230 * i, 230 * (j + 1), 230 * (i + 1));
	setlinecolor(BLACK);
	print(i, j, c);
	setlinecolor(WHITE);
}
void recover(int i, int j, int c)//(i,j)�ָ��Ǹ�����ʾ 0(δ����) 1(��) 2(��)
{
	clearrectangle(20 + 230 * j, 20 + 230 * i, 230 * (j + 1), 230 * (i + 1));
	print(i, j, c);
}
void control(int* x, int* y, int* z, char cmd)//ͨ���������ҿ��Ƹı䵱ǰ����(i,j)λ��
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
void start()//��ʼ��
{
	cleardevice();
	settextcolor(YELLOW);
	settextstyle(40, 0, _T("��Բ"));
	outtextxy(480, 730, _T("��������Ϸ"));
	settextcolor(WHITE);
	settextstyle(18, 0, _T("����"));
	//����
	TCHAR s0[] = _T("[�����]��[WASD]����λ��  [�س���]ȷ��");
	outtextxy(20, 730, s0);
	//��ʾ
	int i;
	for (i = 0; i < 5; i++)
		rectangle(10 + i, 10 + i, 700 - i, 700 - i);
	//����
	line(240, 10, 240, 700);
	line(470, 10, 470, 700);
	line(10, 240, 700, 240);
	line(10, 470, 700, 470);
	//����
	solidrectangle(20, 20, 230, 230);
	highlight(0, 0, 1);
	TCHAR s1[] = _T("״̬���ֵ��������ˣ�");
	outtextxy(20, 760, s1);
	//��ʼλ��
}
int judge(int(*a)[3])//�ж��Ƿ��ʤ 0(ƽ��) 1(��) 2(��)
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
	settextstyle(60, 0, _T("��Բ"));
	outtextxy(210, 250, _T("��������Ϸ"));
	settextcolor(WHITE);
	rectangle(100, 100, 610, 600);
	settextstyle(25, 0, _T("����"));
	outtextxy(248, 360, _T("[�س���]��ʼ��Ϸ"));
	outtextxy(248, 390, _T("[ESC��] �˳���Ϸ"));
	settextstyle(18, 0, _T("����"));
	//����
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
	//��ʼ��
	for (turn = 0; turn < 9; turn++)
	{
		int n = 0;
		for (n = 0;; n++)
		{
			int k = (turn % 2) + 1;//1(��) 2(��)
			cmd = _getch();
			control(&i, &j, &c, cmd);//ͨ���������ҿ��Ƹı䵱ǰ����(i,j)λ��
			highlight(i, j, k);//������ʾ
			c = a[i][j];
			if (cmd == '\r' && c == 0)break;//���»س����Ҵ˴�δ����
		}
		if (turn % 2 == 0)
			c = a[i][j] = 1;
		else if (turn % 2 == 1)
			c = a[i][j] = 2;
		J = judge(a);
		//�ж���Ӯ J=0,1,2����ƽ,��,��
		if (J == 1)
		{
			ju = 1;
			break;
		}//��
		else if (J == 2)
		{
			ju = 2;
			break;
		}//��
		else if (turn % 2 == 0)//�é��ˣ�
		{
			if (turn < 9)//�������һ��
			{
				TCHAR s[] = _T("״̬���ֵ��������ˣ�");
				outtextxy(20, 760, s);
			}
		}
		else if (turn % 2 == 1)//�á��ˣ�
		{
			TCHAR s[] = _T("״̬���ֵ��������ˣ�");
			outtextxy(20, 760, s);
		}
	}
	clearrectangle(20 + 230 * j, 20 + 230 * i, 230 * (j + 1), 230 * (i + 1));
	if (ju != 0)
	setlinecolor(RED);
	print(i, j, c);
	//ȡ�����и�����ʾ
	settextcolor(0x00CCCC);
	outtextxy(20, 760, _T("[ESC��]�˳�  [�س���]���¿�ʼ"));
	settextcolor(0xFF69B4);
	settextstyle(40, 0, _T("��Բ"));
	if (ju == 1)
		outtextxy(480, 730, _T("   ��Ӯ�ˣ� "));
	else if (ju == 2)
		outtextxy(480, 730, _T("   ��Ӯ�ˣ� "));
	else if (ju == 0)
		outtextxy(480, 730, _T("    ����!   "));
	//��ʾ���
	char get;
	for (E = 0;; E++)
	{
		get = _getch();
		if (get == 27)
			break;
		else if (get == '\r')
			goto start;
	}
	//��ESC�˳�
end:;
}