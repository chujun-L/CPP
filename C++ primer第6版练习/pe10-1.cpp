/*
 *	设计一个类来表示银行账户，数据成员包括储户姓名、账号、存款，函数成员执行如下操作：
 *	1. 创建一个对象并将其初始化
 *	2. 显示储户姓名、账号及存款
 *	3. 存入参数指定的存款
 *	4. 取出参数指定的款项
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
	cout << "姓名：" << name << endl;
	cout << "账号：" << acctnum << endl;
	cout << "存款：" << balance << endl;
}

void BankAccount::deposit(double cash)
{
	if (cash > 0)
	{
		balance += cash;
	}
	else
	{
		cout << "存款金额不能少于零" << endl;
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
		cout << "余额不足" << endl;
	}
	else
	{
		cout << "取款金额不能少于零" << endl;
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