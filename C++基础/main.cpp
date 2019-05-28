#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

#define EXERCISE5

#ifdef EXERCISE3
void func(char x[10])
{
	printf("%d\n", sizeof(x));
}
#endif // EXERCISE3

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

	printf("%d\n", sizeof(x));

	func(x);
#endif // EXERCISE3

#ifdef EXERCISE4
	// ָ����ʶ�ά����
	int nArry[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	int *pArry = &nArry[0][0];
	cout << *(pArry + 5) << endl;

#endif // EXERCISE4

#ifdef EXERCISE5
#define NUM  10
	// �������(�ֽ�ɶ�ά����)
	int nYHTriangle[NUM][NUM] = { 0 };

	// ����������ǵ���ֵ
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				nYHTriangle[i][j] = 1;
			}
			else
			{
				nYHTriangle[i][j] = nYHTriangle[i - 1][j - 1] + nYHTriangle[i - 1][j];
			}

		}
	}

	// ��ʽ�����
	for (int i = 0; i < NUM; i++)
	{
		cout << setw((NUM - i) * 3) << nYHTriangle[i][0];

		for (int j = 1; j <= i; j++)
		{
			cout << setw(6) << nYHTriangle[i][j];
		}
		cout << endl;
	}
#endif // EXERCISE5

	system("pause");
	return 0;
}