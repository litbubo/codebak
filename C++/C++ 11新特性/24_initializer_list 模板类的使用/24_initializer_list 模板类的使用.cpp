// 24_initializer_list 模板类的使用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fun(std::initializer_list<int> ls)
{
    auto it = ls.begin();
    for (; it != ls.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

class MyClass
{
public:
    MyClass(initializer_list<string> list)
    {
        auto it = list.begin();
        for (; it != list.end(); it++)
        {
            cout << *it << endl;
            myvector.push_back(*it);
        }
    }
    vector<string> myvector;

};


int main()
{
    fun({ 1,2,3,4,5 });
    MyClass m({ "aaa","bbb","ccc" });
    for (auto it = m.myvector.begin(); it != m.myvector.end(); it++)
    {
        cout << *it << "*" << endl;
    }
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
