#include <stdio.h>

#define TEST7


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
	system("pause");
	return 0;
}