// 07_推荐使用auto的场景.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
using namespace std;

class T1
{
public:
    T1();
    ~T1();
    static int get()
    {
        return 10;
    }

private:

};

T1::T1()
{
}

T1::~T1()
{
}

class T2
{
public:
    T2();
    ~T2();
    static string get()
    {
        return "Hello";
    }

private:

};

T2::T2()
{
}

T2::~T2()
{
}

template<typename T>
void fun()
{
    auto ret = T::get();
    cout << ret << endl;
}

int main()
{
    map<int, string> mp;
    mp.insert(make_pair(1,"xlp"));
    mp.insert(make_pair(2, "cxl"));
    mp.insert(make_pair(3, "xhc"));
    map<int, string>::iterator it = mp.begin();
    for (; it != mp.end(); it++)
    {
        cout << "key:" << it->first << "    value:" << it->second << endl;
    }
    auto it2 = mp.begin();
    for (; it2 != mp.end(); it2++)
    {
        cout << "key:" << it2->first << "    value:" << it2->second << endl;
    }

    fun<T1>();
    fun<T2>();
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
