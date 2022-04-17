// 49_使用weak_ptr解决shared_ptr管理的内存被重复析构的问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>

using namespace std;

class T:public enable_shared_from_this<T>
{
public:
	shared_ptr<T> get_sharedptr()
	{
		return shared_from_this();
	}
	~T()
	{
		cout << "distruct" << endl;
	}

private:

};

int main()
{
	T* t = new T;
	shared_ptr<T> sp(t);
	//shared_ptr<T> sp2(t);
	shared_ptr<T> sp2(sp);

	shared_ptr<T> ss = shared_ptr<T>(new T);
	shared_ptr<T> ss1 = ss->get_sharedptr();
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
