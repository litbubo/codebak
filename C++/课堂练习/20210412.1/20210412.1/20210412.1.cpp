// 20210412.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdio.h"
main()
{
	int num;
	int i = 0;
	int a[10];
	int count = 0;
	scanf_s("%d", &num);
	while (num != 0)
	{
		count++;
		a[i] = num % 10;
		num /= 10;
		i++;
	}

	for (int temp = 0; temp < count; temp++)
	{
		printf("%d", a[temp]);
	}

}
