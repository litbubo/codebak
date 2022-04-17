#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void GotoXY(const int x, const int y)
{
	COORD position;
	position.X = 2 * x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
void ShowCursor(bool bshow)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = bshow;
	SetConsoleCursorInfo(handle, &CursorInfo);
}

int inputspeed(int x)
{
	cout << "请输入速度，按回车结束：" << endl;
	cin >> x;
	return x;
}

int inputposition(int x)
{
	cout << "请输入位置，按回车结束：" << endl;
	cin >> x;
	return x;
}

class Bus
{
private:
	int position0;
	int speed;
	int passengers;
	char color[50];
	char brand[50];
public:
	void SetX(int positionX)
	{
		position0 = positionX;
	}
	int GetX()
	{
		cout << "起始位置为  " << position0 << endl;
		return position0;
	}
	void SetSpeed(int speedX)
	{
		speed = speedX;
	}
	int GetSpeed()
	{
		cout << "速度设置为  " << speed << endl;
		return speed;
	}
	void SetPassengers(int passengersX)
	{
		passengers = passengersX;
	}
	int GetPassengers()
	{
		cout << "乘客数为  " << passengers << endl;
		return passengers;
	}
	void SetColor(char *ps1)
	{
		strcpy_s(color, ps1);
		cout << "颜色为  " << color << endl;
	}
	void SetBrand(char *ps)
	{
		strcpy_s(brand, ps);
		cout << "品牌为  " << brand << endl;
	}
	void Run()
	{
		position0++;
	}
	void Clear()
	{
		GotoXY(position0, 15);
		cout << "                           ";
		GotoXY(position0, 16);
		cout << "                           ";
		GotoXY(position0, 17);
		cout << "                           ";
		GotoXY(position0, 18);
		cout << "                           ";
		GotoXY(position0, 19);
		cout << "                           ";
		GotoXY(position0, 20);
		cout << "                           ";
	}
	void Show()
	{
		GotoXY(position0, 15);
		cout << "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂";
		GotoXY(position0, 16);
		cout << "▎                 ▎";
		GotoXY(position0, 17);
		cout << "▎  □□□□□□   ▎≦";
		GotoXY(position0, 18);
		cout << "▎                 ▎≦";
		GotoXY(position0, 19);
		cout << "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔";
		GotoXY(position0, 20);
		cout << "●●●           ●";
		GotoXY(position0, 21);
		cout << "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔";
	}

};

int main(int argc, char** argv)
{
	int i;
	int m = 0, n = 0, sleep = 0;
	m = inputposition(m);
	n = inputspeed(n);
	cout << endl;
	Bus b1;
	b1.SetX(m);
	b1.SetSpeed(n);
	b1.SetBrand("BWM");
	b1.SetColor("BLUE");
	b1.SetPassengers(100);

	b1.GetX();
	b1.GetPassengers();
	sleep = b1.GetSpeed();
	for (int i = 0;i<50;i++)
	{
		b1.Clear();
		b1.Run();
		b1.Show();
		Sleep(sleep);
		if (_kbhit())
		{
			fflush(stdin);
			int ch = _getch();
			if (ch == 32)
			{
				int c;
				c = _getch();
			}
		}
	}
	return 0;
}
