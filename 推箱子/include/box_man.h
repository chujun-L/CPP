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

enum s_man { QUIT, STOP, MOVE };		// 小人的状态

struct game_screen
{
	//bool status;
	int s_width;
	int s_height;
	int *map;
	//struct game_man *man;
	//enum role r;
	//int s_rows;
	//int s_cols;
	void (*init)(struct game_screen *);
	void	 (*end)(struct game_screen *);
	void	 (*refresh)(struct game_screen *);
};

struct game_man
{
	int status;
	int pos_x;
	int pos_y;
	int *map;
	//void walk_left();
	void (*walk_right)(struct game_man *);
	//void walk_up();
	//void walk_down();
	//void push_box();
	//void (*get_pos)(struct game_screen *);
};


void draw_screen(struct game_screen *game);
void init_game_screen(struct game_screen *game);
void end_game_screen(struct game_screen *game);

//void get_man_pos(struct game_screen *game);
void walk_right(struct game_man *man);

#endif // !BOX_MAN_H_

