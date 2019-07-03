#include <graphics.h>
#include "../include/box_man.h"
#include "../include/map.h"

void init_game_screen(struct game_screen *game)
{
	IMAGE img_role[role_num];
	
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	loadimage(&img_role[wall], _T("img/wall.bmp"));
	loadimage(&img_role[floor], _T("img/floor.bmp"));
	loadimage(&img_role[anchor], _T("img/anchor.bmp"));
	loadimage(&img_role[man], _T("img/man.bmp"));
	loadimage(&img_role[box], _T("img/box.bmp"));

	// 填充游戏画面的角色
	for (int i = 0; i < ROWS * COLS; ++i)
	{
		int role = *(game->map + i);
		putimage(i % COLS * PIXEL, i / COLS * PIXEL, &img_role[role]);
	}

}

void end_game_screen(struct game_screen *game)
{
	free(game);
	closegraph();
}