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

	/* ��ʼ����ͼ */
	init_map(&map[0][0], ROWS, COLS);

	/* ��ʼ����ս̹�� */
	init_tank(TANK_POSITION_X, TANK_POSITION_Y);

	while (1)
	{
		if (_kbhit())	// �Ƿ��а�������
		{
			key_board = _getch();
			switch (key_board)
			{
			case 'a':	// ��
				if (my_tank.x > 0 &&
					get_prop_map(pmap, my_tank.x - 1, my_tank.y) == 0 &&
					get_prop_map(pmap, my_tank.x - 1, my_tank.y + 1) == 0)
				{
					my_tank.dir = LEFT;
					tank_walk(&my_tank, my_tank.dir, &my_tank_img[my_tank.dir]);
				}
				break;
			case 'd':	// ��
				if (my_tank.x < COLS - 2 &&
					get_prop_map(pmap, my_tank.x + 2, my_tank.y) == 0 &&
					get_prop_map(pmap, my_tank.x + 2, my_tank.y + 1) == 0)
				{
					my_tank.dir = RIGHT;
					tank_walk(&my_tank, my_tank.dir, &my_tank_img[my_tank.dir]);
				}
				break;
			case 'w':	// ��
				if (my_tank.y > 0 &&
					get_prop_map(pmap, my_tank.x, my_tank.y - 1) == 0 &&
					get_prop_map(pmap, my_tank.x + 1, my_tank.y - 1) == 0)
				{
					my_tank.dir = UP;
					tank_walk(&my_tank, my_tank.dir, &my_tank_img[my_tank.dir]);
				}
				break;
			case 's':	// ��
				if (my_tank.y < ROWS - 2 &&
					get_prop_map(pmap, my_tank.x, my_tank.y + 2) == 0 &&
					get_prop_map(pmap, my_tank.x + 1, my_tank.y + 2) == 0)
				{
					my_tank.dir = DOWN;
					tank_walk(&my_tank, my_tank.dir, &my_tank_img[my_tank.dir]);
				}
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