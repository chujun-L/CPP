#include <graphics.h>
#include "../include/box_man.h"
#include "../include/map.h"

IMAGE img_role[role_num];

// 角色图片的路径
const TCHAR *img_role_path[] = { _T("img/wall.bmp"),
								_T("img/floor.bmp"),
								_T("img/anchor.bmp"),
								_T("img/man.bmp"),
								_T("img/box.bmp") };

void draw_screen(struct game_screen *game)
{
	for (int i = 0; i < ROWS * COLS; ++i)
	{
		int role = *(game->map + i);
		putimage(i % COLS * PIXEL, i / COLS * PIXEL, &img_role[role]);
	}
}

void init_game_screen(struct game_screen *game)
{
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	// 加载角色的图片
	for (int i = 0; i < role_num; ++i)
	{
		loadimage(&img_role[i], img_role_path[i]);
	}

	// 填充游戏画面的角色
	draw_screen(game);
}

void end_game_screen(struct game_screen *game)
{
	free(game);
	closegraph();
}

void get_man_pos(struct game_man *gman)
{
	for (int i = 0; i < ROWS * COLS; ++i)
	{
		if (man == *(gman->map + i))
		{
			gman->pos_x = i % COLS;
			gman->pos_y = i / COLS;
		}
	}
}

void walk_right(struct game_man *gman)
{
	get_man_pos(gman);

	// 1、如果小人(man)右边是地板(floor)，则直接走动
	if (map[gman->pos_y][gman->pos_x + 1] == floor)
	{
		map[gman->pos_y][gman->pos_x] = floor;
		map[gman->pos_y][gman->pos_x + 1] = man;
	}
	// 2、如果小人(man)右边是箱子(box)而且箱子的右边不是墙(wall)，则推着箱子走动
	else if (map[gman->pos_y][gman->pos_x + 1] == box &&
			 map[gman->pos_y][gman->pos_x + 2] != wall)
	{
		map[gman->pos_y][gman->pos_x] = floor;
		map[gman->pos_y][gman->pos_x + 1] = man;
		map[gman->pos_y][gman->pos_x + 2] = box;
	}
}