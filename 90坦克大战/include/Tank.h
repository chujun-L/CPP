#ifndef __TANK_H__
#define __TANK_H__

#include <graphics.h>

#define ROWS		26
#define COLS		26


/*
 * 显示游戏开始的界面
 */
void menu();

/*
 * 捕获鼠标点击的事件，对说明及开始按键进行响应
 */
void captureMouse();

/*
 * 初始化地图
 *
 *        map： 要初始化的地图，传入地图数组的首地址，例如: &map[0][0]
 * rows, cols： 地图的行数、列数
 */
void init_map(int *map, int rows, int cols);

#endif // !__TANK_H__
