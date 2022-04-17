// c++classwork3.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class People
{
protected:
	string name;
	int age;
	string add;
public:
	People(string n = "Default name.", int a = 0, string ad = "Default add");
	virtual void ShowInfo() = 0;
	virtual ~People()
	{
		cout << "这是People类。" << endl;
	}
};

People::People(string n, int a, string ad)
{
	name = n;
	age = a;
	add = ad;
}

class Student :public People
{
private:
	string college;
	int grade;
public:
	Student(string col="Default college.", int g=0,string n = "Default name.", int a = 0, string ad = "Default add.");
	void ShowInfo()
	{
		cout << "名字：" << name << endl << "年龄：" << age << endl << "地址：" << add << endl;
		cout << "学院：" << college << endl << "年级：" << grade << endl << endl;
	}
	~Student()
	{
		cout << "这是Student类。" << endl;
	}
};

Student::Student(string col, int g, string n, int a, string ad):People(n,a,ad)
{
	college = col;
	grade = g;
}

class Teacher :public People
{
private:
	string profession;
	int money;
public:
	Teacher(string pro = "Default profession", int m = 0, string n = "Default name.", int a = 0, string ad = "Default add");
	void ShowInfo()
	{
		cout << "名字：" << name << endl << "年龄：" << age << endl << "地址：" << add << endl;
		cout << "专业：" << profession << endl << "工资：" << money << endl << endl;
	}
	~Teacher()
	{
		cout << "这是Teacher类。" << endl;
	}
};

Teacher::Teacher(string pro, int m, string n, int a, string ad):People(n,a,ad)
{
	profession = pro;
	money = m;
}

int main()
{
	People *p1, *p2, *pdefault;
	p1 = new Student("信息院", 2, "许连鹏", 19, "12号楼");
	p1->ShowInfo();
	p2=new Teacher("C++",10000000,"老师1",30,"沈阳");
	p2->ShowInfo();
	pdefault = new Student;
	pdefault->ShowInfo();
	delete p1;
	delete p2;
	delete pdefault;
	system("pause");
    return 0;
}