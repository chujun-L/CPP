#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define NDEBUG
#include <assert.h>

#define TEST15

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

	// ���������
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

#ifdef TEST14
void func()
{
	// �ֲ���̬����
	static int i = 0;
	printf("i: %d\n", i++);
}
#endif // TEST14


int main()
{
#ifdef TEST7
	// ָ�������
	// char: 1���ֽ�  int: 4���ֽ�   long: 4���ֽ�  ��32λ����
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
	// �ַ������ַ� sizeof()�������  strlen()�Ǻ���
	char a[] = "ABCDEF";
	char b[] = { 'A','B','C','D','E','F', '\0' };

	printf("strlen a: %d, strlen b: %d\n", strlen(a), strlen(b));
#endif // TEST11

#ifdef TEST12
	// ת���ַ�
	printf("%%\n");
#endif // TEST12

#ifdef TEST13
	// n�Ľ׳�
	int n = 0, nFac = 1;
	
	printf("����һ��������n�������Ľ׳�\n");

	while (1)
	{
		scanf_s("%d", &n);
		if (n < 0)
		{
			printf("�����������Ϊ����\n");
		}
		else if ( n == 1)
		{
			printf("1\n");
			exit(0);
		}
		else
		{
			break;
		}
			
	}
	
	for (int i = 1; i != n + 1; i++)
	{
		nFac *= i;
		printf("%d ", nFac);
	}
	printf("\n");
#endif // TEST13

#ifdef TEST14
	func();
	func();
	func();
#endif // TEST14

#ifdef TEST15
    // ���ԵĿ����÷�
    int i = 100;
    assert(i < 100);
    i++;

#endif // TEST15

	return 0;
}