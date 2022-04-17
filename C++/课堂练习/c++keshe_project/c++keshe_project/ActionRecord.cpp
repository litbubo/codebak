#include "stdafx.h"
#include "ActionRecord.h"

void ActionRecord::CreatAccountRecord(string A)
{
	record += GetTimeNow() + "	";
	record += "已创建账户";
	record += A + "!";
}

void ActionRecord::DeleteAccountRecord(string D)
{
	record += GetTimeNow() + "	";
	record += "已删除账户";
	record += D + "!";
}

void ActionRecord::DepositRecord(double d)
{
	record += GetTimeNow() + "	";
	record += "账户";
	record += account;
	record += "已存入金额";
	record += to_string(d);
	record += "!";
}

void ActionRecord::Withdrawal(double w)
{
	record += GetTimeNow() + "	";
	record += "账户";
	record += account;
	record += "已取出金额";
	record += to_string(w);
	record += "!";
}

void ActionRecord::Print()
{
	cout << record << endl;
}

string ActionRecord::GetTimeNow()				//时间记录
{
	time_t tt = time(NULL);
	tm t;
	localtime_s(&t, &tt);
	string timenow = to_string(t.tm_year + 1900) + "-" + to_string(t.tm_mon + 1) + "-" + to_string(t.tm_mday) + "	";
	timenow += to_string(t.tm_hour) + ":" + to_string(t.tm_min) + ":" + to_string(t.tm_sec);
	return timenow;								//获取系统当前时间，存入string类型并返回
}