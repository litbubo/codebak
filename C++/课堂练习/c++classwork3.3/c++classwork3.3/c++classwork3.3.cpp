#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Undergraduate
{
protected:
	string number;
	string name;
	string profession;
public:
	Undergraduate(string n = "Default number.", string na="Default name", string pro = "Default profession");
	virtual void Show_Info() = 0;
};

Undergraduate::Undergraduate(string n, string na, string pro)
{
	number = n;
	name = na;
	profession = pro;
}

class Graduate :public Undergraduate
{
private:
	string teacher;
	int textnum;
public:
	Graduate(string t = "Default teacher.", int text = 0, string n = "Default number.", string na = "Default name", string pro = "Default profession");
	void Show_Info()
	{
		cout << "学号：" << number << endl << "名字：" << name << endl << "专业：" << profession << endl;
		cout << "教师：" << teacher << endl << "发表论文数：" << textnum << endl << endl;
	}
};

Graduate::Graduate(string t, int text, string n, string na, string pro) :Undergraduate(n,na,pro)
{
	teacher = t;
	textnum = text;

}

int main()
{
	Undergraduate *p;
	p = new Graduate("老师1", 20, "1903070311", "许连鹏", "电子信息科学与技术");
	p->Show_Info();
	delete p;
	system("pause");
	return 0;
}