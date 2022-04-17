#include "stdafx.h"
#include "Account.h"

Account::Account()
{
	account = "Default Account.";
	name = "Default Name.";
	ID_number = "Default ID.";
	balance = 0;
	recent_deposit_amount = 0;
	recent_withdrawal_amount = 0;
	account_type = "Default Type.";
	description = "Default Description.";
}

Account::Account(string acc, string n, string ID, double bal, double rda, double rwa, string accty, string des)
{
	account = acc;
	name = n;
	ID_number = ID;
	account_type = accty;
	description = des;
	balance = bal;
	recent_withdrawal_amount = rwa;
	recent_deposit_amount = rda;
}

void Account::Deposit(double d)					//存款
{
	balance += d;
	recent_deposit_amount = d;
	cout << "余额：" << balance << endl;
}

void Account::Withdrawal(double w, int &x)		//取款
{
	if (w > balance)							//存款剩余判断
	{
		cout << "余额不足！！" << endl;
		x = 0;									//用于判断是否取款成功，来确定是否进行取款的记录
		return;
	}
	balance -= w;
	recent_withdrawal_amount = w;
	cout << "余额：" << balance << endl;
	cout << "已存款!" << endl;
}

void Account::Print()
{
	cout << "已打印账户名为" << account << "的账户信息：" << endl << endl;
	cout << "账 户 名：	" << account << endl;
	cout << "户主姓名：	" << name << endl;
	cout << "身份证号：	" << ID_number << endl;
	cout << "当前余额：	" << balance << endl;
	cout << "最近存款：	" << recent_deposit_amount << endl;
	cout << "最近取款：	" << recent_withdrawal_amount << endl;
	cout << "账户类型：	" << account_type << endl;
	cout << "账户描述：	" << description << endl << endl;
}