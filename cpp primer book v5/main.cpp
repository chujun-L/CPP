#include <iostream>
#include "student.h"

using namespace std;



int main()
{
	CBank bank;
	double rate = 0;

	rate = bank.getRate();

	cout << "rate: " << rate << endl;

	return 0;
}