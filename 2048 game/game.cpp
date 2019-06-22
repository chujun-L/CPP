#include <graphics.h>
#include <conio.h>
#include <vector>
#include "game.h"

using namespace std;

Game2048::Game2048()
{
	setTestData();
}

void Game2048::drawCell(int row, int col)
{
	fillrectangle(col * CELL_HW, row * CELL_HW,		// left, top
		CELL_HW * (col + 1), CELL_HW * (row + 1));		// right, bottom
}

void Game2048::drawNum(int row, int col, int number)
{
	for (int i = 0; i < CELL && number > 0; ++i) {
		outtextxy(col * CELL_HW + (42 - (i * 12)),
				 row * CELL_HW + 18,
			     number % 10 + '0');
		number /= 10;
	}
}

void Game2048::restartGame()
{
	/* 将格子的数据清零 */
	for (int i = 0; i < (CELL << 2); ++i) {
		data[i / CELL][i % CELL] = 0;
	}

	/* 开始游戏时随机两个格子会随机出现数字2或4 */
	randNewNumber();
	randNewNumber();

	gameStatus = GS_NORMAL;
}

bool Game2048::randNewNumber()
{
	vector<int> emptyCell;

	for (int i = 0; i < (CELL << 2); ++i) {
		if (data[i / CELL][i % CELL] == 0) {
			emptyCell.push_back(i);
		}
	}

	if (emptyCell.size() == 0) {
		return false;
	}

	int random = emptyCell[rand() % emptyCell.size()];
	data[random / CELL][random % CELL] = rand() % 10 == 1 ? 4 : 2;

	return true;
}

bool Game2048::moveLeft()
{
	int saveData[CELL][CELL] = { 0 };

	for (int row = 0; row < CELL; ++row) {
		int saveCellNumber = 0, currentWriteCell = 0;

		for (int col = 0; col < CELL; ++col) {
			saveData[row][col] = data[row][col];

			/* 1) 跳过数值为0的格子 */
			if (data[row][col] == 0) continue;

			/* 2) 当前行格子有数据时 */
			if (saveCellNumber == 0) {
				saveCellNumber = data[row][col];
			}
			/* 3) 当前行不止一个格子有数据时 */
			else {
				/* 3-1) 相邻数据相等时 */
				if (saveCellNumber == data[row][col]) {
					data[row][currentWriteCell] = saveCellNumber << 1;
					saveCellNumber = 0;

					/* 游戏胜利 */
					if (data[row][currentWriteCell] == TARGET)	gameStatus = GS_WIN;
				}
				/* 3-2) 相邻数据不相等时 */
				else {
					/* 刷新数据时会将之前的清零，因此再写入一遍 */
					data[row][currentWriteCell] = saveCellNumber;

					saveCellNumber = data[row][col];
				}

				++currentWriteCell;
			}

			data[row][col] = 0;
		}

		if (saveCellNumber != 0) {
			data[row][currentWriteCell] = saveCellNumber;
		}
	}

	/**
	 * 所有的数据都移动到格子的最左、最右、最上、最下时，
	 * 再按该方向的键时不产生随机数，需要按其他方向的键
     */
	for (int i = 0; i < (CELL << 2); ++i) {
		if (data[i / CELL][i % CELL] != saveData[i / CELL][i % CELL])
			return true;
	}

	return false;
}

void Game2048::rotate90Counterclockwise()
{
	int saveCell[CELL][CELL] = { 0 };

	for (int row = 0; row < CELL; ++row) {
		for (int col = 0; col < CELL; ++col) {
			saveCell[row][col] = data[col][CELL - 1 - row];
		}
	}

	for (int i = 0; i < (CELL << 2); ++i) {
		data[i / CELL][i % CELL] = saveCell[i / CELL][i % CELL];
	}
}

bool Game2048::isGameOver()
{
	for (int row = 0; row < CELL; ++row) {
		for (int col = 0; col < CELL; ++col) {
			if ((col + 1 < CELL) &&
				(data[row][col] * data[row][col + 1] == 0 ||
					data[row][col] == data[row][col + 1])) {
				return false;
			}

			if ((row + 1 < CELL) &&
				(data[row][col] * data[row + 1][col] == 0 ||
					data[row][col] == data[row + 1][col])) {
				return false;
			}
		}
	}

	return true;
}

void Game2048::drawGameScreen()
{	
	if (gameStatus == GS_WIN) {
		cleardevice();
		settextcolor(RED);
		outtextxy(80, 100, "Winer");
		settextcolor(BLACK);
	}
	else if (gameStatus == GS_FAIL) {
		cleardevice();
		settextcolor(RED);
		outtextxy(80, 100, "Game Over");
		settextcolor(BLACK);
	}
	else {
		cleardevice();

		for (int i = 0; i < (CELL << 2); ++i) {
			drawCell(i / CELL, i % CELL);								// 画格子
			drawNum(i / CELL, i % CELL, data[i / CELL][i % CELL]);		// 画数字
		}

		settextstyle(18, 0, _T("黑体"));
		settextcolor(RED);
		outtextxy(10, 250, "press r to start/restart");
		outtextxy(10, 270, "press ← ↑ → ↓ to move");
		settextcolor(BLACK);
		settextstyle(FONT_HEIGHT, 0, _T("黑体"));

		gameStatus = GS_NORMAL;
	}
}


void Game2048::setTestData()
{
	for (int i = 0; i < (CELL << 2); ++i) {
		data[i / CELL][i % CELL] = 16 << i / CELL << i % CELL;
	}
}

void Game2048::processKeysCode()
{
	bool update = false;
	int keyCode = _getch();

	if (keyCode >= 'a' && keyCode <= 'z') {
		keyCode -= 32;			// 转换成大写字母
	}

	switch (keyCode) {
	case 72:						// 向上键
		rotate90Counterclockwise();
		update = moveLeft();
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		break;
	case 75:						// 向左键
		update = moveLeft();
		break;
	case 77:						// 向右键
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		update = moveLeft();
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		break;
	case 80:						// 向下键
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		update = moveLeft();
		rotate90Counterclockwise();
		break;
	case 'R':					// 重启游戏
		restartGame();
		break;
	case 'Q':					// 退出游戏
		gameStatus = GS_QUIT;
		break;
	default:
		break;
	}
	Sleep(100);					// 减少CPU的负载

	if (update) {
		randNewNumber();			// 移动后随机的格子产生随机的数字2或者4

		/* 游戏失败 */
		if (isGameOver()) gameStatus = GS_FAIL;
	}
}

int Game2048::getGameStatus()
{
	return gameStatus;
}