#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TEST11

#ifdef TEST8
struct mybitfields
{
	unsigned short a : 4;
	unsigned short b : 5;
	unsigned short c : 7;
};
#endif // TEST8

#ifdef TEST10
char *MyStrcpy(char *cDest, const char *cSrc, int nSize)
{
	assert(cDest);
	assert(cSrc);

	char *ret = cDest;

	// 有溢出风险
	//while (*cDest++ = *cSrc++);
	//{
	//	cDest++;
	//	cSrc++;
	//}

	while (nSize)
	{
		*cDest++ = *cSrc++;
		nSize--;
	}

	return ret;
}
#endif // TEST10



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

#ifdef TEST10
	//char *cDest = NULL;
	char buf[20];
	char *cSrc = "hello world";
	char *pChar = NULL;

	pChar = MyStrcpy(buf, cSrc, sizeof(buf));

	printf("%s\n", pChar);

#endif // TEST10

#ifdef TEST11

#endif // TEST11


	system("pause");
	return 0;
}