#include "../include/Tank.h"

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


