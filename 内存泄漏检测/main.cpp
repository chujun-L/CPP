#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <crtdbg.h>
#include <Windows.h>

#ifdef _DEBUG
#ifndef DBG_NEW

#define DBG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW

#endif // !DBG_NEW
#endif // _DEBUG

int main()
{
	for (int i = 0; i < 5; ++i) {
		int *arry = new int[10];
	}

	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}
