// 02_string容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
3.1.2.1 string 构造函数
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化

3.1.2.2 string基本赋值操作
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/

void fun1()
{
    string s(10, 'a');
    cout << "s:  " << s << endl;
    s.assign("xlpxlp");
    cout << "s:  " << s << endl;
    s.assign("xlpxlp",3);
    cout << "s:  " << s << endl;
    s.assign("asdfghj", 2, 2);
    cout << "s:  " << s << endl;
}

/*
3.1.2.3 string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/
void fun2()
{
    string s("xlp");
    cout << s[0] << endl;
    cout << s.at(5) << endl;
}

/*
3.1.2.4 string拼接操作
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c

3.1.2.5 string查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
*/
void fun3()
{
    string s("123");
    s.append("456");
    cout << s << endl;
    s.append("789", 2);
    cout << s << endl;

    auto pos = s.find("78");
    cout << pos << endl;
    s.replace(2, 2, "qwertyuiop");
    cout << s << endl;
}

/*
3.1.2.6 string比较操作
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
*/

void fun4()
{
    string s1 = "abc";
    string s2 = "abcd";
    cout << s1.compare(s2) << endl;
    s1.replace(1, 1, "c");
    cout << s1.compare(s2) << endl;
}

/*
3.1.2.7 string子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
*/
void fun5()
{
    string email = "imxlp@outlook.com";
    auto pos = email.find("@");
    cout << email.substr(0, pos) << endl;
}

/*
3.1.2.8 string插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/

void fun6()
{
    string s = "123456";
    s.insert(1, "aaa");
    cout << s << endl;
    s.erase(1, 2);
    cout << s << endl;
}

/*
string和c-style字符串转换
*/

void doWork(string s)
{
}

void doWork2(const char* s)
{
}

void fun7()
{
    //char *  ->string
    const char* str = "hello";
    string s(str);


    // string -> char *
    const char* str2 = s.c_str();

    doWork(str2); //编译器将  const char*  可以隐式类型转换为  string

    //doWork2(s); //编译器 不会 将 string 隐式类型转换为 const char *
}

void fun8()
{
    string s = "123456789";
    auto& a = s[3];
    auto& b = s[4];
    a = 'a';
    b = 'b';
    cout << s << endl;
    cout << (void*)s.c_str() << endl;
    
    s = "777777777777777";
    a = 'a';
    b = 'b';
    cout << s << endl;
    cout << (void*)s.c_str() << endl;
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
