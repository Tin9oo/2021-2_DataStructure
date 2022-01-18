/* main.cpp */
/* Description
* 2차원 배열로 행렬을 구현
* 기본연산 구현
* Programmed by J. H. Kim
* Last updated : 2021-09-22 */
#include <iostream>
#include <fstream>
#include "Class_Mtrx.h"
using namespace std;
void main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	if (fin.fail())
	{
		cout << "Error in opening Matrix_5x5_data.txt !!" << endl;
		exit;
	}
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Error in opening Matrix_operations_results.txt !!" << endl;
		exit;
	}
	// 기본 행렬 데이터 불러오기
	Mtrx mtrxA(fin);
	int n_row = mtrxA.getN_row();
	int n_col = mtrxA.getN_col();
	Mtrx mtrxB(fin);
	Mtrx mtrxC(fin);
	// 행렬 덧셈
	Mtrx mtrxD(mtrxA.getN_row(), mtrxB.getN_col());
	mtrxD = mtrxA.add(mtrxB);
	mtrxD.setName("Mtrx_SUM = mtrxA.add(mtrxB)");
	mtrxD.fprintMtrx(fout);
	// 행렬 뺄셈
	Mtrx mtrxE(mtrxA.getN_row(), mtrxB.getN_col());
	mtrxE = mtrxA.sub(mtrxB);
	mtrxE.setName("Mtrx_SUB = mtrxA.sub(mtrxB)");
	mtrxE.fprintMtrx(fout);
	// 행렬 곱셈
	Mtrx mtrxF(mtrxA.getN_row(), mtrxC.getN_col());
	mtrxF = mtrxA.multiply(mtrxC);
	mtrxF.setName("Mtrx_MUL = mtrxA.multiply(mtrxC)");
	mtrxF.fprintMtrx(fout);
	fout.close();
} // end of main()