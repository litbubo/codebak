// exercese1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Auto
{
protected:
	string stypename;
	int npassengers;
	string smanufacturer;
public:
	Auto()
	{
		stypename = "Auto";
		npassengers = 0;
		smanufacturer = "no manufacturer";
	}

	virtual ~Auto() {}
	static void TrimLine(char *sbuf)
	{
		while (*sbuf != '\0')
		{
			if (*sbuf == '\r' || *sbuf == '\n')
			{
				*sbuf = '\0';
				break;
			}
			sbuf++;
		}
	}
	virtual bool Input(FILE *fp) = 0;
	virtual void Show() = 0;
};

class Car :public Auto
{
public:
	Car()
	{
		stypename = "Car";
	}
	bool Input(FILE *fp)
	{
		char sbuf[100];
		fgets(sbuf, 100, fp);
		TrimLine(sbuf);
		smanufacturer = sbuf;
		fgets(sbuf, 100, fp);
		npassengers = atoi(sbuf);
		return true;
	}
	void Show()
	{
		cout << "style: " << stypename << endl;
		cout << "manufacturer: " << smanufacturer << endl;
		cout << "Passenger: " << npassengers << endl;
	}
};

class Truck :public Car
{
protected:
	float fload;
public:
	Truck()
	{
		stypename = "Truck";
		fload = 0;
	}
	bool Input(FILE *fp)
	{
		char sbuf[100];
		Car::Input(fp);
		fgets(sbuf, 100, fp);
		fload = atof(sbuf);
		return true;
	}
	void Show()
	{
		Car::Show();
		cout << "Load:" << fload << endl;
	}
};

class Crane :public Truck
{
protected:
	float fheight;
public:
	Crane()
	{
		stypename = "Crane";
		fheight = 0;
	}
	bool Input(FILE *fp)
	{
		char sbuf[100];
		Truck::Input(fp);
		fgets(sbuf, 100, fp);
		fheight = atof(sbuf);
		return true;
	}
	void Show()
	{
		Truck::Show();
		cout << "Height: " << fheight << endl;
	}
};

int main()
{

    return 0;
}

