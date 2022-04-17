// 09_decltype类型推导规则2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Test { ... };
//函数声明
int func_int();                 // 返回值为 int
int& func_int_r();              // 返回值为 int&
int&& func_int_rr();            // 返回值为 int&&

const int func_cint();          // 返回值为 const int
const int& func_cint_r();       // 返回值为 const int&
const int&& func_cint_rr();     // 返回值为 const int&&

const Test func_ctest();        // 返回值为 const Test

//decltype类型推导
int n = 100;
decltype(func_int()) a = 0;
decltype(func_int_r()) b = n;
decltype(func_int_rr()) c = 0;
decltype(func_cint())  d = 0;
decltype(func_cint_r())  e = n;
decltype(func_cint_rr()) f = 0;
decltype(func_ctest()) g = Test();


int main()
{
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
