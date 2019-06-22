#ifndef GAME_H
#define GAME_H

#define SCREEN_WIDTH		350
#define SCREEN_HEIGHT		250

#define FONT_HEIGHT		25						// 字体高度

#define CELL				4						// 格子数量
#define CELL_HW			60						// 格子长宽

/* 游戏的状态 */
#define GS_FAIL			0
#define GS_WIN			1
#define GS_NORMAL			2
#define GS_QUIT			3

class Game2048 {
public:
	Game2048();
	void drawGameScreen();						// 画整个游戏界面
	void setTestData();							// 开始游戏前显示测试数据
	void processKeysCode();						// 处理方向键
	int getGameStatus();							// 读取游戏的状态

private:
	void drawCell(int row, int col);				// 画格子
	void drawNum(int row, int col, int number);	// 画数字
	void restartGame();
	bool randNewNumber();							// 产生随机的数字2或者4
	bool moveLeft();								// 左移格子里面的数字
	void rotate90Counterclockwise();				// 逆时针旋转90度

	int data[CELL][CELL];
	int gameStatus;
};

#endif // !GAME_H

