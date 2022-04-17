// exercise20201128.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	}
	void Show()
	{
		cout << x << y;
	}
	int GetX()
	{
		return x;
	}
	friend int ppp(Point &p1, Point &p2);
};

int ppp(Point &p1, Point &p2)
{
	return (p1.x - p2.x)*(p1.y - p2.y);
}

int main()
{
	Point p1(1, 1), p2(2, 2);
	cout << ppp(p1,p2)<<endl;
    return 0;
}

