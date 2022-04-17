// c++classwork3.2.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "����People�ࡣ" << endl;
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
		cout << "���֣�" << name << endl << "���䣺" << age << endl << "��ַ��" << add << endl;
		cout << "ѧԺ��" << college << endl << "�꼶��" << grade << endl << endl;
	}
	~Student()
	{
		cout << "����Student�ࡣ" << endl;
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
		cout << "���֣�" << name << endl << "���䣺" << age << endl << "��ַ��" << add << endl;
		cout << "רҵ��" << profession << endl << "���ʣ�" << money << endl << endl;
	}
	~Teacher()
	{
		cout << "����Teacher�ࡣ" << endl;
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
	p1 = new Student("��ϢԺ", 2, "������", 19, "12��¥");
	p1->ShowInfo();
	p2=new Teacher("C++",10000000,"��ʦ1",30,"����");
	p2->ShowInfo();
	pdefault = new Student;
	pdefault->ShowInfo();
	delete p1;
	delete p2;
	delete pdefault;
	system("pause");
    return 0;
}