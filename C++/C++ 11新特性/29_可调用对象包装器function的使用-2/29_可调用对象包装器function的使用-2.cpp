// 29_可调用对象包装器function的使用-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <functional>

using namespace std;

using funptr = void (*)(int, string);

class MyClass
{
public:
    void operator() (string s)
    {
        cout << s << "仿函数" << endl;
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
    //int m_id;
private:

};

class A
{
public:
    A(const function<void(int, string)>& f):callback(f)
    {

    }
    void notify(int a, string s)
    {
        callback(a, s);
    }
private:
    function<void(int, string)> callback;
};


void test(int a, string s)
{
    cout << "test  " << a << s << endl;
}

int main()
{
    function<void(int, string)> f = test;
    function<void(int, string)> f2 = MyClass::world;
    MyClass m1;
    MyClass m2;
    function<void(string)> f3 = m1;
    function<void(int, string)> f4 = m2;
    f(1, "xlp");
    f2(2, "cxl");
    f3("cxl");
    f4(3, "xhc");

    A a(test);
    a.notify(6, "666");
    A aa(MyClass::world);
    aa.notify(7, "777");
    A aaa(m2);
    aaa.notify(8, "888");

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
