// exercise20201204.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int i = 0, int j = 0)
	{
		x = i; y = j;
	}
	void Show()
	{
		cout << x << "," << y << endl;
	}
	Point operator ++()
	{
		++x;
		++y;
		return *this;
	}
	Point operator ++(int)
	{
		Point plot(x, y);
		x++;
		y++;
		return plot;
	}
};




int main()
{
	Point p1(1, 1);
	p1.Show();
	(p1++).Show();
	p1.Show();
	(++p1).Show();
	p1.Show();
	
    return 0;
}

