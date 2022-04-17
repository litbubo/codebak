// exercise20201204.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class String
{
	char *s;
	int l;
public:
	String()
	{
		l = 0;
		s = new char;
		s[0] = '\0';
	}
	String(char *p)
	{
		l = strlen(p);
		s = new char[l + 1];
		strcpy_s(s, l+1,p);
	}
	~String()
	{
		delete[]s;
	}
	void Show()
	{
		cout << s << endl;
	}
	String &operator = (String &str)
	{
		if (this == &str)
			return *this;
		delete[]s;
		l = str.l;
		s = new char[l + 1];
		strcpy_s(s, l + 1, str.s);
		return *this;
	}
};

int main()
{
	String s1("hello world");
	String s2("11111111");
	s1 = s2;
	s1.Show();
	return 0;
}