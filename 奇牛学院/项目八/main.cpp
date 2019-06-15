#include <iostream>
#include <algorithm>
using namespace std;

#define EXERCISE1

int main()
{
#ifdef EXERCISE1
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

	return 0;
}