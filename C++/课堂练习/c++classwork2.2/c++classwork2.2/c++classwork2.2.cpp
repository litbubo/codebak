#include "stdafx.h"
#include <iostream>
using namespace std;

typedef struct student
{
	char name[10];
	int number;
}student;

int main()
{
	int n;
	student *p = new student[5];
	for (n = 0;n < 5;n++)
		cin >> p[n].name >> p[n].number;
	for (n = 0;n < 5;n++)
		cout << p[n].name << endl << p[n].number << endl;
	delete[] p;
	system("pause");
    return 0;
}

