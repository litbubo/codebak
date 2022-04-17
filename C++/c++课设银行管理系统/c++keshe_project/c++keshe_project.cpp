// c++keshe_project.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <list>
#include <fstream>
#include <Windows.h>

#include "Account.h"
#include "ActionRecord.h"

list<Account> LBank;							//账户链表
list<ActionRecord> LRecord;						//活动记录链表

void Menu()
{
	system("cls");
	cout << "********************************银行账户系统******************************" << endl << "*						   			 *" << endl;
	cout << "*				0.打印全部				 *" << endl << "*						   			 *" << endl;
	cout << "*				1.建立账户				 *" << endl << "*						   			 *" << endl;
	cout << "*				2.删除账户				 *" << endl << "*						   			 *" << endl;
	cout << "*				3.存款					 *" << endl << "*						   			 *" << endl;
	cout << "*				4.取款					 *" << endl << "*						   			 *" << endl;
	cout << "*				5.查询					 *" << endl << "*						   			 *" << endl;
	cout << "*				6.系统日志				 *" << endl << "*						   			 *" << endl;
	cout << "*				7.退出					 *" << endl << "*						   			 *" << endl;
	cout << "**************************************************************************" << endl;
}

int InputJudge(int c)							//判断主菜单选项输入是否合法
{
	if (c >= 0 && c <= 7)
		return c;
	cout << "输入有误，请重新输入！" << endl;
	cin >> c;
	return c;
}

void inputData()								//读取本地文件数据
{
	cout << "正在从本地文件读入数据..." << endl << endl;
	Sleep(1000);
	char account[50] = { 0 };					//初始化字符串为0
	char name[50] = { 0 };
	char ID_number[50] = { 0 };
	double balance = 0;
	double recent_deposit_amount = 0;
	double recent_withdrawal_amount = 0;
	char account_type[50] = { 0 };
	char description[50] = { 0 };
	ifstream inFile("D:\\Accountdata.dat", ios::in | ios::binary);			//以二进制读取文件
	if (!inFile)								//判断文件是否存在
		cout << "文件Accountdata.dat不存在！" << endl << endl;
	while (inFile.peek() != EOF)
	{
		inFile.read(account, 50);				//以每50个字节读取一个变量
		inFile.read(name, 50);
		inFile.read(ID_number, 50);
		inFile.read((char*)&balance, sizeof(double));		//以char *方式读取，以double型所占字节数读取
		inFile.read((char*)&recent_deposit_amount, sizeof(double));
		inFile.read((char*)&recent_withdrawal_amount, sizeof(double));
		inFile.read(account_type, 50);
		inFile.read(description, 50);
		Account temp(account, name, ID_number, balance, recent_deposit_amount, recent_withdrawal_amount, account_type, description);
		LBank.push_back(temp);					//将读取到的对象放入链表容器
	}
	inFile.close();
	char account2[200] = { 0 };
	char record[200] = { 0 };
	ifstream inFile2("D:\\ActionRecord.dat", ios::in | ios::binary);
	if (!inFile2)
		cout << "文件ActionRecord.dat不存在！" << endl << endl;
	while (inFile2.peek() != EOF)
	{
		inFile2.read(account2, 200);
		inFile2.read(record, 200);
		ActionRecord temp2(account2, record);
		LRecord.push_back(temp2);				//将读取到的对象放入链表容器
	}
	inFile2.close();
	cout << "数据导入结束..." << endl << endl;
	Sleep(1000);
	system("pause");
	system("cls");
}


void Print_All()								//打印全部信息
{
	system("cls");
	if (LBank.begin() == LBank.end())			//判空
	{
		cout << "账户数量为空！" << endl;
		system("pause");
		return;
	}
	list<Account>::iterator itl;				//迭代器
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		itl->Print();							//遍历打印，调用对象Print()
	}
	cout << "已打印所有用户数据！" << endl << endl;
	system("pause");
}

void Set_Account()								//创建新账户
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
	cout << endl << "请 输 入 新 账 户 名：	";
	cin >> account;
	cout << endl << "请输入新账户户主姓名：	";
	cin >> name;
	cout << endl << "请输入新户主身份证号：	";
	cin >> ID_number;
	cout << endl << "请 输 入 新账户 类型：	";
	cin >> account_type;
	cout << endl << "请 输 入 新账户 描述：	";
	cin >> description;
	Account temp(account, name, ID_number, balance, recent_deposit_amount, recent_withdrawal_amount, account_type, description);
	LBank.push_back(temp);						//新账户放入链表容器
	ActionRecord temp2(account);				//创建当前账户的活动记录
	temp2.CreatAccountRecord(account);			//创建账户记录
	LRecord.push_back(temp2);					
	cout << endl << "账户创建完成！" << endl;
	system("pause");
}

void Delete_Account()							//注销账户
{
	system("cls");
	if (LBank.begin() == LBank.end())
	{
		cout << "账户数量为空！" << endl;
		system("pause");
		return;
	}
	int count = 0, num = 0;
	string account;
	cout << "请输入需要删除账户的账户名：" << endl;
	cin >> account;
	list<Account>::iterator itl;
	num = LBank.size();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		if (account == itl->GetAccount())		//查找账户
		{
			itl->Print();
			LBank.erase(itl);					//从链表容器删除当前账户
			ActionRecord temp(account);			//创建当前账户的活动记录
			temp.DeleteAccountRecord(account);	//记录删除活动
			LRecord.push_back(temp);			//将活动记录放入链表容器
			cout << "删除成功！" << endl;
			break;
		}
		else
			count++;
	}
	if (count == num)
		cout << "未找到此账户，检查是否输入错误。" << endl;
	system("pause");
}

void Deposit_0()								//存款
{
	system("cls");
	if (LBank.begin() == LBank.end())
	{
		cout << "账户数量为空！" << endl;
		system("pause");
		return;
	}
	string account;
	cout << "请输入需要存款账户的账户名：" << endl;
	cin >> account;
	double deposit;
	list<Account>::iterator itl;
	int count = 0, num = 0;
	num = LBank.size();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		if (account == itl->GetAccount())
		{
			cout << "请输入需要存款的金额：" << endl;
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
		cout << "未找到此账户，检查是否输入错误。" << endl;
	system("pause");
}

void Withdrawal_0()								//取款
{
	system("cls");
	if (LBank.begin() == LBank.end())
	{
		cout << "账户数量为空！" << endl;
		system("pause");
		return;
	}
	string account;
	cout << "请输入需要取款账户的账户名：" << endl;
	cin >> account;
	double withdrawal;
	list<Account>::iterator itl;
	int count = 0, num = 0;
	num = LBank.size();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)
	{
		if (account == itl->GetAccount())
		{
			cout << "请输入需要取款的金额：" << endl;
			cin >> withdrawal;
			int x = 1;
			itl->Withdrawal(withdrawal, x);
			itl->Print();
			if (x)
			{
				ActionRecord temp(account);
				temp.Withdrawal(withdrawal);
				LRecord.push_back(temp);
				cout << "已取款!" << endl;
			}
			break;
		}
		else
			count++;
	}
	if (count == num)
		cout << "未找到此账户，检查是否输入错误。" << endl;
	system("pause");
}

void Inquire()									//查询
{
	system("cls");
	if (LBank.begin() == LBank.end())
	{
		cout << "账户数量为空！" << endl;
		system("pause");
		return;
	}
	string account;
	cout << "请输入需要查询账户的账户名：" << endl;
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
		cout << "未找到此账户，检查是否输入错误。" << endl;
	system("pause");
}

void SystenLog()								//系统日志
{
	system("cls");
	list<ActionRecord>::iterator itl;
	if (LRecord.begin() == LRecord.end())
	{
		cout << "账户数量为空！" << endl;
		system("pause");
		return;
	}
	for (itl = LRecord.begin(); itl != LRecord.end(); itl++)
		itl->Print();
	system("pause");
}


void SaveAsFile()								//文件保存
{
	ofstream outFile("D:\\Accountdata.dat", ios::out | ios::binary);		//以写的方式打开文件
	if (!outFile)
	{
		cout << "打开文件Accountdata.dat失败！" << endl;
		return;
	}
	list<Account>::iterator itl;
	itl = LBank.begin();
	for (itl = LBank.begin(); itl != LBank.end(); ++itl)					//遍历写入
	{
		outFile.write(itl->account.c_str(), 50);							//生成一个const char*指针，指向以空字符终止的数组
		outFile.write(itl->name.c_str(), 50);								//以每50个字节一个变量写入
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
		cout << "打开文件ActionRecord.dat失败！" << endl;
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
	cout << "正在保存..." << endl;
	Sleep(1000);
	cout << "保存完毕..." << endl;
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

