// 27_可调用对象.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

using funptr = void (*)(int, string);

void fun(int a, string s)
{
    cout << a << "  " << s << endl;
}

class MyClass
{
public:
    void operator() (string s)
    {
        cout << s << endl;
    }

    operator funptr()
    {
        return world;
    }

    void hello(int a, string s)
    {
        cout << a << "  " << s << "hello" << endl;
    }

    static void world(int a, string s)
    {
        cout << a << "  " << s << "world" << endl;
    }
    int m_id;
private:

};




int main()
{
    funptr f = fun;
    f(1, "hello");
    MyClass m;
    m("hello");

    MyClass m2;
    m2(2, "xlp");

    funptr f2 = MyClass::world;
    using funptr2 = void(MyClass::*)(int, string);
    funptr2 f3 = &MyClass::hello;
    using ptr = int MyClass::*;
    ptr p = &MyClass::m_id;

    MyClass m3;
    (m3.*f3)(3, "xlp");
    m3.*p = 10;
    cout << m3.m_id << endl;


    //std::cout << "Hello World!\n";
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
