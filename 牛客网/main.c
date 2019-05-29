#include <stdio.h>

#define TEST9

#ifdef TEST8
struct mybitfields
{
	unsigned short a : 4;
	unsigned short b : 5;
	unsigned short c : 7;
};
#endif // TEST8


int main()
{
#ifdef TEST7
	// 指针的类型
	// char: 1个字节  int: 4个字节   long: 4个字节  （32位机）
	char *p = "abcdefg", *r;

	long *q;

	q = (long *)p;

	q++;

	r = (char *)q;

	printf("%s, %d\n", r, sizeof(long));

#endif // TEST7

#ifdef TEST8
	struct mybitfields test;
	int i = 0;

	test.a = 2;
	test.b = 3;
	test.c = 0;

	i = *((short *)& test);
	printf("%d\n", i);
#endif // TEST8

#ifdef TEST9
	int nCount = 0;
	int x = 9999;

	while (x)
	{
		nCount++;
		x = x & (x - 1);
	}

	printf("%d\n", nCount);
#endif // TEST9


	system("pause");
	return 0;
}