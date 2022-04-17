// exercise20201129.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Date
{
private:
	int year, month, day;
public:
	Date(int y = 2009, int m = 1, int d = 1);
	Date(const Date&);
	~Date()
	{
		cout << "销毁" << endl;
	}
	void ShowDate();
};

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	cout << "默认" << endl;
}

Date::Date(const Date &date1)
{
	year = date1.year;
	month = date1.month;
	day = date1.day;
	cout << "拷贝构造" << endl;
}

void Date::ShowDate()
{
	cout << year << month << day << endl;;
}

Date Fun(Date date2)
{
	Date date3(date2);
	return date3;
}

int main()
{
	Date obj1(1999, 3, 20);
	obj1.ShowDate();
	Date obj3;
	Date obj2(obj1);
	Date obj4 = obj2;
	obj3 = obj2;
	obj3 = Fun(obj2);
	obj2.ShowDate();
	obj3.ShowDate();
	return 0;
}