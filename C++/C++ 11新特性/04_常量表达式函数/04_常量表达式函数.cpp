// 04_常量表达式函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

constexpr int fun1()
{
    constexpr int a = 10;
    return a;
}

struct person
{
    const char* name;
    int age;
};

struct T
{
    constexpr T():a(100)
    {}
    int a;
};

template<typename T>
constexpr T fun2(T t)
{
    return t;
}
int main()
{
    constexpr T t;
    T t2;
    t.a = 20;
    t2.a = 20;
    constexpr int a = fun1();
    constexpr person p{ "xlp", 20 };
    person p2{ "xlp", 20 };
    //p.age = 1;
    p2.age = 1;

    constexpr person p3 = fun2(p);
    person p4 = fun2(p2);
    p4.age = 1;
    std::cout << p3.name << p3.age << std::endl;
    std::cout << p4.name << p4.age << std::endl;
    std::cout << a << std::endl;
    //std::cout << "Hello World!\n";
}

//constexpr int fun1()
//{
//    constexpr int a = 10;
//    return a;
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
