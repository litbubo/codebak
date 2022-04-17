#include "stdafx.h"
#include <iostream>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
public:
	void SetDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void ShowDate()
	{
		cout << year << "." << month << "." << day << endl;
	}
};
int main()
{
	Date date1, date2;
	cout << "date1 set and output:" << endl;
	date1.SetDate(2001, 2, 30);
	date1.ShowDate();
	cout << "date2 set and output:" << endl;
	date2.SetDate(2005, 10, 12);
	date2.ShowDate();
}
