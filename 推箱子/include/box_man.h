/*
 *	游戏的界面
 *	小人操作
 *	游戏胜利
 */

#ifndef BOX_MAN_H_
#define BOX_MAN_H_

#define PIXEL			61
#define SCREEN_WIDTH		PIXEL * 12
#define SCREEN_HEIGHT		PIXEL * 9


struct game_man
{
	int position_x;
	int position_y;
	void walk_left();
	void walk_right();
	void walk_up();
	void walk_down();
	void push_box();
};

struct game_screen
{
	int s_width;
	int s_height;
	int *map;
	//enum role r;
	//int s_rows;
	//int s_cols;
	void (*init)(struct game_screen *);
	void	 (*end)(struct game_screen *);
};


void init_game_screen(struct game_screen *game);
void end_game_screen(struct game_screen *game);

#endif // !BOX_MAN_H_

