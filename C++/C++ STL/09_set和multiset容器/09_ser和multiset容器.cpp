// 09_ser和multiset容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>
#include <string>
using namespace std;

//
//void print(const multiset<int>& s)
//{
//    for (auto it = s.begin(); it != s.end(); it++)
//    {
//        cout << *it << "  ";
//    }
//    cout << endl;
//}

class Person
{
public:
    Person(string s, int age) :name(s), age(age)
    {}
    int age;
    string name;
};

class myCompare
{
public:
    bool operator()(const int& x, const int& y) const
    {
        return x > y;
    }
    bool operator()(const Person& x, const Person& y) const
    {
        return x.age < y.age;
    }
};

template<typename T>
void print(T& s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

void print(set<Person, myCompare>& s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << it->name << "  " << it->age << endl;;
    }
    cout << endl;
}


void fun1()
{
    set<int> s, s2, s3;
    s.insert(1);
    s.insert(3);
    s.insert(6);
    s.insert(4);
    s.insert(2);
    print(s);
    s2 = s;
    s2.insert(9);
    print(s2);
    cout << "s size : " << s.size() << endl;
    s.swap(s2);
    print(s);
    print(s2);
}


void fun2()
{
    set<int> s{ 1,4,5,6,7,8,3,2 };
    print(s);
    s.erase(8);
    print(s);
    s.erase(++s.begin());
    print(s);
    s.clear();
    print(s);
}

void fun3()
{
    multiset<int> s{ 1,4,5,6,7,8,3,2,2,5,8,4,5,4,5,7,7, };
    print(s);
    cout << s.count(7) << endl;
    auto ret = s.find(10);
    if (ret != s.end())
    {
        cout << *(s.find(10)) << endl;
    }
    else
    {
        cout << "canot find !!" << endl;
    }
}

void fun4()
{
    set<int> s{ 1,2 };
    auto ret = s.insert(1);
    cout << "插入状态：" << boolalpha <<ret.second << endl;
    multiset<int> ss{ 1,2 };
    auto rret = ss.insert(1);
    cout << "插入状态：" << boolalpha << *rret << endl;
}

void fun5()
{
    auto m = make_pair<int, string>(1, "xlp");
    cout << m.first << "  " << m.second << endl;
    pair<int, string> p(1, "xxx");
    cout << p.first << p.second << endl;
}

void fun6()
{
    auto m = make_pair<int, string>(1, "xlp");
    cout << m.first << "  " << m.second << endl;
    pair<int, string> p(1, "xxx");
    cout << p.first << p.second << endl;
}

void fun7()
{
    set<int, myCompare> s{ 1,4,5,6,7,8,3,2 };
    print(s);
}

void fun8()
{
    set<Person, myCompare> s;
    s.insert(Person("xlp1", 1));
    s.insert(Person("xlp3", 3));
    s.insert(Person("xlp2", 2));
    s.insert(Person("xlp4", 4));
    s.insert(Person("xlp0", 0));
    print(s);
}


int main()
{
    //fun1();
    //fun2();
    //fun3();
    //fun4();
    //fun5();
    //fun6();
    //fun7();
    fun8();
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
