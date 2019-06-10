#include <assert.h>
#include <graphics.h>
#include <conio.h>
#include "../include/Tank.h"
#include "../include/bullet.h"

tank_s my_tank;
IMAGE my_tank_img[4];

/*
 * 显示游戏开始的界面
 */
void menu()
{
	initgraph(650, 650);							// 画布大小

	IMAGE logoImg;								// Tank logo
	loadimage(&logoImg, _T("Img/logo.bmp"));
	putimage(110, 20, &logoImg);

	setlinecolor(WHITE);							// 说明按键的边框
	setfillcolor(BLACK);
	fillrectangle(230, 200, 310, 240);
	settextcolor(WHITE);							// 显示“说明”
	settextstyle(25, 0, _T("宋体"));
	outtextxy(245, 210, _T("说明"));

	fillrectangle(350, 200, 430, 240);				// 开始按键的边框
	outtextxy(365, 210, _T("开始"));				// 显示“开始”
}

/*
 * 捕获鼠标点击的事件，对说明及开始按键进行响应
 */
void captureMouse()
{
	MOUSEMSG mouse;
	IMAGE illustrate;
	loadimage(&illustrate, _T("Img/illustrate.jpg"));

	while (1 == 1)
	{
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
		case WM_LBUTTONDOWN:
			/* 说明按键 */
			if (mouse.x > 230 && mouse.x < 310 && mouse.y > 200 && mouse.y < 240)
			{
				putimage(150, 250, &illustrate);		//显示说明
			}
			else
			{
				solidrectangle(150, 250, 450, 550);	//遮挡说明
			}

			/* 开始按键 */
			if (mouse.x > 350 && mouse.x < 430 && mouse.y > 200 && mouse.y < 240)
			{
				cleardevice();
				return;
			}
			break;

		default:
			break;
		}
	}
}

/*
 * 初始化地图
 *
 *        map： 要初始化的地图
 * rows, cols： 地图的行数、列数
 */
void init_map(int *map, int rows, int cols)
{
	IMAGE img_home, img_wall_1, img_wall_2;
	loadimage(&img_home, _T("Img/home.jpg"), 50, 50);
	loadimage(&img_wall_1, _T("Img/wall1.jpg"), 25, 25);
	loadimage(&img_wall_2, _T("Img/wall2.jpg"), 25, 25);

	/* 画地图 */
	for (int i = 0; i < rows * cols; ++i)
	{
		int rt = *(map++);

		switch (rt)
		{
		case 1:
			putimage(25 * (i % cols), 25 * (i / rows), &img_wall_1);	// 可消失的墙
			break;
		case 2:
			putimage(25 * (i % cols), 25 * (i / rows), &img_wall_2);	// 不可消失的墙
			break;
		case 3:
			putimage(25 * (i % cols), 25 * (i / rows), &img_home);		// 老鹰的图案
			break;
		default:
			break;
		}
	}
}

/*
 * 在地图上标记主战坦克初始化的位置
 *
 *  map:	地图的首地址，&map[0][0]
 * x, y: 主战坦克初始化的位置坐标
 * flag: 主战坦克的标记为200
 */
void set_prop_map(int *map, int x, int y, int flag)
{
	assert(map != NULL);

	*(map + (y * COLS + x)) = flag;
	*(map + (y * COLS + (x + 1))) = flag;
	*(map + ((y + 1) * COLS + x)) = flag;
	*(map + ((y + 1) * COLS + (x + 1))) = flag;
}

/*
 * 根据坐标获取在地图上标记的值
 *
 *  map:	地图的首地址，&map[0][0]
 *  x,y: 地图的坐标
 */
int get_prop_map(int *map, int x, int y)
{
	return *(map + (y * COLS + x));
}

/*
 * 初始化主战坦克
 *
 * x，y: 主战坦克在地图出现的坐标
 */
void init_tank(int x, int y)
{
	assert(x < COLS);
	assert(y < ROWS);

	/* 初始化主战坦克的结构体 */
	my_tank.x = x;
	my_tank.y = y;
	my_tank.live = 1;
	my_tank.dir = UP;
	my_tank.fire_bullet = fire_bullet;

	/* 加载主战坦克运动的4个方向的图片 */
	loadimage(&my_tank_img[UP], _T("Img/tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[DOWN], _T("Img/tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[LEFT], _T("Img/tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[RIGHT], _T("Img/tank_right.jpg"), 50, 50);

	/* 设置主战坦克的坐标并显示 */
	set_prop_map(&map[0][0], my_tank.x, my_tank.y, 200);
	putimage(my_tank.x * 25, my_tank.y * 25, &my_tank_img[my_tank.dir]);
}

/*
 * 坦克移动
 *
 * tank: 要移动的坦克
 *  dir: 移动的方向
 *  img: 坦克移动方向的图片
 */
void tank_walk(tank_s *tank, DIRECTION dir, IMAGE *img)
{
	/* 清除主战坦克坐标标记并用黑色方框填充移动轨迹 */
	set_prop_map(&map[0][0], tank->x, tank->y, 0);
	setfillcolor(BLACK);
	solidrectangle(tank->x * 25, tank->y * 25,
		tank->x * 25 + 50, tank->y * 25 + 50);

	/* 更新tank的坐标 */
	switch (dir)
	{
	case UP:
		tank->y -= 1;
		break;
	case DOWN:
		tank->y += 1;
		break;
	case LEFT:
		tank->x -= 1;
		break;
	case RIGHT:
		tank->x += 1;
		break;
	default:
		break;
	}

	/* 设置主战坦克坐标标记并沿轨迹放置图标 */
	set_prop_map(&map[0][0], tank->x, tank->y, 200);
	putimage(tank->x * 25, tank->y * 25, img);
}

/* 将检测到的键盘按下的键值转换成整形数据 */
int keyboad_to_int()
{
	int keyboard = 0;

	if (_kbhit())
	{
		keyboard = _getch();

		switch (keyboard)
		{
		case 'w':		// 上
			return 0;
			break;
		case 's':		// 下
			return 1;
			break;
		case 'a':		// 左
			return 2;
			break;
		case 'd':		// 右
			return 3;
			break;
		case 'j':		// 发射子弹
			return 4;
			break;
		default:
			break;
		}
	}

	return -1;
}

void move_now(int val, int cmp, int *pmap, DIRECTION dir,
	int x, int y, int new_x, int new_y)
{
	if (val > cmp &&
		get_prop_map(pmap, x, y) == 0 &&
		get_prop_map(pmap, new_x, new_y) == 0)
	{
		my_tank.dir = dir;
		tank_walk(&my_tank, my_tank.dir, &my_tank_img[my_tank.dir]);
	}
}

void move_up()
{
	move_now(my_tank.y, 0, &map[0][0], UP,
		my_tank.x, my_tank.y - 1, my_tank.x + 1, my_tank.y - 1);
}

void move_down()
{
	move_now(ROWS - 2, my_tank.y, &map[0][0], DOWN,
		my_tank.x, my_tank.y + 2, my_tank.x + 1, my_tank.y + 2);
}

void move_left()
{
	move_now(my_tank.x, 0, &map[0][0], LEFT,
		my_tank.x - 1, my_tank.y, my_tank.x - 1, my_tank.y + 1);
}

void move_right()
{
	move_now(COLS - 2, my_tank.x, &map[0][0], RIGHT,
		my_tank.x + 2, my_tank.y, my_tank.x + 2, my_tank.y + 1);
}