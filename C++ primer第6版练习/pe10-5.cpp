#include <iostream>
#include "pe10-5stack.h"

using namespace std;

void get_customer(customer &cu)
{
	cout << "输入客户的姓名：";
	//cin.getline(cu.fullname, 35);
	cin >> cu.fullname;

	cout << "输入客户的付款：";
	cin >> cu.payment;
}

int main()
{
	Stack st;
	customer tmp;
	double payment = 0;
	char key;

	while (1)
	{
		cin >> key;
		switch (key)
		{
		case 'a':		// push
			//cout << "press a" << endl;
			get_customer(tmp);
			st.push(tmp);
			break;
		case 'p':		// pop
			//cout << "press p" << endl;
			st.pop(tmp);
			cout << tmp.fullname << " " << tmp.payment << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}