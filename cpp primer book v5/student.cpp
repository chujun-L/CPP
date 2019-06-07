#include <iostream>
#include "student.h"

using namespace std;

double CBank::m_rate = 2.5;	// 静态成员在类外定义

double CBank::getRate()
{
	return m_rate;
}

double CBank::getDeposit()
{
	return m_deposit;
}

/* 定义构造函数
 *
 * 1、创建CBank的对象时，它会被调用
 */
CBank::CBank()
{
	cout << "CBank类被创建" << endl;
}

//CBank::CBank(double rate)
//{
//	m_rate = rate;
//}

