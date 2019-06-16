#include <iostream>
#include <algorithm>
#include <malloc.h>

using namespace std;

#define EXERCISE5

#ifdef EXERCISE3
bool max_min(const int *arry, int size, int *max, int *min)
{
	if (!arry) false;

	const int *p = arry;
	const int *pmin = arry;
	for (int i = 1; i < size; ++i)
	{
		if (*pmin > *(p + i))
		{
			pmin = p + i;		// 前一个数大于后一个数时，将p移动到后一个数
		}						// 相当于找最小值
	}
	*min = *pmin;

	p = arry;
	const int *pmax = arry;
	for (int i = 1; i < size; ++i)
	{
		if (*pmax < * (p + i))
		{
			pmax = p + i;		// 前一个数小于后一个数时，将p移动到后一个数
		}						// 相当于找最大值
	}
	*max = *pmax;

	return true;
}
#endif // !EXERCISE3

#ifdef EXERCISE4
char *str_combine(char *str1, char *str2)
{
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);

	char *rt = (char *)malloc(len_str1 + len_str2 + 1);
	rt = str1;

	for (int i = len_str1, j = 0; j <= len_str2; ++i, ++j)
	{
		*(rt + i) = *(str2 + j);
	}

	return rt;
}
#endif // !EXERCISE3

#ifdef EXERCISE5
void copy_arr(double *target, double *source, int size)
{
	for (int i = 0; i < size; ++i)
	{
		target[i] = source[i];
	}
}

void copy_ptr(double *target, double *source, int size)
{
	for (int i = 0; i < size; ++i)
	{
		*(target + i) = *(source + i);
	}
}

void copy_ptrs(double *target, double *source, double *end)
{
	for (int i = 0; i < (end - source); ++i)
	{
		*(target + i) = *(source + i);
	}
}
#endif // !EXERCISE5


int main()
{
#ifdef EXERCISE1		// 中文字符串反转
	char s[] = "奇牛学院";
	int len = strlen(s);
	char tmp[256];
	char swap[3] = { 0 };

	// 方法1
	for (int i = 0; i < len; i += 2)
	{
		tmp[len - i - 2] = s[i];
		tmp[len - i - 1] = s[i + 1];
	}
	tmp[len] = 0;	// 字符串结束符
	printf("%s\n", tmp);

	// 方法2
	for (int i = 0, len = sizeof(s) - 1;
		i < len / 2;
		i += 2, len -= 2)
	{
		swap[0] = s[len - 2];
		swap[1] = s[len - 1];

		s[len - 2] = s[i];
		s[len - 1] = s[i + 1];

		s[i] = swap[0];
		s[i + 1] = swap[1];
	}
	printf("%s\n", s);
#endif // !EXERCISE1

#ifdef EXERCISE2		// 用指针实现整形数组从小到大的排序
	int a[] = { 4, 2, 5, 1, 8, 3, 10, 6, 4 };
	int *p1 = NULL, *p2 = NULL;
	int tmp = 0;
	int len = sizeof(a) / sizeof(int);


	for (int i = 0; i < len - 1; ++i)
	{
		p1 = a + i;
		p2 = a + i + 1;

		for (int j = 1; j < len - i; ++j)
		{
			if (*p1 > * p2) // 前一个数比后一个数大就交换
			{
				tmp = *p1;
				*p1 = *p2;
				*p2 = tmp;
			}
			++p2;
		}
	}

	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
#endif // !EXERCISE2

#ifdef EXERCISE3		// 计算一个数组中的最大值和最小值
	int arry[] = { 4, 2, 3, 5, 1, 8, 6 };
	int size = sizeof(arry) / sizeof(int);
	int max = 0, min = 0;

	max_min(arry, size, &max, &min);
	printf("max: %d min: %d\n", max, min);
#endif // !EXERCISE3

#ifdef EXERCISE4		// 连接两个字符串
	char str1[] = "hello";
	char str2[] = "world";

	char *str = str_combine(str1, str2);
	printf("%s\n", str);
#endif // !EXERCISE4

#ifdef EXERCISE5		// 用指针对数组的拷贝
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5] = {0};
	double target2[5] = {0};
	double target3[5] = {0};

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << target3[i] << " ";
	}
	cout << endl;

#endif // !EXERCISE5

	system("pause");
	return 0;
}