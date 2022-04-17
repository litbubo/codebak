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

inline Book::Book() :name("Ĭ������"), author("Ĭ������"), publisher("Ĭ�ϳ�����"), pages(0)
{
	cout << "Ĭ�Ϲ���ɹ���" << endl;
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
	cout << "������" << name << endl << "���ߣ�" << author << endl;
	cout << "�����磺" << publisher << endl << "ҳ����" << pages << endl;
}

inline Book::~Book()
{
	cout << "Destruct the book " << name << endl;
}


int main()
{
	Book *p1,*p2;
	p1 = new Book;
	p2=new Book("����ϼ�", "������", "���������", 1330);
	p1->Print();
	delete p1;
	p2->Print();
	p2->SetInfo("����2", "������", "���������", 550);
	p2->Print();
	delete p2;
    return 0;
}

