/* main.cpp */
/* Description
* Mtrx �����
* Mtrx ����
* Programmed by J. H. Kim
* Last updated : 2021-10-02 */

#include <iostream>
#include <fstream>
#include "Mtrx.h"
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;

	Mtrx mA, mB, mC;
	// ���� ����
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

	fin >> mA >> mB >> mC; // Mtrx data �ҷ�����
	mA.set_name("mA = ");
	mB.set_name("mB = ");
	mC.set_name("mC = ");
	fout << mA << mB << mC; // �⺻ Mtrx ���

	// ���� ����
	Mtrx mD = mA + mB;
	mD.set_name("mD = mA + mB =");
	// ���� ����
	Mtrx mE = mA - mB;
	mE.set_name("mE = mA - mB =");
	// ���� ����
	Mtrx mF = mA * mC;
	mF.set_name("mF = mA * mC =");
	
	fout << mD << mE << mF; // ����� Mtrx ���

	// ���� �ݱ�
	fin.close();
	fout.close();

	return 0;
}