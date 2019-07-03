#ifndef MAP_H_
#define MAP_H_

#define COLS		12
#define ROWS		9

enum role { wall, floor, anchor, man, box, role_num };	// 墙，地板，锚点，小人，箱子

extern int map[ROWS][COLS];

#endif // !MAP_H_

