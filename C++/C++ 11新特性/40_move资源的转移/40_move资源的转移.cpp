// 40_move资源的转移.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
using namespace std;

class T
{
public:
	T() :num(new int(100))
	{
		printf("create: %p\n", num);
	}
	T(const T& t) :num(new int)
	{
		*this->num = *t.num;
		printf("copy: %p\n", this->num);
	}
	T(T&& t) :num(t.num)
	{
		printf("move: %p\n", this->num);
		t.num = nullptr;
	}
	~T()
	{
		delete num;
		cout << "distroy" << endl;
	}
	int* num = nullptr;
};

T fun()
{
	T t;
	return t;
}

T fun2()
{
	return T();
}

T&& fun3()
{
	return T();
}



int main()
{
	T t = fun();
	cout << "num = " << *t.num << endl;
	cout << "num_addres = " << t.num << endl;
	cout << endl;

	T&& t2 = fun2();
	cout << "num = " << *t2.num << endl;
	cout << "num_addres = " << t2.num << endl;
	cout << endl;

	T&& t3 = move(t);
	cout << "num = " << *t.num << endl;
	cout << "num_addres = " << t.num << endl;
	cout << "num = " << *t3.num << endl;
	cout << "num_addres = " << t3.num << endl;
	T&& t4 = move(t2);
	cout << "num = " << *t2.num << endl;
	cout << "num_addres = " << t2.num << endl;
	cout << "num = " << *t4.num << endl;
	cout << "num_addres = " << t4.num << endl;

	list<string> l1{ "qqq","www","eee","rrr" };
	list<string> l2 = l1;
	list<string> l3 = move(l1);


	/*T&& t3 = fun3();
	cout << "num = " << *t3.num << endl;
	cout << "num_addres = " << t3.num << endl;
	T&& t = fun();
	std::cout << "Hello World!\n";*/
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
