// c++classwork1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void Setsize(int w=200, int h=100)
{
	cout << "The size is " << w << "*" << h << endl;
}


int main()
{
	int width, height;
	Setsize();
	cin >> width >> height;
	Setsize(width,height);
	system("pause");
    return 0;
}

