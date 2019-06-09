#include <iostream>
#include "../include/Tank.h"
#include "../include/map.h"

int main()
{
	menu();
	captureMouse();

	/* 初始化地图 */
	init_map(&map[0][0], ROWS, COLS);

	/* 初始化主战坦克 */
	init_tank(TANK_POSITION_X, TANK_POSITION_Y);

	system("pause");
	closegraph();
	return 0;
}