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
bool ReadFile2Arry(string sFileName, int *pArry)
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

	for (int i = 0; i < nRows * nCols; i++)
	{
		file >> *pArry++;			// 读取文件内容到数组
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
int extremes(int *nArry, int flag)
{
	int nRet = *nArry;
	int nRows = 6, nCols = 7;
	int i = 0, j = 0;
	int *pBegin = nArry;

	for (int i = 0; i < nRows * nCols - 1; i++)
	{
		nArry++;

		switch (flag)
		{
		case MAX:
			nRet = *nArry > nRet ? *nArry : nRet;
			break;
		case MIN:
			nRet = *nArry < nRet ? *nArry : nRet;
			break;
		default:
			break;
		}
	}

	// 用指针怎么推导出二维数组的下标? 然后求出nArry[i][j]
	for (int n = 0; n < nRows * nCols; n++)
	{
		if (nRet == *pBegin)
		{
			i = n / nCols;
			j = n % nCols;
			cout << "nArry[" << i << "]" << "[" << j << "]" << " ";
		}
		pBegin++;
	}

	return nRet;
}


int main()
{
	string cFileName = "map.txt";
	int gMap[NUM][NUM];
	int nPeakNum = 0;
	int *pMap = &gMap[0][0];

	int (*p1)[NUM];		// 声明指针数组
	p1 = &gMap[0];		// 指向二维数组的首地址

	if (ReadFile2Arry(cFileName, pMap))
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

		cout << "最大值：" << extremes(pMap, MAX) << endl;
		cout << "最小值：" << extremes(pMap, MIN) << endl;
		cout << "hello world" << endl;
	}

	system("pause");
	return 0;
}

