// exercise20201129.6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0)
	{
		x = a;y = b;
	}
	void Show()
	{
		cout << x << "," << y << endl;
	}
	friend Point operator -(const Point &);
	friend bool operator !(const Point &);
};

Point operator -(const Point &p)
{
	Point temp(-p.x, -p.y);
	return temp;
}

bool operator !(const Point &c)
{
	return (c.x == 0 && c.y == 0);
}
int main()
{
	Point a1(1, 1);
	Point a2(5, 4);
	Point a3;
	cout << boolalpha << !a3 << endl;
	a3 = -a1;
	a3.Show();
	a3 = -a2;
	a3.Show();
    return 0;
}

