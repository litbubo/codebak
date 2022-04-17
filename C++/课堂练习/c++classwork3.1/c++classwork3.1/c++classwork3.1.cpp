// c++classwork3.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Point
{
protected:
	double x, y;
public:
	Point(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}
	virtual double Area() = 0;
	virtual void ShowPoint() = 0;
};

class Circle :public Point
{
private:
	double radius;
public:
	Circle(double r = 0, double a = 0, double b = 0);
	double Area()
	{
		return 3.1416*radius*radius;
	}
	void ShowPoint()
	{
		cout << "位置是：（" << x << "," << y << "）。" << endl;
	}
};

Circle::Circle(double r, double a, double b) :Point(a, b)
{
	radius = r;
}

int main()
{
	Point *p;
	Circle c1(2,2,9);
	p = &c1;
	cout << "面积为：" << p->Area() << endl;
	p->ShowPoint();
	system("pause");
    return 0;
}

