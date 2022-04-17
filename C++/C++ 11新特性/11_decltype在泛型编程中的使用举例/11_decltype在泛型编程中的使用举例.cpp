// 11_decltype在泛型编程中的使用举例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
using namespace std;

template<class T>
class Container
{
public:
	Container();
	~Container();

	void fun(T &t)
	{
		for (m_it = t.begin(); m_it != t.end(); m_it++)
		{
			cout << *m_it << "    ";
		}
	}

private:
	//T::iterator m_it;
	decltype(T().begin()) m_it;

};

template<class T>
Container<T>::Container()
{
}

template<class T>
Container<T>::~Container()
{
}



int main()
{
	list<int> l{ 1,2,3,4,5,6,7,8,9 };
	const list<int> l2{ 1,2,3,4,5,6,7,8,9 };
	Container<list<int>> obj;
	Container<const list<int>> obj2;
	obj.fun(l);
	obj2.fun(l2);
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
