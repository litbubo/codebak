#include "stdafx.h"
#include "ActionRecord.h"

void ActionRecord::CreatAccountRecord(string A)
{
	record += GetTimeNow() + "	";
	record += "�Ѵ����˻�";
	record += A + "!";
}

void ActionRecord::DeleteAccountRecord(string D)
{
	record += GetTimeNow() + "	";
	record += "��ɾ���˻�";
	record += D + "!";
}

void ActionRecord::DepositRecord(double d)
{
	record += GetTimeNow() + "	";
	record += "�˻�";
	record += account;
	record += "�Ѵ�����";
	record += to_string(d);
	record += "!";
}

void ActionRecord::Withdrawal(double w)
{
	record += GetTimeNow() + "	";
	record += "�˻�";
	record += account;
	record += "��ȡ�����";
	record += to_string(w);
	record += "!";
}

void ActionRecord::Print()
{
	cout << record << endl;
}

string ActionRecord::GetTimeNow()				//ʱ���¼
{
	time_t tt = time(NULL);
	tm t;
	localtime_s(&t, &tt);
	string timenow = to_string(t.tm_year + 1900) + "-" + to_string(t.tm_mon + 1) + "-" + to_string(t.tm_mday) + "	";
	timenow += to_string(t.tm_hour) + ":" + to_string(t.tm_min) + ":" + to_string(t.tm_sec);
	return timenow;								//��ȡϵͳ��ǰʱ�䣬����string���Ͳ�����
}