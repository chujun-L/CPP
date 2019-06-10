#ifndef __TANK_H__
#define __TANK_H__

#define ROWS		26
#define COLS		26
#define TANK_POSITION_X	8
#define TANK_POSITION_Y	24

extern int map[ROWS][COLS];				// 地图的二维数组在map.h中定义

enum DIRECTION { UP, DOWN, LEFT, RIGHT };	// 坦克移动的方向

struct bullet_s
{
	int pos_x;							// 子弹在地图的x坐标
	int pos_y;							// 子弹在地图的y坐标
	int status;							// 子弹是否存在
	DIRECTION dir;						// 子弹飞行的方向
};

struct tank_s {
	int x;								// 坦克在地图的坐标
	int y;
	int live;							// 坦克是否生存：1(活着) 0(挂了)
	DIRECTION dir;
	void (*fire_bullet)(bullet_s *);		// 发射子弹
};

extern tank_s my_tank;					// 声明主战坦克结构体
extern IMAGE my_tank_img[4];				// 坦克移动方向的图片



/* 显示游戏开始的界面 */
void menu();

/* 捕获鼠标点击的事件，对说明及开始按键进行响应 */
void captureMouse();

/*
 * 初始化地图
 *
 *        map： 要初始化的地图，传入地图数组的首地址，例如: &map[0][0]
 * rows, cols： 地图的行数、列数
 */
void init_map(int *map, int rows, int cols);

/*
 * 在地图上标记主战坦克初始化的位置
 *
 *  map:	地图的首地址，&map[0][0]
 * x, y: 主战坦克初始化的位置坐标
 * flag: 主战坦克的标记为200
 */
void set_prop_map(int *map, int x, int y, int flag);

/*
 * 根据坐标获取在地图上标记的值
 *
 *  map:	地图的首地址，&map[0][0]
 *  x,y: 地图的坐标
 */
int get_prop_map(int *map, int x, int y);

/*
 * 初始化主战坦克
 *
 * x，y: 主战坦克在地图出现的坐标
 */
void init_tank(int x, int y);

/*
 * 坦克移动
 *
 * tank: 要移动的坦克
 *  dir: 移动的方向
 *  img: 坦克移动方向的图片
 */
void tank_walk(tank_s *tank, DIRECTION dir, IMAGE *img);

#endif // !__TANK_H__
