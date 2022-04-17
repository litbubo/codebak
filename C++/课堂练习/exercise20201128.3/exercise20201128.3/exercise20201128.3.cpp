// exercise20201128.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A;
class B
{
	int x;
public:
	B(int a) {
		x = a;
	}
	friend class A;
};

class A
{
public:
	void Print(B &b)
	{
		cout << b.x << endl;
	}
};


int main()
{
	B b(10);
	A a;
	a.Print(b);
    return 0;
}

