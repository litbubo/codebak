// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
main()
{
	int num;
	int i = 0;
	int a[10];
	int count = 0;
	scanf("%d", &num);
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
