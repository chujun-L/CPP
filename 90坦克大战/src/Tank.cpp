#include "../include/Tank.h"

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
	assert(flag == 200);

	*(map + (y * ROWS + x)) = flag;
	*(map + (y * ROWS + (x + 1))) = flag;
	*(map + ((y + 1) * ROWS + x)) = flag;
	*(map + ((y + 1) * ROWS + (x + 1))) = flag;
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
	tank_s my_tank;
	my_tank.x = x;
	my_tank.y = y;
	my_tank.live = 1;
	my_tank.dir = UP;

	/* 加载主战坦克运动的4个方向的图片 */
	IMAGE my_tank_img[4];
	loadimage(&my_tank_img[UP], _T("Img/tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[DOWN], _T("Img/tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[LEFT], _T("Img/tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[RIGHT], _T("Img/tank_right.jpg"), 50, 50);

	/* 设置主战坦克的坐标并显示 */
	set_prop_map(&map[0][0], my_tank.x, my_tank.y, 200);
	putimage(my_tank.x * 25, my_tank.y * 25, &my_tank_img[my_tank.dir]);
}