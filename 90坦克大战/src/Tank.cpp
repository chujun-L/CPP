#include "../include/Tank.h"

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