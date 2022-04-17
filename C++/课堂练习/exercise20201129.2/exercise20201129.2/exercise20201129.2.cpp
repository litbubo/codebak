// exercise20201129.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#define M 10
using namespace std;

int main()
{
	int a[M] = {1,2,3,4,5,6,7,8,9,10};
	int q = 0, p = M - 1;
	int temp;
	for (int i = 0;i < M / 2;i++)
	{
			temp = a[p];
			a[p--] = a[q];
			a[q++] = temp;
	}
	for (int i = 0;i < 10;i++)
		cout << "   " << a[i];
    return 0;
}

