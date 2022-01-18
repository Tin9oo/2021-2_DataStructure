/* main.cpp */
/* Description
* ���ϴ� ũ���� ������ �迭����
* �迭�� Ư��(�ִ�, �ּ�, ��� ���)
* ����/�� ���� �� �ҿ� �ð� ����
* Programmed by J. H. Kim
* Last updated : 2021-09-22 */
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include "BigArray.h"
using namespace std;
#define ELEMENTS_PER_LINE 10
#define SAMPLE_LINES 3
void main()
{
	LARGE_INTEGER freq, t1, t2;
	LONGLONG t_diff;
	double elapsed_t;

	QueryPerformanceFrequency(&freq); // ���ļ�

	ofstream fout;
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Error in opening output.txt !!"
			<< endl;
		exit;
	}
	int base_offset = 0;
	int big_rand_size = 1000000; // �迭 ũ�� 1,000,000
	base_offset = -big_rand_size / 2; // ������
	BigArray ba_2(big_rand_size);
	fout << endl << "Generating big rand array of "
		<< ba_2.size() << " elements with base_offset " << base_offset << " ... "
		<< endl;
	ba_2.genBigRandArray(base_offset); // �迭 ����
	ba_2.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);
	ba_2.fprintStatistics(fout);
	QueryPerformanceCounter(&t1);
	ba_2.quick_sort(); // ����Ʈ �� �ð� ����
	QueryPerformanceCounter(&t2);
	t_diff = t2.QuadPart - t1.QuadPart;
	elapsed_t = (double)t_diff / freq.QuadPart;
	fout << "Quick sort took " << elapsed_t * 1000 << "[milliseconds]" << endl;
	ba_2.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);
	ba_2.suffle();
	QueryPerformanceCounter(&t1);
	ba_2.selection_sort(); // ���� ���� �� �ð� ����
	QueryPerformanceCounter(&t2);
	t_diff = t2.QuadPart - t1.QuadPart;
	elapsed_t = (double)t_diff / freq.QuadPart;
	fout << "Selection sort took " << elapsed_t * 1000 << " [milliseconds]" << endl;
	ba_2.fprintSample(fout, ELEMENTS_PER_LINE, SAMPLE_LINES);
	fout.close();
}