// exercise20201117.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Vehicle
{
protected:
	int pos, speed;
public:
	Vehicle(int ps = 0, int spd = 0)
	{
		pos = ps;
		speed = spd;
	}
	void SetSpeed(int spd)
	{
		speed = spd;
	}
	void Show()
	{
		cout << pos << endl;
	}
	virtual void run() = 0;
};

class Car :public Vehicle
{
public:
	void run()
	{
		pos += speed;
	}
};


int main()
{
	Vehicle *pvh;
	Car car;
	pvh = &car;
	pvh->SetSpeed(5);
	pvh->Show();
	pvh->run();
	pvh->Show();
	pvh->run();
	pvh->Show();
	pvh->run();
	pvh->Show();
	pvh->run();
    return 0;
}

