// 48_弱引用智能指针weak_ptr的初始化和相关的操作函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> sp(new int(500));
    shared_ptr<int> sp2(sp);
    //unique_ptr<int> up(sp);

    weak_ptr<int> wp1;
    weak_ptr<int> wp2(wp1);
    weak_ptr<int> wp3(sp);
    weak_ptr<int> wp4;
    wp4 = wp3;

    cout << "use count:" << endl;
    wp4.reset();
    cout << wp1.use_count() << endl;
    cout << wp2.use_count() << endl;
    cout << wp3.use_count() << endl;
    cout << wp4.use_count() << endl;

    sp2.reset();
    cout << boolalpha << wp3.expired() << endl;
    sp.reset();
    cout << boolalpha << wp3.expired() << endl;

    shared_ptr<int> ss, ss1;
    weak_ptr<int> ww;
    ss = make_shared<int>(1314);
    cout << ss << endl;
    ww = ss;
    //cout << *ww << endl;
    ss1 = ww.lock();
    cout << "ww is use count:  " << ww.use_count() << endl;
    ss.reset();
    cout << "ww is use count:  " << ww.use_count() << endl;
    ss = ww.lock();
    cout << "ww is use count:  " << ww.use_count() << endl;
    cout << *ss << endl << *ss1 << endl;
    ww.reset();
    cout << "ww is use count:  " << ww.use_count() << endl;
    cout << "ss is use count:  " << ss1.use_count() << endl;

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
