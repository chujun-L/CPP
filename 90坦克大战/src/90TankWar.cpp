#include <iostream>
#include "../include/Tank.h"
#include "../include/map.h"

int main()
{
	menu();
	captureMouse();
	init_map(&map[0][0], ROWS, COLS);

	system("pause");
	closegraph();
	return 0;
}