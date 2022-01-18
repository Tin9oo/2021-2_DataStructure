/* main.cpp */
/* Description:
* 파일 입력 및 데이터 통계 분석
* Programmed by J. H. Kim
* Last updated : 2021-09-08 */

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#define MAX_NUM_DATA 10
#define INPUT_FILE_NAME "input_data.txt"
#define OUTPUT_FILE_NAME "output.txt"

int fileInputData(ifstream& fin, int* data_array, int max_num_data);
void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout);

int main() {
	int* data_array;
	int num_data = 0;
	ifstream fin;
	ofstream fout;

	fin.open(INPUT_FILE_NAME);
	if (fin.fail()) {
		cout << "Fail to open an input file (" << INPUT_FILE_NAME << ")" << endl;
		exit(1);
	}
	fout.open(OUTPUT_FILE_NAME);
	if (fout.fail()) {
		cout << "Fail to open an output file (" << OUTPUT_FILE_NAME << ")" << endl;
		exit(1);
	}

	data_array = (int*)calloc(MAX_NUM_DATA, sizeof(int));

	num_data = fileInputData(fin, data_array, MAX_NUM_DATA);

	getStatistics_fileOut(data_array, num_data, fout);

	return 0;
}
int fileInputData(ifstream& fin, int* data_array, int max_num_data) {
	int num_data = 0;
	for (int i = 0; i < max_num_data; i++) {
		fin >> data_array[i];
		cout << data_array[i] << " ";
		num_data++;
		if (data_array[i] == NULL) break;
	}

	return num_data;
}
void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout) {
	int min, max;
	double sum = 0.0, avg, var, diff, sq_diff_sum = 0.0, std_dev;

	min = INT_MAX;
	max = INT_MIN;
	for (int i = 0; i < num_data; i++) {
		if (data_array[i] < min) min = data_array[i];
		if (data_array[i] > max) max = data_array[i];
		sum += (double)data_array[i];
	}
	avg = sum / num_data;
	for (int i = 0; i < num_data; i++) {
		diff = data_array[i] - avg;
		sq_diff_sum += pow(diff, 2);
	}
	var = sq_diff_sum / num_data;
	std_dev = sqrt(var);


	fout << "Total " << num_data << " input from input data file." << endl;
	fout << "Total " << num_data << " integer data : {" << data_array[0];
	for (int i = 1; i < num_data; i++) {
		fout << ", " << data_array[i];
	}
	fout << "}" << endl;
	fout << "min (" << min << "), max (" << max << "), ";
	fout << "sum (" << sum << "), average (" << avg << ")" << endl;
	fout << "variance (" << var << "), standard deviation (" << std_dev << ")" << endl;
}