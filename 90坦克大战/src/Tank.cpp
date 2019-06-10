#include <assert.h>
#include <graphics.h>
#include <conio.h>
#include "../include/Tank.h"
#include "../include/bullet.h"

tank_s my_tank;
IMAGE my_tank_img[4];

/*
 * ��ʾ��Ϸ��ʼ�Ľ���
 */
void menu()
{
	initgraph(650, 650);							// ������С

	IMAGE logoImg;								// Tank logo
	loadimage(&logoImg, _T("Img/logo.bmp"));
	putimage(110, 20, &logoImg);

	setlinecolor(WHITE);							// ˵�������ı߿�
	setfillcolor(BLACK);
	fillrectangle(230, 200, 310, 240);
	settextcolor(WHITE);							// ��ʾ��˵����
	settextstyle(25, 0, _T("����"));
	outtextxy(245, 210, _T("˵��"));

	fillrectangle(350, 200, 430, 240);				// ��ʼ�����ı߿�
	outtextxy(365, 210, _T("��ʼ"));				// ��ʾ����ʼ��
}

/*
 * ������������¼�����˵������ʼ����������Ӧ
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
			/* ˵������ */
			if (mouse.x > 230 && mouse.x < 310 && mouse.y > 200 && mouse.y < 240)
			{
				putimage(150, 250, &illustrate);		//��ʾ˵��
			}
			else
			{
				solidrectangle(150, 250, 450, 550);	//�ڵ�˵��
			}

			/* ��ʼ���� */
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
 * ��ʼ����ͼ
 *
 *        map�� Ҫ��ʼ���ĵ�ͼ
 * rows, cols�� ��ͼ������������
 */
void init_map(int *map, int rows, int cols)
{
	IMAGE img_home, img_wall_1, img_wall_2;
	loadimage(&img_home, _T("Img/home.jpg"), 50, 50);
	loadimage(&img_wall_1, _T("Img/wall1.jpg"), 25, 25);
	loadimage(&img_wall_2, _T("Img/wall2.jpg"), 25, 25);

	/* ����ͼ */
	for (int i = 0; i < rows * cols; ++i)
	{
		int rt = *(map++);

		switch (rt)
		{
		case 1:
			putimage(25 * (i % cols), 25 * (i / rows), &img_wall_1);	// ����ʧ��ǽ
			break;
		case 2:
			putimage(25 * (i % cols), 25 * (i / rows), &img_wall_2);	// ������ʧ��ǽ
			break;
		case 3:
			putimage(25 * (i % cols), 25 * (i / rows), &img_home);		// ��ӥ��ͼ��
			break;
		default:
			break;
		}
	}
}

/*
 * �ڵ�ͼ�ϱ����ս̹�˳�ʼ����λ��
 *
 *  map:	��ͼ���׵�ַ��&map[0][0]
 * x, y: ��ս̹�˳�ʼ����λ������
 * flag: ��ս̹�˵ı��Ϊ200
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
 * ���������ȡ�ڵ�ͼ�ϱ�ǵ�ֵ
 *
 *  map:	��ͼ���׵�ַ��&map[0][0]
 *  x,y: ��ͼ������
 */
int get_prop_map(int *map, int x, int y)
{
	return *(map + (y * COLS + x));
}

/*
 * ��ʼ����ս̹��
 *
 * x��y: ��ս̹���ڵ�ͼ���ֵ�����
 */
void init_tank(int x, int y)
{
	assert(x < COLS);
	assert(y < ROWS);

	/* ��ʼ����ս̹�˵Ľṹ�� */
	my_tank.x = x;
	my_tank.y = y;
	my_tank.live = 1;
	my_tank.dir = UP;
	my_tank.fire_bullet = fire_bullet;

	/* ������ս̹���˶���4�������ͼƬ */
	loadimage(&my_tank_img[UP], _T("Img/tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[DOWN], _T("Img/tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[LEFT], _T("Img/tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[RIGHT], _T("Img/tank_right.jpg"), 50, 50);

	/* ������ս̹�˵����겢��ʾ */
	set_prop_map(&map[0][0], my_tank.x, my_tank.y, 200);
	putimage(my_tank.x * 25, my_tank.y * 25, &my_tank_img[my_tank.dir]);
}

/*
 * ̹���ƶ�
 *
 * tank: Ҫ�ƶ���̹��
 *  dir: �ƶ��ķ���
 *  img: ̹���ƶ������ͼƬ
 */
void tank_walk(tank_s *tank, DIRECTION dir, IMAGE *img)
{
	/* �����ս̹�������ǲ��ú�ɫ��������ƶ��켣 */
	set_prop_map(&map[0][0], tank->x, tank->y, 0);
	setfillcolor(BLACK);
	solidrectangle(tank->x * 25, tank->y * 25,
		tank->x * 25 + 50, tank->y * 25 + 50);

	/* ����tank������ */
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

	/* ������ս̹�������ǲ��ع켣����ͼ�� */
	set_prop_map(&map[0][0], tank->x, tank->y, 200);
	putimage(tank->x * 25, tank->y * 25, img);
}

/* ����⵽�ļ��̰��µļ�ֵת������������ */
int keyboad_to_int()
{
	int keyboard = 0;

	if (_kbhit())
	{
		keyboard = _getch();

		switch (keyboard)
		{
		case 'w':		// ��
			return 0;
			break;
		case 's':		// ��
			return 1;
			break;
		case 'a':		// ��
			return 2;
			break;
		case 'd':		// ��
			return 3;
			break;
		case 'j':		// �����ӵ�
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