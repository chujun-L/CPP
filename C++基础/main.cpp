#include <iostream>
#include <stdio.h>
using namespace std;

#define EXERCISE4

#ifdef EXERCISE3
void func(char x[10])
{
	printf("%d\n", sizeof(x));
}
#endif // EXERCISE3

#ifdef EXERCISE4
// �ݹ鷽ʽ
int Fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;

	return Fibo(n - 1) + Fibo(n - 2);
}
#endif // EXERCISE4


int main()
{
#ifdef EXERCISE1
	/*
	 * ���롰Jack love Rose����Ȼ�������Rose love Jack��
	 * str:         �������ľ���
	 * tmp, k1, k2: ��Ž�������ʱ����
	 * i:           ɨ�����о���
	 * j:           ɨ��һ������
	 */

	char str[256];
	char tmp[1];
	int i = 0, j = 0, k1 = 0, k2 = 0;

	cout << "����һ��Ӣ�ľ��ӣ�";
	gets_s(str, sizeof(str));

	while (str[i])
	{
		while (str[i] == ' ') i++;

		j = i;
		while (str[j] != ' ' && str[j] != '\0') j++;			// ͳ��һ�����������м�����ĸ
		for (k1 = i, k2 = j - 1; k1 < k2; k1++, k2--)			// ��ת�����������ĸ
		{
			tmp[0] = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp[0];
		}
		i = j;												// ɨ����һ������
	}

	for (k1 = 0, k2 = i - 1; k1 < k2; k1++, k2--)				// ��ת��������
	{
		tmp[0] = str[k1];
		str[k1] = str[k2];
		str[k2] = tmp[0];
	}

	cout << str << endl;
#endif	//EXERCISE1

#ifdef EXERCISE2
	/*
	 * ���һ���������ġ�*��
	 */

	int row = 0;

	cout << "����������";
	cin >> row;

	for (int i = 0; i < row; i++)
	{
		for (int blank = 0; blank < row - i; blank++)
		{
			cout << " ";
		}

		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
#endif // EXERCISE2

#ifdef EXERCISE3
	// ������Ϊ�������β�ʱ��Ĵ�С�ж�
	char x[14];
	char *pChar = NULL;

	printf("%d %d\n", sizeof(x), sizeof(pChar));
	

	func(x);
#endif // EXERCISE3

#ifdef EXERCISE4
	// 쳲���������(Fibo)���������õݹ�ķ�ʽ
	int n = 0, i = 0, k1 = 1, k2 = 1, swap = 0;

	cout << "�������2��������" << endl;
	cin >> n;
	//cout << "1 1 ";

	//for (i = 3; i <= n; i++)
	//{
	//	swap = k1 + k2;
	//	k1 = k2;
	//	k2 = swap;
	//	cout << swap << " ";
	//}
	//cout << endl;

	cout << Fibo(n) << endl;

#endif // EXERCISE4

	system("pause");
	return 0;
}

