#pragma once
#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
	string account;								//账号
	string name;								//姓名
	string ID_number;							//身份证号
	double balance;								//余额
	double recent_deposit_amount;				//最近存款金额
	double recent_withdrawal_amount;			//最近取款金额
	string account_type;						//账户类型
	string description;							//账户描述
public:
	Account();									//无参构造函数
	Account(string acc, string n, string ID, double bal, double rda, double rwa, string accty, string des);
	void Deposit(double d);						//取款
	void Withdrawal(double w, int &);			//存款
	void Print();
	string GetAccount() { return account; };
	friend void SaveAsFile();
};