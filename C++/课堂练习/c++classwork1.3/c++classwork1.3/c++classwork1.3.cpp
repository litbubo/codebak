#include "stdafx.h"
#include <iostream>
using namespace std;

inline int Rect(int cx, int cy)
{
	return cx*cy;
}

int main()
{
	int k = 1, sum = 0;
	for (;k <= 40;k++)
	{
		sum += Rect(k, 100);
	}
	cout << sum << endl;
	system("pause");
	return 0;
}