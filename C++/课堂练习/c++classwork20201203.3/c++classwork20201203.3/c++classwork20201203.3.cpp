// c++classwork20201203.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Cshape
{
public:
	virtual void DispAttr() = 0;
	virtual double Sarea() = 0;
	virtual double Volume() = 0;
};

class Ball :public Cshape
{
	double S, V;
	double radius;
public:
	Ball(double r = 0)
	{
		radius = r;
	}
	double Sarea()
	{
		S = 4 * 3.14 * radius * radius;
		return S;
	}
	double Volume()
	{
		V = 4 * 3.14 * radius * radius * radius / 3;
		return V;
	}
	void DispAttr()
	{
		cout << "半径为："<< radius << endl;
	}
};

class Square :public Cshape
{
	double S, V;
	double radius;
public:
	Square(double r = 0)
	{
		radius = r;
	}
	double Sarea()
	{
		S = 4 * 3.14 * radius * radius;
		return S;
	}
	double Volume()
	{
		V = 4 * 3.14 * radius * radius * radius / 3;
		return V;
	}
	void DispAttr()
	{
		cout << "边长为：" << radius << endl;
	}
};

class Cylinder :public Cshape
{
	double S, V;
	double radius,height;
public:
	Cylinder(double r = 0,double h = 0)
	{
		radius = r;
		height = h;
	}
	double Sarea()
	{
		S = 3.14 * 2 * radius * (height + radius);
		return S;
	}
	double Volume()
	{
		V = 3.14 * radius * radius * height;
		return V;
	}
	void DispAttr()
	{
		cout << "边长为：" << radius << endl;
	}
};

int main()
{
	Cshape *c1, *c2, *c3;
	Ball b1(2);
	Square s1(2);
	Cylinder cy1(1, 2);
	c1 = &b1;
	cout << c1->Sarea() << endl;
	cout << c1->Volume() << endl;
	c2 = &s1;
	cout << c2->Sarea() << endl;
	cout << c2->Volume() << endl;
	c3 = &cy1;
	cout << c3->Sarea() << endl;
	cout << c3->Volume() << endl;
    return 0;
}

