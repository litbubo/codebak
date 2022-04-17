// xiaoche.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

//定位光标位置 
void GotoXY(const int x, const int y)
{
	COORD position;
	position.X = 2 * x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);//这个就是这样，记住格式就行
																		//设置红色文字 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
}
//显示或隐藏光标 
void ShowCursor(bool bshow)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = bshow; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}
//汽车类 
class Car
{
private:
	char style[50];
	int x;
	int y;
public:
	//设置X值 
	void SetX(int x1)
	{
		x = x1;
	}
	//得到X值 
	int GetX()
	{
		return x;
	}
	//设置型号 
	void SetStyle(char *ps)
	{
		strcpy_s(style, ps);
	}
	//行驶 
	void Run()
	{
		x++;
	}
	//清除当前光标下的车 
	void Clear()
	{
		GotoXY(x, 10);
		cout << "       ";
		GotoXY(x, 11);
		cout << "       ";
	}
	//显示车 
	void Show()
	{
		GotoXY(x, 10);
		cout << "▄██▄";
		GotoXY(x, 11);
		cout << " ◎  ◎";

	}

};

int main(int argc, char** argv)
{
	int i;
	//定义对象 
	Car c1;
	//调用成员函数 
	c1.SetStyle("Benz");
	c1.SetX(0);

	//循环控制运动	 
	for (i = 0;i<30;i++)
	{
		c1.Clear();		//旧的位置清除 
		c1.Run();		//车改变位置 
		c1.Show();		//新的位置绘制 

		Sleep(100);		//延时100毫秒 
	}

	return 0;
}
