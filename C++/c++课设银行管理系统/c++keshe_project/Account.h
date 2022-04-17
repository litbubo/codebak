#pragma once
#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
	string account;								//�˺�
	string name;								//����
	string ID_number;							//���֤��
	double balance;								//���
	double recent_deposit_amount;				//��������
	double recent_withdrawal_amount;			//���ȡ����
	string account_type;						//�˻�����
	string description;							//�˻�����
public:
	Account();									//�޲ι��캯��
	Account(string acc, string n, string ID, double bal, double rda, double rwa, string accty, string des);
	void Deposit(double d);						//ȡ��
	void Withdrawal(double w, int &);			//���
	void Print();
	string GetAccount() { return account; };
	friend void SaveAsFile();
};