// 08_list容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>

using namespace std;

void print(const list<int> &l)
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

bool mysort(int& x, int& y)
{
    return x > y;
}

void fun1()
{
    list<int> l,l2, l3;
    l.push_back(10);
    l.push_back(20);
    l.push_back(20);
    l.push_back(40);
    l.push_front(100);
    l.push_front(200);
    l.push_front(300);
    l.push_front(400);
    print(l);

    l2.assign(++l.begin(), l.end());
    print(l2);

    l3 = l2;
    print(l3);
}

void fun2()
{
    list<int> l{ 1,2,3,4,5 };
    list<int> l2{ 9,8,7,6,5 };
    print(l);
    print(l2);
    l.swap(l2);
    print(l);
    print(l2);
}


void fun3()
{
    list<int> l{ 1,2,3,4,5 };
    cout << l.size() << endl;
    l.resize(10);
    print(l);
    l.resize(15, 9);
    print(l);
}

void fun4()
{
    list<int> l{ 1,2,3,4,5,6,7,8,9,0,9,9,9,9,9,9,9,9,9,9,99 };
    print(l);
    l.pop_back();
    l.pop_front();
    print(l);
    l.insert(--l.end(), 88);
    l.insert(++l.begin(), 5, 88);
    print(l);
    l.erase(--l.end());
    print(l);
    l.remove(9);
    print(l);
}

void fun5()
{
    list<int> l{ 1,2,3,4,5,6,7,8,9};
    print(l);
    cout << l.front() << endl;
    cout << l.back() << endl;
}

void fun6()
{
    list<int> l{ 1,2,3,4,5,6,7,8,9 };
    print(l);
    l.reverse();
    print(l);
    l.clear();
    print(l);
    list<int> l2{ 5,6,7,5,5,8,2,4,3,7,0,1 };
    l2.sort(mysort);
    print(l2);
}


int main()
{
    //fun1();
    //fun2();
    //fun3();
    //fun4();
    //fun5();
    fun6();
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
