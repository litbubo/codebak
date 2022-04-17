// c++classwork202012.03.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class base
{
public:
	virtual void print()
	{
		cout << "base class print" << endl;
	}
	virtual void Test()
	{
		cout << "Base Test." << endl;
	}
};
class derived1 :public base
{
	void print()
	{
		cout << "derived1 class print" << endl;
	}
	void Test()
	{
		cout << "Derived Test." << endl;
	}
};
class derived2 :public base
{
	void print()
	{
		cout << "derived2 class print" << endl;
	}
	void Test()
	{
		cout << "Derived Test." << endl;
	}
};
int main()
{
	base b1, *pb, b2, *pb2;
	derived1 d1;
	derived2 d2;
	base& rb1 = b1;
	rb1.print();
	rb1.Test();
	pb = &b1;
	pb->print();
	pb = &d1;
	pb->print();
	pb->Test();
	base& rb2 = d1;
	rb2.print();
	rb2.Test();
	return 0;
}


