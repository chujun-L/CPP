#include "student.h"

double CBank::rate = 2.5;	// 静态成员在类外定义

double CBank::getRate()
{
	return this->rate;
}

