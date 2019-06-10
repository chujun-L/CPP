#include <iostream>
#include <graphics.h>
#include "../include/Tank.h"
#include "../include/map.h"
#include "../include/bullet.h"

int main()
{
	int key = 0;
	int *pmap = &map[0][0];
	bullet_s tank_bullet;			// 主战坦克的子弹
	tank_s *ptank = &my_tank;

	void (*pfunc[])() = { move_up, move_down, move_left, move_right };

	menu();
	captureMouse();

	/* 初始化地图 */
	init_map(&map[0][0], ROWS, COLS);

	/* 初始化主战坦克 */
	init_tank(TANK_POSITION_X, TANK_POSITION_Y);

	while (1)
	{
		key = keyboad_to_int();
		if (key >= 0 && key <= 3)
		{
			pfunc[key]();
		}
		else if (key == 4)
		{
			ptank->fire_bullet(&tank_bullet);
		}
	}
	//system("pause");
	closegraph();
	return 0;
}