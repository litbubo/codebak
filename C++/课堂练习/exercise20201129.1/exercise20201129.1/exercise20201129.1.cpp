// exercise20201129.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class X
{
private:
	int x;
public:
	X()
	{
		x = 0;
	}
	X(int x0 = 0)
	{
		x = x0;
	}
};


int main()
{
	X a(1);
	X a();
	//X a;
    return 0;
}

