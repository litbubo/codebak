// exercise20210117.1.cpp : �������̨Ӧ�ó������ڵ㡣
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

