#ifndef MAP_H_
#define MAP_H_

#define COLS		12
#define ROWS		9

enum role { wall, floor, anchor, man, box, role_num };	// ǽ���ذ壬ê�㣬С�ˣ�����

extern int map[ROWS][COLS];

#endif // !MAP_H_

