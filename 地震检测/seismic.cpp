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
		/* ʱ�䴰����ÿ������ƽ��֮�� */
		sum += pow(arry[leng - i], 2);
	}

	return sum / window;
}

int main()
{
	string filename = "seismic.dat";
	ifstream file;
	int seismic_data_count = 0;			// ���������ݵ�����
	float time_interval = 0;				// ���ݲ�����ʱ����
	float *seismic = NULL;
	float short_power = 0, long_power = 0, ratio = 0;

	file.open(filename.c_str());
	if (file.fail()) {
		cout << "open file fail" << endl;
		//exit(-1);
	}
	else {
		/* ��ȡ���ݵ�������������ʱ���� */
		file >> seismic_data_count >> time_interval;
		cout << "���������ݵ������� " << seismic_data_count << endl;
		cout << "���ݲ�����ʱ������ " << time_interval << endl;

		/* ��ȡ���������� */
		seismic = new float[seismic_data_count];
		for (int i = 0; i < seismic_data_count; ++i) {
			file >> seismic[i];
		}

		/* ��/�̴�������ͳ�ƺú����һ���1 */
		for (int i = LONG_WINDOW - 1; i < seismic_data_count; ++i) {
			short_power = power_w(seismic, i, SHORT_WINDOW);
			long_power = power_w(seismic, i, LONG_WINDOW);

			ratio = short_power / long_power;

			if (ratio > THRESHOLD) {
				cout << "������ܷ����ڣ� " << time_interval * i << "��" << endl;
			}
		}

		delete[] seismic;
		file.close();
	}


	system("pause");
	return 0;
}