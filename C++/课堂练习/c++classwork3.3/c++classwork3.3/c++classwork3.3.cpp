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
		cout << "ѧ�ţ�" << number << endl << "���֣�" << name << endl << "רҵ��" << profession << endl;
		cout << "��ʦ��" << teacher << endl << "������������" << textnum << endl << endl;
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
	p = new Graduate("��ʦ1", 20, "1903070311", "������", "������Ϣ��ѧ�뼼��");
	p->Show_Info();
	delete p;
	system("pause");
	return 0;
}