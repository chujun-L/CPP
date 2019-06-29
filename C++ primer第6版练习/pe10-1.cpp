/*
 *	���һ��������ʾ�����˻������ݳ�Ա���������������˺š���������Աִ�����²�����
 *	1. ����һ�����󲢽����ʼ��
 *	2. ��ʾ�����������˺ż����
 *	3. �������ָ���Ĵ��
 *	4. ȡ������ָ���Ŀ���
 */

#include <iostream>
#include <cstring>

using namespace std;

class BankAccount
{
private:
	char name[40];
	char acctnum[25];
	double balance;

public:
	BankAccount();
	BankAccount(const char *client, const char *num, double bal);
	void show() const;
	void deposit(double cash);
	void withdraw(double cash);
};

BankAccount::BankAccount()
{

}

BankAccount::BankAccount(const char *client, const char *num, double bal)
{
	strncpy_s(name, client, 39);
	name[39] = '\0';
	strncpy_s(acctnum, num, 24);
	acctnum[24] = '\0';
	balance = bal;
}

void BankAccount::show() const
{
	cout << "������" << name << endl;
	cout << "�˺ţ�" << acctnum << endl;
	cout << "��" << balance << endl;
}

void BankAccount::deposit(double cash)
{
	if (cash > 0)
	{
		balance += cash;
	}
	else
	{
		cout << "������������" << endl;
	}
}

void BankAccount::withdraw(double cash)
{
	if (cash > 0 && cash <= balance)
	{
		balance -= cash;
	}
	else if (cash > balance)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "ȡ�����������" << endl;
	}
}

int main()
{
	BankAccount frog("kermit", "croak322", 123.00);
	frog.show();
	frog.deposit(100.0);
	frog.show();
	frog.withdraw(20.5);
	frog.show();

	BankAccount acct;
	acct.show();
	
	system("pause");
	return 0;
}