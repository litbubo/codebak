// 21_统一的数据初始化方式 - 初始化列表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Person
{
public:
    Person(int num) :m_num(num)
    {}
private:
    int m_num;
};

int main()
{
    Person p1(10);
    Person p2 = 20;
    Person p3 = { 30 };
    Person p4{ 40 };

    int a{ 1234 };
    int b = { 123 };
    int arr[]{ 1234 };
    int* p = new int{ 1234 };
    int* array = new int[5]{ 1,2,3,4,5 };
    for(auto x = 0; x<5; x++)
    {
        std::cout << array[x] << std::endl;
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
