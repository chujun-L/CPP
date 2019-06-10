#include <graphics.h>
#include "../include/bullet.h"

/* 子弹飞行过程中对前一个位置进行隐藏 */
void bullet_blink(int left, int top, int right, int bottom)
{
	setfillcolor(WHITE);
	solidrectangle(left, top, right, bottom);
	Sleep(150);
	setfillcolor(BLACK);
	solidrectangle(left, top, right, bottom);
}

/* 子弹飞行 */
void bullet_fly(DIRECTION dir, int left, int top, int right, int bottom)
{
	switch (dir)
	{
	case UP:
		break;
	case DOWN:
		break;
	case LEFT:
		while (left > 0)
		{
			bullet_blink(left, top, right, bottom);
			left -= 8;
			right -= 8;
		}	
		break;
	case RIGHT:
		break;
	default:
		break;
	}
}

/*
 * 发射子弹
 * 
 * bullet: 要发射的子弹
 */
void fire_bullet(bullet_s *bullet)
{
	tank_s *tank = &my_tank;

	/* 根据主战坦克的方向来计算子弹的初始坐标 */
	switch (tank->dir)
	{
	case UP:
		bullet->pos_x = tank->x * 25 + 23;
		bullet->pos_y = tank->y * 25 - 4;
		break;
	case DOWN:
		bullet->pos_x = tank->x * 25 + 23;
		bullet->pos_y = tank->y * 25 + 50;
		break;
	case LEFT:
		bullet->pos_x = tank->x * 25 - 4;
		bullet->pos_y = tank->y * 25 + 23;
		break;
	case RIGHT:
		bullet->pos_x = tank->x * 25 + 50;
		bullet->pos_y = tank->y * 25 + 23;
		break;
	default:
		break;
	}

	bullet->dir = tank->dir;
	bullet->status = 1;

	bullet_fly(bullet->dir, bullet->pos_x, bullet->pos_y, bullet->pos_x + 4, bullet->pos_y + 4);
}
