#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
	string name;
	string author;
	string publisher;
	int pages;
public:
	Book();
	Book(string nm, string ath, string pub, int pg);
	void SetInfo(string nm, string ath, string pub, int pg);
	void Print();
	~Book();
};

inline Book::Book() :name("默认名字"), author("默认作者"), publisher("默认出版社"), pages(0)
{
	cout << "默认构造成功。" << endl;
}

Book::Book(string nm, string ath, string pub, int pg)
{
	name = nm;
	author = ath;
	publisher = pub;
	pages = pg;
}

void Book::SetInfo(string nm, string ath, string pub, int pg)
{
	name = nm;
	author = ath;
	publisher = pub;
	pages = pg;
}

inline void Book::Print()
{
	cout << "书名：" << name << endl << "作者：" << author << endl;
	cout << "出版社：" << publisher << endl << "页数：" << pages << endl;
}

inline Book::~Book()
{
	cout << "Destruct the book " << name << endl;
}


int main()
{
	Book *p1,*p2;
	p1 = new Book;
	p2=new Book("三体合集", "刘慈欣", "重庆出版社", 1330);
	p1->Print();
	delete p1;
	p2->Print();
	p2->SetInfo("三体2", "刘慈欣", "重庆出版社", 550);
	p2->Print();
	delete p2;
    return 0;
}

