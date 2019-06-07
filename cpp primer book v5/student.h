#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>

using namespace std;

class CBank {
public:
	double getRate();
	double getDeposit();
	CBank();					// 声明构造函数
	//CBank(double rate);		// 声明带参数的构造函数
	CBank(double deposit) : m_deposit(deposit) { cout << "deposit" << endl; }	// 初始化列表

private:
	static double m_rate;		// 用static声明rate为静态成员
	double m_deposit;
};

#endif // !_STUDENT_H

