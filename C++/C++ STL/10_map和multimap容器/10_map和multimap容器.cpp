// 10_map和multimap容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

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
void print(T& t)
{
    for (auto it = t.begin(); it != t.end(); it++)
    {
        cout << (*it).first << "  " << (*it).second << endl;
    }
    cout << endl;
}

void print(map<Person, string, myCompare>& t)
{
    for (auto it = t.begin(); it != t.end(); it++)
    {
        cout << it->first.name << "  " << (*it).first.age << "  " << it->second << endl;
    }
    cout << endl;
}



void fun1()
{
    map<int, int> s, s2, s3;
    s.insert(make_pair(1, 10));
    s.insert(make_pair(2, 20));
    s.insert(make_pair(3, 30));
    s.insert(make_pair(4, 40));
    s.insert(make_pair(5, 50));
    print(s);
    s2 = s;
    s2.insert(make_pair(9, 90));
    print(s2);
    cout << "s size : " << s.size() << endl;
    s.swap(s2);
    print(s);
    print(s2);
}


void fun2()
{
    map<int, int> m{ make_pair(1, 10),
                        make_pair(2, 20) ,
                        make_pair(3, 30) ,
                        make_pair(4, 40) ,
                        make_pair(5, 50) ,
                        };
    print(m);
    m.erase(3);
    print(m);
    m.erase(m.begin());
    print(m);
    m.clear();
    print(m);
}

void fun3()
{
    map<int, int> m{ make_pair(1, 10),
                        make_pair(2, 20) ,
                        make_pair(3, 30) ,
                        make_pair(4, 40) ,
                        make_pair(5, 50) ,
    };
    print(m);
    cout << m.count(40) << endl;
    auto ret = m.find(1);
    if (ret != m.end())
    {
        cout << ret->first << "  " << ret->second << endl;
    }
    else
    {
        cout << "canot find !!" << endl;
    }
}

void fun4()
{
    map<int, int> m{ make_pair(1, 10),
                        make_pair(2, 20) ,
                        make_pair(3, 30) ,
                        make_pair(4, 40) ,
                        make_pair(5, 50) ,
    };
    auto ret = m.insert(make_pair(1, 10));
    cout << "插入状态：" << boolalpha << ret.second << endl;
    multimap<int, int> mm{ make_pair(1, 10), };
    auto rret = mm.insert(make_pair(1, 10));
    cout << "插入状态：" << boolalpha << rret->first << endl;
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
    map<int, int, myCompare> m{ make_pair(1, 10),
                        make_pair(2, 20) ,
                        make_pair(3, 30) ,
                        make_pair(4, 40) ,
                        make_pair(5, 50) ,
    };
    print(m);
}

void fun7()
{
    map<Person, string, myCompare> m;
    m.insert(make_pair(Person("xlp1", 1), "111"));
    m.insert(make_pair(Person("xlp3", 3), "333"));
    m.insert(make_pair(Person("xlp2", 2), "222"));
    m.insert(make_pair(Person("xlp4", 4), "444"));
    m.insert(make_pair(Person("xlp0", 0), "000"));
    print(m);
}


int main()
{
    //fun1();
    //fun2();
    //fun3();
    //fun4();
    //fun5();
    //fun6();
    fun7();
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
