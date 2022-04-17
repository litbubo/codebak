// exercise2020128.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class B;
class A
{
	int a, b;
public:
	A(int x, int y)
	{
		a = x;b = y;
	}
	void Print()
	{
		cout << a << b << endl;
	}
	void Setab(B &obj);
};

class B
{
	friend void A::Setab(B &obj);
	int c, d;
public:
	B(int x, int y)
	{
		c = x;
		d = y;
	}
	void Print()
	{
		cout << c << d << endl;
	}
};

void A::Setab(B &obj)
{
	a = obj.c;
	b = obj.d;
	obj.c++;
	obj.d++;
}
int main()
{
	A a(1,1);
	B b(2, 2);
	a.Print();
	b.Print();
	a.Setab(b);
	a.Print();
	b.Print();
    return 0;
}

