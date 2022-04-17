// exercise20201117.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Date
{
public:
	int year, month, day;
	Date(int y, int m, int d);
	void Show();
};

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

void Date::Show()
{
	cout << year << month << day << endl;
}
int main()
{
	Date obj(2000, 11, 17);
	int *p;
	p = &obj.day;
	cout << *p << endl;
    return 0;
}

