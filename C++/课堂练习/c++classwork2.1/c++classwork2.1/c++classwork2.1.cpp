#include "stdafx.h"
#include <iostream>
using namespace std;

int Array[10] = {0,11,22,33,44,55,66,77,88,99};

int & Get(int i)
{
	int &x = Array[i];
	cout << "数组第" << i + 1 << "个元素为：  " << x << endl;
	return x;
}

int main()
{
	int n,m;
	while (true)
	{
		cout << "输入想要访问的元素下标：" << endl;
		cin >> n;
		if (n == 99)
		{
			cout << "已结束" << endl;
			break;
		}
		else if (n < 0 || n>9)
		{
			cout << "超过范围！" << endl;
			continue;
		}
		Get(n);
		cin >> m;
		Get(n) = m;
	}
	for (n = 0;n < 10;n++)
		cout << Array[n] << "  ";
	cout << endl;
	system("pause");
    return 0;
}