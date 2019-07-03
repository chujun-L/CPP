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

	// ��ʼ����Ϸ
	game->init(game);

	// ���̼��
	do {

		Sleep(100);
	} while (1);

	// ������Ϸ
	game->end(game);
	return 0;
}