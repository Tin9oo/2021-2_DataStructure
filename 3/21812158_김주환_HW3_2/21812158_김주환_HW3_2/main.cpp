/* main.cpp */
/* Description
* 2���� �迭�� ����� ����
* �⺻���� ����
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
	// �⺻ ��� ������ �ҷ�����
	Mtrx mtrxA(fin);
	int n_row = mtrxA.getN_row();
	int n_col = mtrxA.getN_col();
	Mtrx mtrxB(fin);
	Mtrx mtrxC(fin);
	// ��� ����
	Mtrx mtrxD(mtrxA.getN_row(), mtrxB.getN_col());
	mtrxD = mtrxA.add(mtrxB);
	mtrxD.setName("Mtrx_SUM = mtrxA.add(mtrxB)");
	mtrxD.fprintMtrx(fout);
	// ��� ����
	Mtrx mtrxE(mtrxA.getN_row(), mtrxB.getN_col());
	mtrxE = mtrxA.sub(mtrxB);
	mtrxE.setName("Mtrx_SUB = mtrxA.sub(mtrxB)");
	mtrxE.fprintMtrx(fout);
	// ��� ����
	Mtrx mtrxF(mtrxA.getN_row(), mtrxC.getN_col());
	mtrxF = mtrxA.multiply(mtrxC);
	mtrxF.setName("Mtrx_MUL = mtrxA.multiply(mtrxC)");
	mtrxF.fprintMtrx(fout);
	fout.close();
} // end of main()