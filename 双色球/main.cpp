#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//#define DOUBLECOLORBALL
#define COLORBALLLOTTO

#ifdef DOUBLECOLORBALL
// ˫ɫ��
#define RED			33
#define BLUE			16
#define REDZONE		6
#define BLUEZONE		1
#endif // DOUBLECOLORBALL


#ifdef COLORBALLLOTTO
// ����͸
#define RED			35
#define BLUE			12
#define REDZONE		5
#define BLUEZONE		2
#endif // COLORBALLLOTTO

bool index_to_value(int *arry, int num, int size, int *save)
{
	int *p = arry;

	for (int i = 0; i < num; ++i)
	{
		for (int j = 1; j < size; ++j)
		{
			if (*p < *(arry + j))			
				p = arry + j;
		}
		*(save + i) = p - arry + 1;	// �������ĺ���
		*p = 0;						// ���㣬��ֹ�´�ѭ�������ҵ�������
	}
	return true;
}

int main()
{
	string filename = "./dc_ball.txt";
	ifstream file;
	int dc_ball_red[RED] = { 0 }, dc_ball_blue[BLUE] = { 0 };
	int red_ball[REDZONE] = { 0 }, blue_ball[BLUEZONE] = { 0 };
	int line[7] = { 0 };

	file.open(filename);
	if (file.fail()) {
		cout << "open file fail" << endl;
	}

	while (1)
	{
		if (file.eof())
			break;

		for (int i = 0; i < 7; ++i)
		{
			file >> line[i];
			if (i < REDZONE)
				dc_ball_red[line[i] - 1] += 1;		// ͳ�ƺ���
			else
				dc_ball_blue[line[i] - 1] += 1;		// ͳ������
		}
	}

	/* �Ƶ�����ĺ��� */
	index_to_value(dc_ball_red, REDZONE, RED, red_ball);

	/* �Ƶ�����ĺ��� */
	index_to_value(dc_ball_blue, BLUEZONE, BLUE, blue_ball);

#ifdef DOUBLECOLORBALL
	//��ӡ���н��ĺ���
	cout << "˫ɫ���н��ĺ���: ";
	for (int i = 0; i < REDZONE; ++i)
	{
		cout << "[" << setw(2) << setfill('0') << red_ball[i] << "]";
	}
	cout << "    " << "[" << blue_ball[0] << "]" << endl;
#endif // DOUBLECOLORBALL


#ifdef COLORBALLLOTTO
	//��ӡ���н��ĺ���
	cout << "����͸�н��ĺ���: ";
	for (int i = 0; i < REDZONE; ++i)
	{
		cout << "[" << setw(2) << setfill('0') << red_ball[i] << "]";
	}
	cout << "    ";
	for (int i = 0; i < BLUEZONE; ++i)
	{
		cout << "[" << setw(2) << setfill('0') << blue_ball[i] << "]";
	}
	cout << endl;
#endif // COLORBALLLOTTO

	system("pause");
	return 0;
}