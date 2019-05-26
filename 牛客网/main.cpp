#include <stdio.h>

#define TEST2

int main()
{
#ifdef TEST1
	char *a = "you", b[] = "welcome # you # to # china!";
	int i, j = 0; char *p = NULL;

	for (i = 0; b[i] != '\0'; i++)
	{
		if (*a == b[i])
		{
			p = &b[i];

			for (j = 0; a[j] != '\0'; j++)
			{
				if (a[j] != *p)
					break;

				p++;
			}
			if (a[j] != '\0')
				break;
		}
	}
	printf("%c\n", a[0]);
	printf("%s\n", p);
#endif // TEST1

#ifdef TEST2
	int n[3][3], i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			n[i][j] = i + j;
			printf("%d\n", n[i][j]);
		}
	printf("-------------\n");


	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
		{
			n[i + 1][j + 1] += n[i][j];
			printf("%d\n", n[i + 1][j + 1]);
		}
	printf("-------------\n");

	printf("%d\n", n[i][j]);
#endif // TEST2

#ifdef TEST3
	int a[] = { 1, 2, 3, 4 };
	int *b = a;

	printf("%d\n", *b);
	printf("%d\n", *(b + 1));
	*b += 2;
	printf("%d\n", *b);
	*(b + 2) = 2;

	b++;

	printf("%d, %d\n", *b, *(b + 2));
#endif // TEST3

#ifdef TEST4
	// volatile 防止编译器的优化而省略的代码
	volatile int *p = (int *)0xaae0275; *p = 1;
	volatile int *p = (int *)0xaae0275; p[0] = 1;
	(volatile int *)0xaae0275[0] = 1;
	((volatile int *)0xaae0275)[0] = 1;
	(volatile int *)0xaae0275 = 1;
#endif // TEST4


	return 0;
}