// 47_独占的智能指针unique_ptr的删除器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include <functional>

using namespace std;

class Test
{
public:
	Test() {}
	Test(int x) :num(x)
	{
		cout << "creat by " << num << endl;
	}
	Test(string s) :str(s)
	{
		cout << "creat by " << str << endl;
	}
	~Test()
	{
		cout << "distoried" << endl;
	}

	void print_num()
	{
		cout << "num = " << num << endl;
	}
	void set_num(int num)
	{
		this->num = num;
	}

private:
	int num;
	string str;
};

int main()
{
	unique_ptr<int> p(new int(10));
	unique_ptr<int> p2 = move(p);

	unique_ptr<Test> p3(new Test("xlpxlp"));
	p3.reset(new Test(99));
	auto pt = p3.get();
	pt->print_num();
	p3.reset();

	unique_ptr<Test, function<void(Test*)>> p4(new Test("hello"), [=](Test* t)
		{
			cout << "mydelte" << endl;
			delete t;
		});

	unique_ptr<Test[]> ptr(new Test[5]{ 1,2,3,4,5 });
	ptr.reset();

	shared_ptr<Test[]> ptr2(new Test[5]{ 6, 7, 8, 9, 10 });
	ptr2.reset();
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
