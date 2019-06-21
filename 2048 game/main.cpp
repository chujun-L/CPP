#include <graphics.h>
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
	setfillcolor(LIGHTGREEN);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
}

int main(void)
{
	initGameScreen();
	Game2048 game;

	game.drawGameScreen();

	system("pause");
	closegraph();
	return 0;
}