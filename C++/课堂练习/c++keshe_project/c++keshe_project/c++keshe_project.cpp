// c++keshe_project.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <list>
#include <fstream>
#include <Windows.h>

#include "Account.h"
#include "ActionRecord.h"

list<Account> LBank;							//�˻�����
list<ActionRecord> LRecord;						//���¼����

void Menu()
{
	system("cls");
	cout << "********************************�����˻�ϵͳ******************************" << endl << "*						   			 *" << endl;
	cout << "*				0.��ӡȫ��				 *" << endl << "*						   			 *" << endl;
	cout << "*				1.�����˻�				 *" << endl << "*						   			 *" << endl;
	cout << "*				2.ɾ���˻�				 *" << endl << "*						   			 *" << endl;
	cout << "*				3.���					 *" << endl << "*						   			 *" << endl;
	cout << "*				4.ȡ��					 *" << endl << "*						   			 *" << endl;
	cout << "*				5.��ѯ					 *" << endl << "*						   			 *" << endl;
	cout << "*				6.ϵͳ��־				 *" << endl << "*						   			 *" << endl;
	cout << "*				7.�˳�					 *" << endl << "*						   			 *" << endl;
	cout << "**************************************************************************" << endl;
}

int InputJudge(int c)							//�ж����˵�ѡ�������Ƿ�Ϸ�
{
	if (c >= 0 && c <= 7)
		return c;
	cout << "�����������������룡" << endl;
	cin >> c;
	return c;
}

void inputData()								//��ȡ�����ļ�����
{
	cout << "���ڴӱ����ļ���������..." << endl << endl;
	Sleep(1000);
	char account[50] = { 0 };					//��ʼ���ַ���Ϊ0
	char name[50] = { 0 };
	char ID_number[50] = { 0 };
	double balance = 0;
	double recent_deposit_amount = 0;
	double recent_withdrawal_amount = 0;
	char account_type[50] = { 0 };
	char description[50] = { 0 };
	ifstream inFile("D:\\Accountdata.dat", ios::in | ios::binary);			//�Զ����ƶ�ȡ�ļ�
	if (!inFile)								//�ж��ļ��Ƿ����
		cout << "�ļ�Accountdata.dat�����ڣ�" << endl << endl;
	while (inFile.peek() != EOF)
	{
		inFile.read(account, 50);				//��ÿ50���ֽڶ�ȡһ������
		inFile.read(name, 50);
		inFile.read(ID_number, 50);
		inFile.read((char*)&balance, sizeof(double));		//��char *��ʽ��ȡ����double����ռ�ֽ�����ȡ
		inFile.read((char*)&recent_deposit_amount, sizeof(double));
		inFile.read((char*)&recent_withdrawal_amount, sizeof(double));
		inFile.read(account_type, 50);
		inFile.read(description, 50);
		Account temp(account, name, ID_number, balance, recent_deposit_amount, recent_withdrawal_amount, account_type, description);
		LBank.push_back(temp);					//����ȡ���Ķ��������������
	}
	inFile.close();
	char account2[200] = { 0 };
	char record[200] = { 0 };
	ifstream inFile2("D:\\ActionRecord.dat", ios::in | ios::binary);
	if (!inFile2)
		cout << "�ļ�ActionRecord.dat�����ڣ�" << endl << endl;
	while (inFile2.peek() != EOF)
	{
		inFile2.read(account2, 200);
		inFile2.read(record, 200);
		ActionRecord temp2(account2, record);
		LRecord.push_back(temp2);				//����ȡ���Ķ��������������
	}
	inFile2.close();
	cout << "���ݵ������..." << endl << endl;
	Sleep(1000);
	system("pause");
	system("cls");
}


void Print_All()								//��ӡȫ����Ϣ
{
	system("cls");
	if (LBank.begin() == LBank.end())			//�п�
	{
		cout << "�˻�����Ϊ�գ�" << endl;
		system("pause");
		return;
	}
	list<Account>::iterator itl;				//������
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		itl->Print();							//������ӡ�����ö���Print()
	}
	cout << "�Ѵ�ӡ�����û����ݣ�" << endl << endl;
	system("pause");
}

void Set_Account()								//�������˻�
{
	system("cls");
	string account;
	string name;
	string ID_number;
	double balance = 0;
	double recent_deposit_amount = 0;
	double recent_withdrawal_amount = 0;
	string account_type;
	string description;
	cout << endl << "�� �� �� �� �� �� ����	";
	cin >> account;
	cout << endl << "���������˻�����������	";
	cin >> name;
	cout << endl << "�������»������֤�ţ�	";
	cin >> ID_number;
	cout << endl << "�� �� �� ���˻� ���ͣ�	";
	cin >> account_type;
	cout << endl << "�� �� �� ���˻� ������	";
	cin >> description;
	Account temp(account, name, ID_number, balance, recent_deposit_amount, recent_withdrawal_amount, account_type, description);
	LBank.push_back(temp);						//���˻�������������
	ActionRecord temp2(account);				//������ǰ�˻��Ļ��¼
	temp2.CreatAccountRecord(account);			//�����˻���¼
	LRecord.push_back(temp2);					
	cout << endl << "�˻�������ɣ�" << endl;
	system("pause");
}

void Delete_Account()							//ע���˻�
{
	system("cls");
	if (LBank.begin() == LBank.end())
	{
		cout << "�˻�����Ϊ�գ�" << endl;
		system("pause");
		return;
	}
	int count = 0, num = 0;
	string account;
	cout << "��������Ҫɾ���˻����˻�����" << endl;
	cin >> account;
	list<Account>::iterator itl;
	num = LBank.size();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		if (account == itl->GetAccount())		//�����˻�
		{
			itl->Print();
			LBank.erase(itl);					//����������ɾ����ǰ�˻�
			ActionRecord temp(account);			//������ǰ�˻��Ļ��¼
			temp.DeleteAccountRecord(account);	//��¼ɾ���
			LRecord.push_back(temp);			//�����¼������������
			cout << "ɾ���ɹ���" << endl;
			break;
		}
		else
			count++;
	}
	if (count == num)
		cout << "δ�ҵ����˻�������Ƿ��������" << endl;
	system("pause");
}

void Deposit_0()								//���
{
	system("cls");
	if (LBank.begin() == LBank.end())
	{
		cout << "�˻�����Ϊ�գ�" << endl;
		system("pause");
		return;
	}
	string account;
	cout << "��������Ҫ����˻����˻�����" << endl;
	cin >> account;
	double deposit;
	list<Account>::iterator itl;
	int count = 0, num = 0;
	num = LBank.size();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		if (account == itl->GetAccount())
		{
			cout << "��������Ҫ���Ľ�" << endl;
			cin >> deposit;
			itl->Deposit(deposit);
			itl->Print();
			ActionRecord temp(account);
			temp.DepositRecord(deposit);
			LRecord.push_back(temp);
			break;
		}
		else
			count++;
	}
	if (count == num)
		cout << "δ�ҵ����˻�������Ƿ��������" << endl;
	system("pause");
}

void Withdrawal_0()								//ȡ��
{
	system("cls");
	if (LBank.begin() == LBank.end())
	{
		cout << "�˻�����Ϊ�գ�" << endl;
		system("pause");
		return;
	}
	string account;
	cout << "��������Ҫȡ���˻����˻�����" << endl;
	cin >> account;
	double withdrawal;
	list<Account>::iterator itl;
	int count = 0, num = 0;
	num = LBank.size();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		if (account == itl->GetAccount())
		{
			cout << "��������Ҫȡ��Ľ�" << endl;
			cin >> withdrawal;
			int x = 1;
			itl->Withdrawal(withdrawal, x);
			itl->Print();
			if (x)
			{
				ActionRecord temp(account);
				temp.Withdrawal(withdrawal);
				LRecord.push_back(temp);
				cout << "��ȡ��!" << endl;
			}
			break;
		}
		else
			count++;
	}
	if (count == num)
		cout << "δ�ҵ����˻�������Ƿ��������" << endl;
	system("pause");
}

void Inquire()									//��ѯ
{
	system("cls");
	if (LBank.begin() == LBank.end())
	{
		cout << "�˻�����Ϊ�գ�" << endl;
		system("pause");
		return;
	}
	string account;
	cout << "��������Ҫ��ѯ�˻����˻�����" << endl;
	cin >> account;
	list<Account>::iterator itl;
	int count = 0, num = 0;
	num = LBank.size();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		if (account == itl->GetAccount())
		{
			itl->Print();
			break;
		}
		else
			count++;
	}
	if (count == num)
		cout << "δ�ҵ����˻�������Ƿ��������" << endl;
	system("pause");
}

void SystenLog()								//ϵͳ��־
{
	system("cls");
	list<ActionRecord>::iterator itl;
	if (LRecord.begin() == LRecord.end())
	{
		cout << "�˻�����Ϊ�գ�" << endl;
		system("pause");
		return;
	}
	for (itl = LRecord.begin(); itl != LRecord.end(); itl++)
		itl->Print();
	system("pause");
}


void SaveAsFile()								//�ļ�����
{
	ofstream outFile("D:\\Accountdata.dat", ios::out | ios::binary);		//��д�ķ�ʽ���ļ�
	if (!outFile)
	{
		cout << "���ļ�Accountdata.datʧ�ܣ�" << endl;
		return;
	}
	list<Account>::iterator itl;
	itl = LBank.begin();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)					//����д��
	{
		outFile.write(itl->account.c_str(), 50);							//����һ��const char*ָ�룬ָ���Կ��ַ���ֹ������
		outFile.write(itl->name.c_str(), 50);								//��ÿ50���ֽ�һ������д��
		outFile.write(itl->ID_number.c_str(), 50);
		outFile.write((char*)&itl->balance, sizeof(double));
		outFile.write((char*)&itl->recent_deposit_amount, sizeof(double));
		outFile.write((char*)&itl->recent_withdrawal_amount, sizeof(double));
		outFile.write(itl->account_type.c_str(), 50);
		outFile.write(itl->description.c_str(), 50);
	}
	outFile.close();
	ofstream outFile2("D:\\ActionRecord.dat", ios::out | ios::binary);
	if (!outFile2)
	{
		cout << "���ļ�ActionRecord.datʧ�ܣ�" << endl;
		return;
	}
	list<ActionRecord>::iterator itl2;
	itl2 = LRecord.begin();
	for (itl2 = LRecord.begin(); itl2 != LRecord.end(); ++itl2)
	{
		outFile2.write(itl2->account.c_str(), 200);
		outFile2.write(itl2->record.c_str(), 200);
	}
	outFile2.close();
	cout << "���ڱ���..." << endl;
	Sleep(1000);
	cout << "�������..." << endl;
	Sleep(1000);
	return;
}

int main()
{
	inputData();
	int choose;
	bool judge = true;
	while (judge)
	{
		Menu();
		cin >> choose;
		choose = InputJudge(choose);
		switch (choose)
		{
		case 0:
			Print_All();
			break;
		case 1:
			Set_Account();
			break;
		case 2:
			Delete_Account();
			break;
		case 3:
			Deposit_0();
			break;
		case 4:
			Withdrawal_0();
			break;
		case 5:
			Inquire();
			break;
		case 6:
			SystenLog();
			break;
		case 7:
			judge = false;
		}
	}
	SaveAsFile();
	system("pause");
	return 0;
}

