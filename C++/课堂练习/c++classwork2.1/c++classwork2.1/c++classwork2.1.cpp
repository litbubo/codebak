#include "stdafx.h"
#include <iostream>
using namespace std;

int Array[10] = {0,11,22,33,44,55,66,77,88,99};

int & Get(int i)
{
	int &x = Array[i];
	cout << "�����" << i + 1 << "��Ԫ��Ϊ��  " << x << endl;
	return x;
}

int main()
{
	int n,m;
	while (true)
	{
		cout << "������Ҫ���ʵ�Ԫ���±꣺" << endl;
		cin >> n;
		if (n == 99)
		{
			cout << "�ѽ���" << endl;
			break;
		}
		else if (n < 0 || n>9)
		{
			cout << "������Χ��" << endl;
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