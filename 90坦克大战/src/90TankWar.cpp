#include <iostream>
#include "../include/Tank.h"
#include "../include/map.h"

int main()
{
	menu();
	captureMouse();

	/* ��ʼ����ͼ */
	init_map(&map[0][0], ROWS, COLS);

	/* ��ʼ����ս̹�� */
	init_tank(TANK_POSITION_X, TANK_POSITION_Y);

	system("pause");
	closegraph();
	return 0;
}