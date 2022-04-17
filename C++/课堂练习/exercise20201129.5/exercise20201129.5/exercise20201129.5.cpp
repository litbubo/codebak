// exercise20201129.5.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Complex
{
	int real;
	int image;
public:
	Complex(int x = 0, int y = 0)
	{
		real = x;
		image = y;
		cout << "����" << endl;
	}
	void Print()
	{
		cout << real << "+" << image << "i" << endl;
	}
	friend Complex operator + (const Complex &, const Complex &);
	~Complex()
	{
		cout << "����" << endl;
	}
};

Complex operator +(const Complex &c1, const Complex &c2)
{
	Complex temp(c1.real + c2.real, c1.image + c2.image);
	return temp;
}


int main()
{
 	Complex a1(1, 5);
	Complex a2(3, 3);
	Complex a3;
	a3 = a1 + a2;
	a3.Print();
    return 0;
}

