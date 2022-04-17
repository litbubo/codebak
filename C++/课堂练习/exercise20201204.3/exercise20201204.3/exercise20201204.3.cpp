// exercise20201204.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class String
{
	char *subf;
	int l;
public:
	char &operator[](int i)
	{
		if (i < 0 && i >= l)
			exit(1);
		return subf[i];
	}
};

int main()
{
    return 0;
}

