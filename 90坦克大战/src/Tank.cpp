#include "../include/Tank.h"

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