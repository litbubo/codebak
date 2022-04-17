// 01_容器算法迭代器初识.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class T
{
public:
	T(int t)
	{
		num = t;
	}
	int num = 0;

private:

};



void print(int val)
{
	cout << val << endl;
}

void fun1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	for_each(v.begin(), v.end(), print);
	
}

void fun2()
{
	vector<T> v{ 1,2,3,4,5 };
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).num << "  " << it->num << endl;
	}
}

void fun3()
{
	vector<int> *v1 = new vector<int>;
	vector<int> *v2 = new vector<int>;
	vector<int> *v3 = new vector<int>;
	for (auto  i = 0; i < 10; i++)
	{
		(*v1).push_back(i);
		(*v2).push_back(i + 10);
		(*v3).push_back(i + 100);
	}
	vector<vector<int>> v{ *v1,*v2,*v3 };
	for (auto it = v.begin(); it !=v.end(); it++)
	{
		for (auto vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << "  ";
		}
		cout << endl;
	}
	delete v1, v2, v3;
}


int main()
{
	//fun1();
	//fun2();
	fun3();
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
