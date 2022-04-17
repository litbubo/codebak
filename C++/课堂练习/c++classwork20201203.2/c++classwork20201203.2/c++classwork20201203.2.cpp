// c++classwork20201203.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Container
{
protected:
	double radius;
public:
	Container(double r)
	{
		radius = r;
	}
	virtual double surface_area()=0;
	virtual double volume() = 0;
};

class Ball:public Container
{
	double S,V;
public:
	Ball(double r=0);
	double surface_area()
	{
		S = 4 * 3.14 * radius * radius;
		return S;
	}
	double volume()
	{
		V = 4 * 3.14 * radius * radius * radius / 3;
		return V;
	}
};
Ball::Ball(double r):Container(r) {}

class Square:public Container
{
	double S,V;
public:
	Square(double r=0);
	double surface_area()
	{
		S = 6 * radius * radius;
		return S;
	}
	double volume()
	{
		V = radius * radius * radius;
		return V;
	}
};
Square::Square(double r):Container(r) {}

class Cylinder :public Container
{
	double height;
	double V, S;
public:
	Cylinder(double h = 0, double r = 0);
	double surface_area()
	{
		S = 3.14 * 2 * radius * (height + radius);
		return S;
	}
	double volume()
	{
		V = 3.14 * radius * radius * height;
		return V;
	}
};

Cylinder::Cylinder(double h, double r):Container(r)
{
	height = h;
}


int main()
{
	Container *c1, *c2, *c3;
	Ball b1(2);
	Square s1(2);
	Cylinder cy1(1, 2);
	c1 = &b1;
	cout << c1->surface_area() << endl;
	cout << c1->volume() << endl;
	c2 = &s1;
	cout << c2->surface_area() << endl;
	cout << c2->volume() << endl;
	c3 = &cy1;
	cout << c3->surface_area() << endl;
	cout << c3->volume() << endl;
	
	return 0;
}