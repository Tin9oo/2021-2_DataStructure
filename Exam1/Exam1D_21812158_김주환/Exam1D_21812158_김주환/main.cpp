/* main.cpp */
/* Description
* Mtrx 입출력
* Mtrx 연산 추가
* MtrxArray로 통합
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

	MtrxArray mtrx(NUM_MTRX); // MtrxArray 생성

	fin >> mtrx[0] >> mtrx[1] >> mtrx[2]; // Mtrx 데이터 받아오기
	mtrx[0].set_name("mtrx[0] =");
	mtrx[1].set_name("mtrx[1] =");
	mtrx[2].set_name("mtrx[2] =");
	mtrx[3] = mtrx[0] + mtrx[1]; // 덧셈 연산 후 대입
	mtrx[3].set_name("mtrx[3] = mtrx[0] + mtrx[1] =");
	mtrx[4] = mtrx[0] - mtrx[1]; // 뺄셈 연산 후 대입
	mtrx[4].set_name("mtrx[4] = mtrx[0] - mtrx[1] =");
	mtrx[5] = mtrx[0] * mtrx[2]; // 곱셈 연산 후 대입
	mtrx[5].set_name("mtrx[5] = mtrx[0] * mtrx[2] =");
	mtrx[6] = ~mtrx[5]; // 틸다 연산 후 대입
	mtrx[6].set_name("mtrx[6] = ~mtrx[5] =");

	fout << mtrx; // 위에서 연산하고 저장한 MtrxArray를 출력
				  // MtrxArray 출력 내부에서 Mtrx 출력을 반복실행한다.

	fin.close(); // 파일 닫기
	fout.close();

	return 0;
}