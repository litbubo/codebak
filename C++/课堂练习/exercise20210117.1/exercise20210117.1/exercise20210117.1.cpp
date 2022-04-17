// exercise20210117.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	char *p = "abcdefg";
	int count = 0;
	for (; *p; p++)
		count++;
	printf("%d", count);

	return 0;
}

