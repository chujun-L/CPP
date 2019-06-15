#include <iostream>
#include <algorithm>
using namespace std;

#define EXERCISE2	

int main()
{
#ifdef EXERCISE1		// �����ַ�����ת
	char s[] = "��ţѧԺ";
	int len = strlen(s);
	char tmp[256];
	char swap[3] = { 0 };
	
	// ����1
	for (int i = 0; i < len; i += 2)
	{
		tmp[len - i - 2] = s[i];
		tmp[len - i - 1] = s[i + 1];
	}
	tmp[len] = 0;	// �ַ���������
	printf("%s\n", tmp);

	// ����2
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

#ifdef EXERCISE2		// ��ָ��ʵ�����������С���������
	int a[] = {4, 2, 5, 1, 8, 3, 10, 6, 4};
	int *p1 = NULL, *p2 = NULL;
	int tmp = 0;
	int len = sizeof(a) / sizeof(int);


	for (int i = 0; i < len - 1; ++i)
	{
		p1 = a + i;
		p2 = a + i + 1;

		for (int j = 1; j < len - i; ++j)
		{
			if (*p1 > * p2) // ǰһ�����Ⱥ�һ������ͽ���
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
#endif // EXERCISE2


	return 0;
}