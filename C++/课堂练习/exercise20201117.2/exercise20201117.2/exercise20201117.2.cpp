// exercise20201117.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void Print()
	{
		cout << "Base Class Print." << endl;
	}
};

class Derived1 :public Base
{
public:
	void Print()
	{
		cout << "Derived1 Class Print." << endl;
	}
};

class Derived2 :public Base
{
	void Print()
	{
		cout << "Derived2 Class Print." << endl;
	}
};

int main()
{
	Base b1, *pd;
	Derived1 d1;
	Derived2 d2;
	Base &rb1 = b1;
	pd = &b1;
	pd->Print();
	rb1.Print();
	pd = &d1;
	pd->Print();
	pd = &d2;
	pd->Print();
	Base &rb2 = d1;
	rb2.Print();
    return 0;
}

