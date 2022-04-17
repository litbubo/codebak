// 03_vector容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "   " ;
    }
    cout << endl;
}

void fun1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    print_vector(v1);
    vector<int> v2(v1);
    print_vector(v2);
    vector<int> v3(v1.begin(), v1.end());
    print_vector(v3);
    vector<int> v4(10, 500);
    print_vector(v4);
}

void fun2()
{
    vector<int> v;
    cout << boolalpha << v.empty() << endl; 
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << v.capacity() << endl << v.size() << endl;
    print_vector(v);
    v.resize(10);
    cout << v.capacity() << endl << v.size() << endl;
    print_vector(v);
}

void fun3()
{
    vector<int> v;
    cout << boolalpha << v.empty() << endl;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    print_vector(v);
    v.push_back(55);
    print_vector(v);
    v.pop_back();
    print_vector(v);
    v.insert(v.begin() + 5, 99);
    v.insert(v.begin(), 5, 88);
    print_vector(v);
    v.clear();
    print_vector(v);
}

void fun4()
{
    vector<int> v;
    cout << boolalpha << v.empty() << endl;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    print_vector(v);
    cout << v[9] << endl;
    cout << v.at(8) << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
}

void fun5()
{
    vector<int> v;
    cout << boolalpha << v.empty() << endl;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << v.capacity() << endl << v.size() << endl;
    //print_vector(v);
    v.resize(10);
    cout << v.capacity() << endl << v.size() << endl;
    print_vector(v);
    vector<int>(v).swap(v);
    cout << v.capacity() << endl << v.size() << endl;
}

void fun6()
{
    vector<int> v;
    cout << boolalpha << v.empty() << endl;
    v.reserve(100000);
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << v.capacity() << endl << v.size() << endl;
    //print_vector(v);
   
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
