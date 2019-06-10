#include <iostream>
#include <conio.h>
#include <graphics.h>
#include "../include/Tank.h"
#include "../include/map.h"

int main()
{
	int key_board = 0;
	int *pmap = &map[0][0];

	menu();
	captureMouse();

	/* 初始化地图 */
	init_map(&map[0][0], ROWS, COLS);

	/* 初始化主战坦克 */
	init_tank(TANK_POSITION_X, TANK_POSITION_Y);

	while (1)
	{
		if (_kbhit())	// 是否有按键按下
		{
			key_board = _getch();
			switch (key_board)
			{
			case 'a':	// 左
				if ((my_tank.x) > 0 &&
					*(pmap + (my_tank.y * COLS + (my_tank.x - 1))) == 0 &&
					*(pmap + ((my_tank.y + 1) * COLS + (my_tank.x - 1))) == 0)
				{
					my_tank.dir = LEFT;
					tank_walk(&my_tank, my_tank.dir, &my_tank_img[my_tank.dir]);
				}
				break;
			case 'd':	// 右
				break;
			case 'w':	// 上
				break;
			case 's':	// 下
				break;
			default:
				break;
			}
		}
	}
	//system("pause");
	closegraph();
	return 0;
}