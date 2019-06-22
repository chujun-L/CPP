#include <graphics.h>
#include <ctime>
#include "game.h"

void initGameScreen()
{
	/* 设置游戏画面的大小 */
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	/* 字体设置 */
	settextstyle(FONT_HEIGHT, 0, _T("黑体"));
	setbkmode(TRANSPARENT);

	/* 格子设置 */
	settextcolor(BLACK);
	setfillcolor(LIGHTGRAY);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);

	/* 得分牌 */
	fillrectangle(260, 0, 340, 240);
	//outtextxy(270, 0, "score"); 
	//outtextxy(270, 80, "▲");

	/* 随机数种子 */
	srand((unsigned)time(NULL));
}

int main(void)
{
	initGameScreen();
	Game2048 game;

	do {
		game.drawGameScreen();
		game.processKeysCode();

	} while (GS_QUIT != game.getGameStatus());

	closegraph();
	return 0;
}