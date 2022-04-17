// 44_共享智能指针shared_ptr的使用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include<memory>

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
	shared_ptr<int> p1(new int(20));
	cout << "p1 use_count: " << p1.use_count() << endl;
	shared_ptr<int> p2 = move(p1);
	cout << "p1 use_count: " << p1.use_count() << endl;
	cout << "p2 use_count: " << p2.use_count() << endl;
	shared_ptr<int> p3 = p2;
	cout << "p1 use_count: " << p1.use_count() << endl;
	cout << "p2 use_count: " << p2.use_count() << endl;
	cout << "p3 use_count: " << p3.use_count() << endl;

	shared_ptr<Test> ptr(new Test("hello"));
	cout << "ptr use_count: " << ptr.use_count() << endl;
	shared_ptr<Test> ptr2 = ptr;
	cout << "ptr use_count: " << ptr.use_count() << endl;
	cout << "ptr2 use_count: " << ptr2.use_count() << endl;
	shared_ptr<Test> ptr3 = move(ptr);
	cout << "ptr use_count: " << ptr.use_count() << endl;
	cout << "ptr2 use_count: " << ptr2.use_count() << endl;
	cout << "ptr3 use_count: " << ptr3.use_count() << endl;
	ptr3.reset();
	cout << "ptr use_count: " << ptr.use_count() << endl;
	cout << "ptr2 use_count: " << ptr2.use_count() << endl;
	cout << "ptr3 use_count: " << ptr3.use_count() << endl;
	ptr2.reset();

	shared_ptr<Test> ptr4(new Test(520));
	//ptr4.reset();

	std::cout << "Hello World!\n";

	auto t = ptr4.get();
	t->set_num(66);
	t->print_num();

	ptr4->set_num(77);
	ptr4->print_num();

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
