/* main.cpp */
/* Description
* Mtrx �����
* Mtrx ���� �߰�
* MtrxArray�� ����
* Programmed by J. H. Kim
* Last updated : 2021-10-02 */

#include <iostream>
#include <fstream>
#include "MtrxArray.h"
using namespace std;

#define NUM_MTRX 7

int main()
{
	ifstream fin;
	ofstream fout;

	int n_row, n_col;
	fin.open("Matrix_data.txt");
	if (fin.fail())
	{
		cout << "Error in opening input data file !!" << endl;
		exit;
	}

	fout.open("Result.txt");
	if (fout.fail())
	{
		cout << "Error in opening output data file !!" << endl;
		exit;
	}

	MtrxArray mtrx(NUM_MTRX); // MtrxArray ����

	fin >> mtrx[0] >> mtrx[1] >> mtrx[2]; // Mtrx ������ �޾ƿ���
	mtrx[0].set_name("mtrx[0] =");
	mtrx[1].set_name("mtrx[1] =");
	mtrx[2].set_name("mtrx[2] =");
	mtrx[3] = mtrx[0] + mtrx[1]; // ���� ���� �� ����
	mtrx[3].set_name("mtrx[3] = mtrx[0] + mtrx[1] =");
	mtrx[4] = mtrx[0] - mtrx[1]; // ���� ���� �� ����
	mtrx[4].set_name("mtrx[4] = mtrx[0] - mtrx[1] =");
	mtrx[5] = mtrx[0] * mtrx[2]; // ���� ���� �� ����
	mtrx[5].set_name("mtrx[5] = mtrx[0] * mtrx[2] =");
	mtrx[6] = ~mtrx[5]; // ƿ�� ���� �� ����
	mtrx[6].set_name("mtrx[6] = ~mtrx[5] =");

	fout << mtrx; // ������ �����ϰ� ������ MtrxArray�� ���
				  // MtrxArray ��� ���ο��� Mtrx ����� �ݺ������Ѵ�.

	fin.close(); // ���� �ݱ�
	fout.close();

	return 0;
}