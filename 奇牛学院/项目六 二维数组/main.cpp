#include <iostream>
#include <fstream>

using namespace std;

#define NUM 7
#define MAX 1
#define MIN 0

/*
 * ��ȡ�ļ����ݵ�����
 *
 * sFileName: �ļ���
 * nArry:     ���������
 */
bool ReadFile2Arry(string sFileName, int *pArry)
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

	for (int i = 0; i < nRows * nCols; i++)
	{
		file >> *pArry++;			// ��ȡ�ļ����ݵ�����
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
	if (nArry[nRows][nCols] > nArry[nRows - 1][nCols] &&		// ��
		nArry[nRows][nCols] > nArry[nRows + 1][nCols] &&		// ��
		nArry[nRows][nCols] > nArry[nRows][nCols - 1] &&		// ��
		nArry[nRows][nCols] > nArry[nRows][nCols + 1] &&		// ��
		nArry[nRows][nCols] > nArry[nRows - 1][nCols - 1] &&	// ���Ͻ�
		nArry[nRows][nCols] > nArry[nRows - 1][nCols + 1] &&	// ���Ͻ�
		nArry[nRows][nCols] > nArry[nRows + 1][nCols - 1] &&	// ���½�
		nArry[nRows][nCols] > nArry[nRows + 1][nCols + 1])		// ���½�
		
	{
		return true;
	}

	return false;
}

/*
 * �жϵ�ǰ��ֵ�Ƿ�Ϊ���
 *
 * nArry: Ҫ�жϵ�ֵ���ڵ�����
 * nRows��nCols: Ҫ�жϵ�ֵ����������±�
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
 * �������ҳ����ֵ����Сֵ
 *
 * nArry: Ҫ���ҵ�����
 * flag�� ������С�ı�־
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

	// ��ָ����ô�Ƶ�����ά������±�? Ȼ�����nArry[i][j]
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

	if (ReadFile2Arry(cFileName, pMap))
	{
		// �������飬�ҳ��嶥���ȵ�ֵ
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
					cout << "�ȵ��λ�ã� " << gMap[row][col] << endl;
				}
			}
		}
		cout << "������Ŀ�� " << nPeakNum << endl;

		cout << "���ֵ��" << extremes(pMap, MAX) << endl;
		cout << "��Сֵ��" << extremes(pMap, MIN) << endl;
	}

	system("pause");
	return 0;
}

