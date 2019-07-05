#include <malloc.h>
#include <Windows.h>
#include <conio.h>
#include "../include/box_man.h"
#include "../include/map.h"


void process_keyboard_code(struct game_man *man)
{
	int keys_code = _getch();

	switch (keys_code)
	{
	case 72:			// 向上
		break;
	case 75:			// 向左
		break;
	case 77:			// 向右
		if (man->status == MOVE)
		{
			man->walk_right(man);
		}
		break;
	case 80:			// 向下
		break;
	case 'q':		// 退出游戏
		man->status = QUIT;
		break;
	}
}

int main()
{
	struct game_screen *game = (struct game_screen *)malloc(sizeof(struct game_screen));
	struct game_man *man = (struct game_man *)malloc(sizeof(struct game_man));

	if (game && man)
	{
		//game->status = true;
		game->s_width = SCREEN_WIDTH;
		game->s_height = SCREEN_HEIGHT;
		game->map = &map[0][0];
		//game->man = man;
		game->init = init_game_screen;
		game->end = end_game_screen;
		game->refresh = draw_screen;

		//man->get_pos = get_man_pos;
		man->status = MOVE;
		man->map = &map[0][0];
		man->walk_right = walk_right;
	}
	else
	{
		exit(-1);
	}

	// 初始化游戏
	game->init(game);

	// 键盘检测
	do {
		process_keyboard_code(man);
		game->refresh(game);
		Sleep(100);

	} while (man->status);

	// 结束游戏
	game->end(game);
	return 0;
}