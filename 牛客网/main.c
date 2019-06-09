#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define NDEBUG
#include <assert.h>

//#define TEST21

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

	while (nSize--)
	{
		*cDest++ = *cSrc++;
		//nSize--;
	}

	return ret;
}
#endif // TEST10

#ifdef TEST14
void func()
{
	// 局部静态变量
	static int i = 0;
	printf("i: %d\n", i++);
}
#endif // TEST14

#ifdef TEST18
// 函数指针数组在菜单选择的用法
void func1(void)
{
	printf("fun1\n");
}	
void func2(void)	
{
	printf("fun2\n");
}	
void func3(void)	
{
	printf("fun3\n");
}	
int show_menu(void)
{
	int n = 0;

	printf("输入1 ~ 3: ");
	scanf("%d", &n);

	return n;
}
#endif // TEST18

#ifdef TEST19
#define trace(x, format) \
	printf(#x "=%" #format "\n", x)		// printf("i=%d\n", i);
#endif // TEST19

#ifdef TEST21
void boyAge(int **pAge)
{
	static int age = 20;	// 没有static修饰，是不安全的
	*pAge = &age;
}
#endif // TEST21

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

	MyStrcpy(buf, cSrc, sizeof(buf));

	printf("%s\n", buf);

#endif // TEST10

#ifdef TEST11
	// 字符串与字符 sizeof()是运算符  strlen()是函数
	char a[] = "ABCDEF";
	char b[] = { 'A','B','C','D','E','F', '\0' };

	printf("strlen a: %d, strlen b: %d\n", strlen(a), strlen(b));
#endif // TEST11

#ifdef TEST12
	// 转义字符
	printf("%%\n");
#endif // TEST12

#ifdef TEST13
	// n的阶乘
	int n = 0, nFac = 1;

	printf("输入一个正整数n，求它的阶乘\n");

	while (1)
	{
		scanf_s("%d", &n);
		if (n < 0)
		{
			printf("输入的数不能为负数\n");
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
	// 断言开关的用法
	int i = 100;
	assert(i < 100);
	i++;

#endif // TEST15

#ifdef TEST16
	// 访问空指针产生段错误 
	int *p = NULL;
	*p = 20;
#endif // TEST16

#ifdef TEST17
	// 指针访问字符串
#if 0	
	char s[] = "desolate", *p = s;
	// *p++, *(p++), (*p)++, *++p, *(++p), ++*p, ++(*p)
	printf("%c\n", ++(*p));
#endif
	// 指针对数据的访问
	int a[] = {10, 15, 4, 25, 3, -4};
	int *p = &a[2];
	// *(p+1), p[-1], p-a, a[*p++], *(a+a[2])
	printf("%d\n", *(a+a[2]));
#endif // TEST17

#ifdef TEST18
	int choice = 0;
	void (*pFuncArray[])(void) = {func1, func2, func3};	// 函数指针数组

	while (1)
	{
		choice = show_menu();
		if (choice >= 1 && choice <= 3)
		{
			pFuncArray[choice - 1]();
		}
		else
		{
			break;
		}
	}
#endif // TEST18

#ifdef TEST19
	// 预处理实现3个功能：1、头文件的包含 2、宏的扩展 3、条件编辑
	// 预定义宏 __FILE__ / __LINE__ / __DATE__ / __TIME__
	// 预处理运算符 #  ##  Defined
	int i = 1;
	float x = 2.0;
	char *s = "three";

	trace(i, d);
	trace(x, f);
	trace(s, s);	
#endif // TEST19

#ifdef TEST20
    int x, y;
    scanf("%d,%d", &x, &y);
    printf("x: %d, y: %d\n", x, y);
#endif // TEST20

#ifdef TEST21
	int *p = NULL;
	boyAge(&p);
	printf("boy age: %d\n", *p);	
#endif // TEST21

#ifdef TEST22
	int arry[10];
	printf("%d\n", (int)sizeof(arry));
#endif // TEST22

	return 0;
}
