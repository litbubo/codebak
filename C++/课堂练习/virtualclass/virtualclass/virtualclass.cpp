
#include "stdafx.h"
#include <iostream>
using namespace std;

class Shape
{
protected:
	double x, y;
public:
	Shape(double a, double b)
	{
		x = a;
		y = b;
	}
	virtual double Area() = 0;
	virtual void Print() = 0;
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double r = 0, double a = 0, double b = 0);
	double Area();
	void Print();
};

Circle::Circle(double r, double a, double b) :Shape(a, b)
{
	radius = r;
}

double Circle::Area()
{
	return 3.1416 * radius * radius;
}

void Circle::Print()
{
	cout << "Circle Center = (" << x << "," << y << "),Radius = " << radius << endl;
}

class Rectangle :public Shape
{
private:
	double width, height;
public:
	Rectangle(double a = 0, double b = 0, double w = 0, double h = 0);
	double Area();
	void Print();
};

Rectangle::Rectangle(double a, double b, double w, double h):Shape (a,b)
{
	width = w;
	height = h;
}

double Rectangle::Area()
{
	return width * height;
}

void Rectangle::Print()
{
	cout << "Circle Position = (" << x << "," << y << "),Size = (" << width << "," << height << ")" << endl;
}

int main()
{
	Shape *ps1, *ps2;
	//Shape s1(5,10);
	Circle c1(10, 30, 15);
	Rectangle r1(20, 20, 100, 40);
	ps1 = &c1;
	ps2 = &r1;
	ps1->Print();
	cout << "Area = " << ps1->Area() << endl;
	ps2->Print();
	cout << "Area = " << ps2->Area() << endl;
	system("pause");
    return 0;
}