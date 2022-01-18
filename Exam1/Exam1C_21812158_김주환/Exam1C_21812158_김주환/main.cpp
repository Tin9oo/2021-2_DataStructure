/* main.cpp */
/* Description
* Mtrx �����
* Mtrx ���� �߰�
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

	Mtrx mA, mB;
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
	
	fin >> mA >> mB; // Mtrx ������ �޾ƿ���
	mA.set_name("mA = ");
	mB.set_name("mB = ");
	fout << mA << mB;

	if (mA == mB) // ������ Ȯ��
		fout << "mA and mB are equal" << endl;
	if (mA != mB) // �ٸ��� Ȯ��
		fout << "mA and mB are not equal" << endl;

	Mtrx mG = ~mA; // ��ġ
	mG.set_name("mG = ~mA =");
	fout << mG;

	fin.close();
	fout.close();

	return 0;
}