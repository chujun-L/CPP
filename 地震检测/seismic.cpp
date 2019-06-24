#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

#define LONG_WINDOW		5
#define SHORT_WINDOW		2
#define THRESHOLD			1.5

float power_w(float *arry, int leng, int window)
{
	float sum = 0;

	for (int i = 0; i < window; ++i) {
		/* 时间窗口内每个数据平方之和 */
		sum += pow(arry[leng - i], 2);
	}

	return sum / window;
}

int main()
{
	string filename = "seismic.dat";
	ifstream file;
	int seismic_data_count = 0;			// 地震检测数据的数量
	float time_interval = 0;				// 数据采样的时间间隔
	float *seismic = NULL;
	float short_power = 0, long_power = 0, ratio = 0;

	file.open(filename.c_str());
	if (file.fail()) {
		cout << "open file fail" << endl;
		//exit(-1);
	}
	else {
		/* 读取数据的数量及采样的时间间隔 */
		file >> seismic_data_count >> time_interval;
		cout << "地震检测数据的数量： " << seismic_data_count << endl;
		cout << "数据采样的时间间隔： " << time_interval << endl;

		/* 读取采样的数据 */
		seismic = new float[seismic_data_count];
		for (int i = 0; i < seismic_data_count; ++i) {
			file >> seismic[i];
		}

		/* 长/短窗口数据统计好后向右滑动1 */
		for (int i = LONG_WINDOW - 1; i < seismic_data_count; ++i) {
			short_power = power_w(seismic, i, SHORT_WINDOW);
			long_power = power_w(seismic, i, LONG_WINDOW);

			ratio = short_power / long_power;

			if (ratio > THRESHOLD) {
				cout << "地震可能发生在： " << time_interval * i << "秒" << endl;
			}
		}

		delete[] seismic;
		file.close();
	}


	system("pause");
	return 0;
}