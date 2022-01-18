#include <iomanip>
#include"Mtrx.h"
using namespace std;

#define SETW 10

typedef double* DBLPTR;

ostream& operator<< (ostream& fout, const Mtrx& m) {
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;

	fout << m.name << endl;
	for (int i = 0; i < m.n_row; i++) {
		for (int j = 0; j < m.n_col; j++) {
			fout.setf(ios::fixed);
			fout.precision(2);
			if ((i == 0) && (j == 0))
				fout << a6 << a3 << setw(SETW) << m.dM[i][j];
			else if ((i == 0) && (j == (m.n_col - 1)))
				fout << setw(SETW) << m.dM[i][j] << a6 << a4;
			else if ((i > 0) && (i < (m.n_row - 1)) && (j == 0))
				fout << a6 << a2 << setw(SETW) << m.dM[i][j];
			else if ((i > 0) && (i < (m.n_row - 1)) && (j == (m.n_col - 1)))
				fout << setw(SETW) << m.dM[i][j] << a6 << a2;
			else if ((i == (m.n_row - 1)) && (j == 0))
				fout << a6 << a6 << setw(SETW) << m.dM[i][j];
			else if ((i == (m.n_row - 1)) && (j == (m.n_col - 1)))
				fout << setw(SETW) << m.dM[i][j] << a6 << a5;
			else
				fout << setw(SETW) << m.dM[i][j];
		}
		fout << endl;
	}
	fout << endl;
	return fout;
}
Mtrx::Mtrx() // default constructor
{
	name = "mR";
	n_col = 0;
	n_row = 0;
	dM = new DBLPTR[1];
}
Mtrx::Mtrx(string nm, int n_row, int n_col)
	: name(nm), n_row(n_row), n_col(n_col)
{
	int i, j;
	//cout <<"Mtrx constructor (int size: "
	// << size << ")\n";
	dM = new DBLPTR[n_row];
	for (i = 0; i < n_row; i++)
		dM[i] = new double[n_col];
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++) {
			dM[i][j] = 0.0;
		}
	}
	// cout <<"End of Mtrx constructor... \n";
}
Mtrx::Mtrx(string nm, double* pA, int n_row, int n_col)
	: name(nm), n_row(n_row), n_col(n_col)
{
	int i, j;
	int cnt = 0;
	//cout <<"Mtrx constructor (int size: "
	// << size << ")\n";
	dM = new DBLPTR[n_row];
	for (i = 0; i < n_row; i++)
		dM[i] = new double[n_col];
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++) {
			dM[i][j] = pA[cnt++];
		}
	}
	// cout <<"End of Mtrx constructor... \n";
}
Mtrx::~Mtrx() {
	// cout << "destructor of Mtrx ("
	// << name << ")" << endl;
	/*
	for (int i=0; i<n_row; i++)
	delete [] dM[i];
	delete [] dM;
	*/
}
void Mtrx::init(int n_row, int n_col) {
	int i, j;
	//cout <<"Mtrx constructor (int size: "
	// << size << ")\n";
	dM = new DBLPTR[n_row];
	for (i = 0; i < n_row; i++) {
		dM[i] = new double[n_col];
	}
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++)
			dM[i][j] = 0.0;
	}
	// cout <<"End of Mtrx constructor... \n";
}
