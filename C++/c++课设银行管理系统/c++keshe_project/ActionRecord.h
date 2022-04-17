#pragma once
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class ActionRecord
{
private:
	string record;								//账户活动记录
	string account;								//与此次活动绑定的账号
public:
	ActionRecord(string acc) { account = acc; };
	ActionRecord(string acc, string rec) { account = acc; record = rec; };
	void CreatAccountRecord(string A);			//账户创建记录
	void DeleteAccountRecord(string D);			//账户注销记录
	void DepositRecord(double d);				//存款记录
	void Withdrawal(double w);					//取款记录
	void Print();
	string GetAccount() { return account; };
	string GetTimeNow();						//获取当前系统时间
	friend void SaveAsFile();
};