#include <iostream>
#include <fstream>

using namespace std;

#define NUM 7
#define MAX 1
#define MIN 0

/*
 * 读取文件内容到数组
 *
 * sFileName: 文件名
 * nArry:     保存的数组
 */
bool ReadFile2Arry(string sFileName, int nArry[][NUM])
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
	if (nRows > NUM || nCols > NUM)
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

	file.close();
	return true;
}


/*
 * 判断当前的值是否为峰值
 *
 * nArry: 要判断的值所在的数组
 * nRows、nCols: 要判断的值所在数组的下标
 */
bool isPeakInArry(int nArry[][NUM], int nRows, int nCols)
{
	if (nArry[nRows][nCols] > nArry[nRows - 1][nCols] &&		// 上
		nArry[nRows][nCols] > nArry[nRows + 1][nCols] &&		// 下
		nArry[nRows][nCols] > nArry[nRows][nCols - 1] &&		// 左
		nArry[nRows][nCols] > nArry[nRows][nCols + 1] &&		// 右
		nArry[nRows][nCols] > nArry[nRows - 1][nCols - 1] &&	// 左上角
		nArry[nRows][nCols] > nArry[nRows - 1][nCols + 1] &&	// 右上角
		nArry[nRows][nCols] > nArry[nRows + 1][nCols - 1] &&	// 左下角
		nArry[nRows][nCols] > nArry[nRows + 1][nCols + 1])		// 右下角
		
	{
		return true;
	}

	return false;
}

/*
 * 判断当前的值是否为峰底
 *
 * nArry: 要判断的值所在的数组
 * nRows、nCols: 要判断的值所在数组的下标
 */
bool isValleyInArry(int nArry[][NUM], int nRows, int nCols)
{
	if (nArry[nRows][nCols] < nArry[nRows - 1][nCols] &&
		nArry[nRows][nCols] < nArry[nRows + 1][nCols] &&
		nArry[nRows][nCols] < nArry[nRows][nCols - 1] &&
		nArry[nRows][nCols] < nArry[nRows][nCols + 1])
	{
		return true;
	}

	return false;
}

/*
 * 在数组找出最大值或最小值
 *
 * nArry: 要查找的数组
 * flag： 最大或最小的标志
 */
int extremes(int nArry[][NUM], int flag)
{
	int nRet = nArry[0][0];

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			switch (flag)
			{
			case MAX:
				nRet = nArry[i][j] > nRet ? nArry[i][j] : nRet;
				break;
			case MIN:
				nRet = nArry[i][j] < nRet ? nArry[i][j] : nRet;
				break;
			default:
				break;
			}
		}
	}

	// 打印最大或最小值在数组中的位置
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (nArry[i][j] == nRet)
			{
				cout << "Arry[" << i << "]" << "[" << j << "]" << " ";
			}
		}
	}
	return nRet;
}


int main()
{
	string cFileName = "map.txt";
	int gMap[NUM][NUM];
	int nPeakNum = 0;

	if (ReadFile2Arry(cFileName, gMap))
	{
		// 遍历数组，找出峰顶或峰谷的值
		for (int row = 1; row < 6; row++)
		{
			for (int col = 1; col < 7; col++)
			{
				if (isPeakInArry(gMap, row, col))
				{
					//cout << gMap[row][col] << endl;
					nPeakNum++;
				}


				if (isValleyInArry(gMap, row, col))
				{
					cout << "谷点的位置： " << gMap[row][col] << endl;
				}
			}
		}
		cout << "峰点的数目： " << nPeakNum << endl;

		cout << "最大值：" << extremes(gMap, MAX) << endl;
		cout << "最小值：" << extremes(gMap, MIN) << endl;
	}

	system("pause");
	return 0;
}

