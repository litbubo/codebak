#pragma once
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class ActionRecord
{
private:
	string record;								//�˻����¼
	string account;								//��˴λ�󶨵��˺�
public:
	ActionRecord(string acc) { account = acc; };
	ActionRecord(string acc, string rec) { account = acc; record = rec; };
	void CreatAccountRecord(string A);			//�˻�������¼
	void DeleteAccountRecord(string D);			//�˻�ע����¼
	void DepositRecord(double d);				//����¼
	void Withdrawal(double w);					//ȡ���¼
	void Print();
	string GetAccount() { return account; };
	string GetTimeNow();						//��ȡ��ǰϵͳʱ��
	friend void SaveAsFile();
};