// 17_通过using定义基础类型和函数指针别名.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
using namespace std;
class Base
{
public:
    void test()
    {
        cout << "Base" << endl;
    }
};

class Child :public Base
{
public:
    void test()
    {
        cout << "Base" << endl;
    }
};

int mytest(int a, int b)
{
    return a + b;
}

typedef int (*fun)(int, int);
using fun2 = int (*)(int, int);

template<typename T>
struct MyMap
{
    typedef map<int, T> mapType;
};

template<typename T>
using mmap = map<int, T>;

template<typename U>
class Container
{
public:
    void print(U &u)
    {
        for (auto it = u.begin(); it != u.end(); it++)
        {
            cout << it->first << "   " << it->second << endl;
        }
    }

};


int main()
{
    Child c;
    c.Base::test();
    std::cout << "Hello World!\n";
    fun f = mytest;
    fun2 f2 = mytest;

    cout << (*f)(1, 2) << endl;
    cout << f2(2, 3) << endl;

    MyMap<int>::mapType mm1;
    mm1.insert(make_pair(1, 1));
    mm1.insert(make_pair(2, 2));
    mm1.insert(make_pair(3, 3));
    mm1.insert(make_pair(4, 4));
    Container<MyMap<int>::mapType> c1;
    c1.print(mm1);
    MyMap<double>::mapType mm2;
    mm2.insert(make_pair(1, 1.1));
    mm2.insert(make_pair(2, 2.2));
    mm2.insert(make_pair(3, 3.3));
    mm2.insert(make_pair(4, 4.4));
    Container<MyMap<double>::mapType> c2;
    c2.print(mm2);
    mmap<string> mm3;
    mm3.insert(make_pair(1, "xlp"));
    Container<mmap<string>> c3;
    c3.print(mm3);

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
