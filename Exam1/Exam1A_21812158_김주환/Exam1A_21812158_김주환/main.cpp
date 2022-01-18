/* main.cpp */
/* Description
* Mtrx ¿‘√‚∑¬
* Programmed by J. H. Kim
* Last updated : 2021-10-02 */
#include <iostream>
#include <fstream>
#include <string>
#include "Mtrx.h"
using namespace std;
int main()
{
	ifstream fin;
	ofstream fout;
	Mtrx mA, mB, mC;
	fin.open("Matrix_data.txt");
	if (fin.fail()) {
		cout << "Error in opening input data file !!" << endl;
		exit;
	}
	fout.open("Result.txt");
	if (fout.fail()) {
		cout << "Error in opening output data file !!" << endl;
		exit;
	}
	fin >> mA >> mB >> mC;
	mA.set_name("mA =");
	mB.set_name("mB =");
	mC.set_name("mC =");
	fout << mA << mB << mC;
	fin.close();
	fout.close();
	return 0;
}