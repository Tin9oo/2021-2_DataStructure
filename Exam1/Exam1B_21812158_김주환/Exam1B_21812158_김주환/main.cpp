/* main.cpp */
/* Description
* Mtrx 입출력
* Mtrx 연산
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
	// 파일 열기
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

	fin >> mA >> mB >> mC; // Mtrx data 불러오기
	mA.set_name("mA = ");
	mB.set_name("mB = ");
	mC.set_name("mC = ");
	fout << mA << mB << mC; // 기본 Mtrx 출력

	// 덧셈 연산
	Mtrx mD = mA + mB;
	mD.set_name("mD = mA + mB =");
	// 뺄셈 연산
	Mtrx mE = mA - mB;
	mE.set_name("mE = mA - mB =");
	// 곱셈 연산
	Mtrx mF = mA * mC;
	mF.set_name("mF = mA * mC =");
	
	fout << mD << mE << mF; // 연산된 Mtrx 출력

	// 파일 닫기
	fin.close();
	fout.close();

	return 0;
}