// 05_打分案例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Person
{
public:
	Person(string s, int x):name(s),score(x) {};
	string name;
	int score;
};

void creat_person(vector<Person>& v)
{
	string name = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string temp = "选手";
		temp += name[i];
		v.push_back(Person(temp, 0));
	}
}

void set_Score(vector<Person>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		deque<int> score;
		for (int i = 0; i < 10; i++)
		{
			score.push_back(rand()%41 + 60);
		}
		sort(score.begin(), score.end());
		score.pop_back();
		score.pop_front();
		/*for (auto it = score.begin(); it != score.end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;*/
		double score_sum = 0;
		for (auto it = score.begin(); it != score.end(); it++)
		{
			score_sum += *it;
		}

		it->score = score_sum / (int)score.size();
	}
}

int main()
{
	vector<Person> v;
	creat_person(v);
	set_Score(v);
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->name << "    分数：" << it->score << endl;
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
