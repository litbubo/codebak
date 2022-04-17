// 04_deque.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void print(const deque<int>& d) 
{
    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void fun1()
{
    deque<int> d, d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    print(d1);
    d = d1;
    print(d);
    deque<int> d3(d.begin(), d.end());
    print(d3);
}

void fun2()
{
    deque<int> d, d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    print(d1);
    
    d.assign(d1.begin() + 1, d1.end());
    print(d); 
}

void fun3()
{
    deque<int> d;
    cout << boolalpha << d.empty() << endl;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    print(d);
    cout << d.size() << endl;
    d.resize(5);
    print(d);
    //d.resize(10);
    //print(d);
    d.resize(11, 7);
    print(d);
}

void fun4()
{
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    print(d);
    d.push_back(99);
    d.push_front(99);
    print(d);
    d.pop_back();
    d.pop_front();
    print(d);

    d.insert(d.begin() + 1, 88);
    print(d);
    d.insert(d.begin() + 1, 5, 99);
    print(d);
    d.clear();
    print(d);
}

void fun5()
{
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    print(d);
    cout << d[5] << endl;
    cout << d.at(6) << endl;
    cout << d.front() << endl;
    cout << d.back() << endl;
}

int main()
{
    //fun1();
    //fun2();
    //fun3();
    //fun4();
    fun5();
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
