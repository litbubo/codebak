// xiaoche.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

//��λ���λ�� 
void GotoXY(const int x, const int y)
{
	COORD position;
	position.X = 2 * x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);//���������������ס��ʽ����
																		//���ú�ɫ���� 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
}
//��ʾ�����ع�� 
void ShowCursor(bool bshow)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = bshow; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
}
//������ 
class Car
{
private:
	char style[50];
	int x;
	int y;
public:
	//����Xֵ 
	void SetX(int x1)
	{
		x = x1;
	}
	//�õ�Xֵ 
	int GetX()
	{
		return x;
	}
	//�����ͺ� 
	void SetStyle(char *ps)
	{
		strcpy_s(style, ps);
	}
	//��ʻ 
	void Run()
	{
		x++;
	}
	//�����ǰ����µĳ� 
	void Clear()
	{
		GotoXY(x, 10);
		cout << "       ";
		GotoXY(x, 11);
		cout << "       ";
	}
	//��ʾ�� 
	void Show()
	{
		GotoXY(x, 10);
		cout << "�{�����{";
		GotoXY(x, 11);
		cout << " ��  ��";

	}

};

int main(int argc, char** argv)
{
	int i;
	//������� 
	Car c1;
	//���ó�Ա���� 
	c1.SetStyle("Benz");
	c1.SetX(0);

	//ѭ�������˶�	 
	for (i = 0;i<30;i++)
	{
		c1.Clear();		//�ɵ�λ����� 
		c1.Run();		//���ı�λ�� 
		c1.Show();		//�µ�λ�û��� 

		Sleep(100);		//��ʱ100���� 
	}

	return 0;
}
