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
	for (int row = 0; row < CELL; ++row) {
		int saveCellNumber = 0, currentWriteCell = 0;

		for (int col = 0; col < CELL; ++col) {
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

	return true;
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

void Game2048::drawGameScreen()
{	
	cleardevice();

	for (int i = 0; i < (CELL << 2); ++i) {
		drawCell(i / CELL, i % CELL);								// 画格子
		drawNum(i / CELL, i % CELL, data[i / CELL][i % CELL]);		// 画数字
	}

	gameStatus = GS_NORMAL;
}


void Game2048::setTestData()
{
	for (int i = 0; i < (CELL << 2); ++i) {
		data[i / CELL][i % CELL] = 16 << i / CELL << i % CELL;
	}
}

void Game2048::processKeysCode()
{
	int keyCode = _getch();

	if (keyCode >= 'a' && keyCode <= 'z') {
		keyCode -= 32;			// 转换成大写字母
	}

	switch (keyCode) {
	case 72:						// 向上键
		rotate90Counterclockwise();
		moveLeft();
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		break;
	case 75:						// 向左键
		moveLeft();
		break;
	case 77:						// 向右键
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		moveLeft();
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		break;
	case 80:						// 向下键
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		rotate90Counterclockwise();
		moveLeft();
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
}

int Game2048::getGameStatus()
{
	return gameStatus;
}