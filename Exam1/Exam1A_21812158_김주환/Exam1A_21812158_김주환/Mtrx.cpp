/* Mtrx.cpp */
#include <iomanip>
#include "Mtrx.h"
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
istream& operator>> (istream& fin, Mtrx& m) {
	// DBLPTR *dM; /* defined in class, as private data member
	int i, j, size_row, size_col, num_data, cnt;
	double d;
	//cout <<"Mtrx constructor (double **dA, int size: " << size << ") \n";
	fin >> size_row >> size_col;
	m.n_row = size_row;
	m.n_col = size_col;
	m.dM = new DBLPTR[m.n_row]; // 정보를 받아 필요한 2차원 배열 동적 생성
	for (i = 0; i < m.n_row; i++)
		m.dM[i] = new double[m.n_col];
	for (i = 0; i < m.n_row; i++) {
		for (j = 0; j < m.n_col; j++) {
			if (fin.eof())
				m.dM[i][j] = 0.0; // 초기값은 0.0
			else {
				fin >> d;
				m.dM[i][j] = d;
			}
		}
	}
	//cout <<"End of Mtrx constructor... \n";
	return fin;
}
Mtrx::Mtrx() {
	name = "noname";
	n_col = 0;
	n_row = 0;
	dM = NULL;
	// new DBLPTR[1];
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