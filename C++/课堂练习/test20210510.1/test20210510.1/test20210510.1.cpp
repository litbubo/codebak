// test20210510.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
using namespace std;



int showH()
{
	cout << 6666;
	return 0;
}

int main()
{
	int(*fun0[5])();

	fun0[0] = &showH;

	fun0[0]();


    return 0;
}

