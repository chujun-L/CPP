#include <stdio.h>

#define TEST7


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
	system("pause");
	return 0;
}