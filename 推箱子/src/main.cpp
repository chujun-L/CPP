#include <malloc.h>
#include <Windows.h>
#include "../include/box_man.h"
#include "../include/map.h"



int main()
{
	struct game_screen *game = (struct game_screen *)malloc(sizeof(struct game_screen));

	if (game)
	{
		game->s_width = SCREEN_WIDTH;
		game->s_height = SCREEN_HEIGHT;
		game->map = &map[0][0];
		game->init = init_game_screen;
		game->end = end_game_screen;
	}
	else
	{
		exit(-1);
	}

	// ³õÊ¼»¯ÓÎÏ·
	game->init(game);

	// ¼üÅÌ¼ì²â
	do {

		Sleep(100);
	} while (1);

	// ½áÊøÓÎÏ·
	game->end(game);
	return 0;
}