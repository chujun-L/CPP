#include <graphics.h>
#include "game.h"

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

void Game2048::drawGameScreen()
{
	for (int row = 0; row < CELL; ++row) {
		for (int col = 0; col < CELL; ++col) {
			drawCell(row, col);					// 1）画格子
			drawNum(row, col, data[row][col]);		// 2) 画数字
		}
	}
}


void Game2048::setTestData()
{
	for (int row = 0; row < CELL; ++row) {
		for (int col = 0; col < CELL; ++col) {
			data[row][col] = 16 << row << col;
		}
	}
}