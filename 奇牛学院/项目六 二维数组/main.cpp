#include <iostream>
#include <fstream>

using namespace std;

#define NUM 7


/*
 * ��ȡ�ļ����ݵ�����
 *
 * sFileName: �ļ���
 * nArry:     ���������
 */
bool ReadFile2Arry(string sFileName, int nArry[][NUM])
{
	ifstream file;
	int nRows = 0, nCols = 0;

	file.open(sFileName.c_str());
	if (file.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		return false;
	}

	file >> nRows >> nCols;		// ��map.txt�ļ��ж�ȡ����������
	if (nRows > NUM || nCols > NUM)
	{
		cout << "�ļ�����" << endl;
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
 * �жϵ�ǰ��ֵ�Ƿ�Ϊ��ֵ
 *
 * nArry: Ҫ�жϵ�ֵ���ڵ�����
 * nRows��nCols: Ҫ�жϵ�ֵ����������±�
 */
bool isPeakInArry(int nArry[][NUM], int nRows, int nCols)
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
	int gMap[NUM][NUM];

	if (ReadFile2Arry(cFileName, gMap))
	{
		// �������飬�ҳ���ֵ
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

