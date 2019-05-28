#include <iostream>
#include <fstream>

using namespace std;

#define DIM 7		// DIM: dimensional 维度


/*
 * 读取文件内容到数组
 *
 * sFileName: 文件名
 * nArry:     保存的数组
 */
bool ReadFile2Arry(string sFileName, int nArry[][DIM])
{
	ifstream file;
	int nRows = 0, nCols = 0;

	file.open(sFileName.c_str());
	if (file.fail())
	{
		cout << "打开文件失败" << endl;
		return false;
	}

	file >> nRows >> nCols;		// 在map.txt文件中读取行数、列数
	if (nRows > DIM || nCols > DIM)
	{
		cout << "文件过大" << endl;
		return false;
	}

	for (int row = 0; row < nRows; row++)
	{
		for (int col = 0; col < nCols; col++)
		{
			file >> nArry[row][col];
		}
	}

	return true;
}


/*
 * 判断当前的值是否为峰值
 *
 * nArry: 要判断的值所在的数组
 * nRows、nCols: 要判断的值所在数组的下标
 */
bool isPeakInArry(int nArry[][DIM], int nRows, int nCols)
{
	if (nArry[nRows][nCols] > nArry[nRows - 1][nCols] &&
		nArry[nRows][nCols] > nArry[nRows + 1][nCols] &&
		nArry[nRows][nCols] > nArry[nRows][nCols - 1] &&
		nArry[nRows][nCols] > nArry[nRows][nCols + 1])
	{
		return true;
	}

	return false;
}



int main()
{
	string cFileName = "map.txt";
	int gMap[DIM][DIM];

	if (ReadFile2Arry(cFileName, gMap))
	{
		// 遍历数组，找出峰值
		for (int row = 1; row < 6; row++)
		{
			for (int col = 1; col < 7; col++)
			{
				if (isPeakInArry(gMap, row, col))
					cout << gMap[row][col] << endl;
			}
		}
	}

	system("pause");
	return 0;
}

