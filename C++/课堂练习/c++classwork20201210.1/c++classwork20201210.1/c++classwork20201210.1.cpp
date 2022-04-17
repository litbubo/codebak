// c++classwork20201210.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

class Vector
{
	double x, y;
public:
	Vector();
	Vector(double a, double b);
	friend Vector operator + (const Vector &,const Vector &);
	Vector operator - (const Vector &);
	double Length(const Vector &);
	Vector operator ++ ();
	void Print();
	~Vector(){	cout << "Destruct the Vector!" << endl;	}
};

Vector::Vector() :x(0), y(0)
{

}

Vector::Vector(double a, double b)
{
	x = a;y = b;
}

Vector Vector::operator - (const Vector &v)
{
	Vector temp(x - v.x, y - v.y);
	return temp;
}

double Vector::Length(const Vector &v)
{
	double l;
	return sqrt((x - v.x)*(x - v.x + (y - v.y)*(y - v.y)));
}

Vector Vector::operator++ ()
{
	++x;
	++y;
	return *this;
}

void Vector::Print()
{
	cout << "(" << x << "," << y << ")" << endl;
}

Vector operator + (const Vector &a, const Vector &b)
{
	Vector temp(a.x+b.x,a.y+b.y);
	return temp;
}


int main()
{
	Vector v1(1,1);
	Vector v2(1, 2);
	Vector v3;
	v3 = v2 + v1;
	v3.Print();
	++v3;
	v3.Print();
	v3 = v2 - v1;
	v3.Print();
	cout << v3.Length(v1) << endl;

    return 0;
}

