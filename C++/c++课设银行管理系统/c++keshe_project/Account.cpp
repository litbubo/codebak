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

void Account::Deposit(double d)					//���
{
	balance += d;
	recent_deposit_amount = d;
	cout << "��" << balance << endl;
}

void Account::Withdrawal(double w, int &x)		//ȡ��
{
	if (w > balance)							//���ʣ���ж�
	{
		cout << "���㣡��" << endl;
		x = 0;									//�����ж��Ƿ�ȡ��ɹ�����ȷ���Ƿ����ȡ��ļ�¼
		return;
	}
	balance -= w;
	recent_withdrawal_amount = w;
	cout << "��" << balance << endl;
	cout << "�Ѵ��!" << endl;
}

void Account::Print()
{
	cout << "�Ѵ�ӡ�˻���Ϊ" << account << "���˻���Ϣ��" << endl << endl;
	cout << "�� �� ����	" << account << endl;
	cout << "����������	" << name << endl;
	cout << "���֤�ţ�	" << ID_number << endl;
	cout << "��ǰ��	" << balance << endl;
	cout << "�����	" << recent_deposit_amount << endl;
	cout << "���ȡ�	" << recent_withdrawal_amount << endl;
	cout << "�˻����ͣ�	" << account_type << endl;
	cout << "�˻�������	" << description << endl << endl;
}