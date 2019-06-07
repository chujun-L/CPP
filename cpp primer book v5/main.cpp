#include <iostream>
#include "student.h"

using namespace std;



int main()
{
	CBank bank(260.6);
	double deposit = 0;

	deposit = bank.getDeposit();

	cout << "deposit: " << deposit << endl;

	

	return 0;
}