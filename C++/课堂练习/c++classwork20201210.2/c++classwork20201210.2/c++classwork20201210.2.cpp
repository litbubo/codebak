// c++classwork20201210.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define N 10
using namespace std;

template <typename T>T FindMin(T arry[], int num, int &pos)
{
	int i = 0;
	T y=arry[0];
	for (i = 0; i < num; i++)
		if (y >= arry[i])
		{
			y = arry[i];
			pos = i;
		}
	return y;
}

int main()
{
	int position;
	int a[N] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << FindMin(a, N, position) << endl;
	cout << position << endl;
	double b[N] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1 };
	cout << FindMin(b, N, position) << endl;
	cout << position << endl;
    return 0;
}

