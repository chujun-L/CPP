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
	case 72:			// ����
		break;
	case 75:			// ����
		break;
	case 77:			// ����
		if (man->status == MOVE)
		{
			man->walk_right(man);
		}
		break;
	case 80:			// ����
		break;
	case 'q':		// �˳���Ϸ
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

	// ��ʼ����Ϸ
	game->init(game);

	// ���̼��
	do {
		process_keyboard_code(man);
		game->refresh(game);
		Sleep(100);

	} while (man->status);

	// ������Ϸ
	game->end(game);
	return 0;
}