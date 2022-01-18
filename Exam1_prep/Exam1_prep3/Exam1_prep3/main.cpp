#include <fstream>
#include "MtrxArray.h"

#define NUM_MTRX 6
int main()
{
	ifstream fin;
	ofstream fout;
	int n_row, n_col;
	fin.open("Matrix_3x3.txt");
	fout.open("Result.txt");
	Mtrx m;
	fin >> m;
	n_row = m.get_n_col();
	n_col = m.get_n_col();
	MtrxArray mtrx(NUM_MTRX, n_row, n_col);
	mtrx[0] = m;
	fin >> mtrx[1];
	mtrx[0].set_name("mtrx[0] =");
	mtrx[1].set_name("mtrx[1] =");
	fout << mtrx[0] << endl;
	fout << mtrx[1] << endl;
	mtrx[2] = mtrx[0] + mtrx[1];
	mtrx[2].set_name("mtrx[2] = mtrx[0] + mtrx[1] =");
	fout << mtrx[2] << endl;
	mtrx[3] = mtrx[0] - mtrx[1];
	mtrx[3].set_name("mtrx[3] = mtrx[0] - mtrx[1] =");
	fout << mtrx[3] << endl;
	mtrx[4] = mtrx[0] * mtrx[1];
	mtrx[4].set_name("mtrx[4] = mtrx[0] * mtrx[1] =");
	fout << mtrx[4] << endl;
	mtrx[5] = mtrx[0];
	mtrx[5].set_name("mtrx[5] = mtrx[0] =");
	fout << mtrx[5] << endl;
	if (mtrx[0] == mtrx[1])
		fout << "mtrx[0] and mtrx[1] are equal.\n";
	if (mtrx[0] != mtrx[1])
		fout << "mtrx[0] and mtrx[1] are not equal.\n";
	fin.close();
	fout.close();
	return 0;
}