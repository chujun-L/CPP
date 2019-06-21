#ifndef GAME_H
#define GAME_H

#define SCREEN_WIDTH		350
#define SCREEN_HEIGHT		250

#define FONT_HEIGHT		25						// 字体高度

#define CELL				4						// 格子数量
#define CELL_HW			60						// 格子长宽

class Game2048 {
public:
	Game2048();
	void drawGameScreen();						// 画整个游戏界面
	void setTestData();							// 开始游戏前显示测试数据

private:
	void drawCell(int row, int col);				// 画格子
	void drawNum(int row, int col, int number);	// 画数字

	int data[CELL][CELL];
};

#endif // !GAME_H

