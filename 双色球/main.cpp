#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//#define DOUBLECOLORBALL
#define COLORBALLLOTTO

#ifdef DOUBLECOLORBALL
// 双色球
#define RED			33
#define BLUE			16
#define REDZONE		6
#define BLUEZONE		1
#endif // DOUBLECOLORBALL


#ifdef COLORBALLLOTTO
// 大乐透
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
		*(save + i) = p - arry + 1;	// 出现最多的号码
		*p = 0;						// 清零，防止下次循环还是找到它本身
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
				dc_ball_red[line[i] - 1] += 1;		// 统计红球
			else
				dc_ball_blue[line[i] - 1] += 1;		// 统计蓝球
		}
	}

	/* 推导红球的号码 */
	index_to_value(dc_ball_red, REDZONE, RED, red_ball);

	/* 推导蓝球的号码 */
	index_to_value(dc_ball_blue, BLUEZONE, BLUE, blue_ball);

#ifdef DOUBLECOLORBALL
	//打印出中奖的号码
	cout << "双色球中奖的号码: ";
	for (int i = 0; i < REDZONE; ++i)
	{
		cout << "[" << setw(2) << setfill('0') << red_ball[i] << "]";
	}
	cout << "    " << "[" << blue_ball[0] << "]" << endl;
#endif // DOUBLECOLORBALL


#ifdef COLORBALLLOTTO
	//打印出中奖的号码
	cout << "大乐透中奖的号码: ";
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