// exercise20201129.4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class String
{
	char *S;
public:
	String(char *p)
	{
		S = new char[strlen(p) + 1];
		strcpy_s(S, strlen(p) + 1,p);
	}
	String(const String &r)
	{
		S = new char[strlen(r.S) + 1];
		strcpy_s(S, strlen(r.S) + 1, r.S);
	}
	~String();
};
String::~String()
{
	delete []S;
}

int main()
{
	String S1("teacher");
	String S2(S1);
    return 0;
}

