/* main.cpp */
/* Description
* 2���� �迭�� ����� ����
* �⺻����� ��ġ��� ����
* Programmed by J. H. Kim
* Last updated : 2021-09-17 */
#include <iostream>
#include <fstream>
#include "Class_Mtrx.h"
using namespace std;
void main()
{
	ifstream fin;
	ofstream fout;
	fin.open("Matrix_data.txt");
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
	mtrxA.setName("MtrxA");
	int n_row = mtrxA.getN_row();
	int n_col = mtrxA.getN_col();
	mtrxA.fprintMtrx(fout);
	Mtrx mtrxB(fin);
	mtrxB.setName("MtrxB");
	mtrxB.fprintMtrx(fout);
	Mtrx mtrxC(fin);
	mtrxC.setName("MtrxC");
	mtrxC.fprintMtrx(fout);
	// ��� ����
	Mtrx mtrxD(mtrxA.getN_row(), mtrxB.getN_col());
	mtrxD = mtrxA.add(mtrxB);
	mtrxD.setName("MtrxD = mtrxA.add(mtrxB)");
	mtrxD.fprintMtrx(fout);
	// ��� ����
	Mtrx mtrxE(mtrxA.getN_row(), mtrxB.getN_col());
	mtrxE = mtrxA.sub(mtrxB);
	mtrxE.setName("MtrxE = mtrxA.sub(mtrxB)");
	mtrxE.fprintMtrx(fout);
	// ��� ����
	Mtrx mtrxF(mtrxA.getN_row(), mtrxC.getN_col());
	mtrxF = mtrxA.multiply(mtrxC);
	mtrxF.setName("MtrxF = mtrxA.multiply(mtrxC)");
	mtrxF.fprintMtrx(fout);
	// ��ġ ��� ����
	Mtrx mtrxT(mtrxF.getN_col(), mtrxF.getN_row());
	mtrxT = mtrxT.Transpos(mtrxF);
	mtrxT.setName("MtrxT = mtrxT.Transpos(mtrxF)");
	mtrxT.fprintMtrx(fout);
	fout.close();
} // end of main()