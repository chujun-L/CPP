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
// 递归方式
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
	 * 输入“Jack love Rose”，然后输出“Rose love Jack”
	 * str:         存放输入的句子
	 * tmp, k1, k2: 存放交换的临时变量
	 * i:           扫描整行句子
	 * j:           扫描一个单词
	 */

	char str[256];
	char tmp[1];
	int i = 0, j = 0, k1 = 0, k2 = 0;

	cout << "输入一行英文句子：";
	gets_s(str, sizeof(str));

	while (str[i])
	{
		while (str[i] == ' ') i++;

		j = i;
		while (str[j] != ' ' && str[j] != '\0') j++;			// 统计一个单词里面有几个字母
		for (k1 = i, k2 = j - 1; k1 < k2; k1++, k2--)			// 逆转单词里面的字母
		{
			tmp[0] = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp[0];
		}
		i = j;												// 扫描下一个单词
	}

	for (k1 = 0, k2 = i - 1; k1 < k2; k1++, k2--)				// 逆转整个句子
	{
		tmp[0] = str[k1];
		str[k1] = str[k2];
		str[k2] = tmp[0];
	}

	cout << str << endl;
#endif	//EXERCISE1

#ifdef EXERCISE2
	/*
	 * 输出一个金字塔的‘*’
	 */

	int row = 0;

	cout << "输入行数：";
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
	// 数组作为变量及形参时候的大小判断
	char x[14];
	char *pChar = NULL;

	printf("%d %d\n", sizeof(x), sizeof(pChar));
	

	func(x);
#endif // EXERCISE3

#ifdef EXERCISE4
	// 斐波那契数列(Fibo)，还可以用递归的方式
	int n = 0, i = 0, k1 = 1, k2 = 1, swap = 0;

	cout << "输入大于2的正整数" << endl;
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

