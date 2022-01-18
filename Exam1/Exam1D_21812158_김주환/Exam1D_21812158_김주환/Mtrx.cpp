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
Mtrx::Mtrx() { // default constructor
	name = "noname";
	n_col = 0;
	n_row = 0;
	dM = NULL;
	// new DBLPTR[1];
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
Mtrx::~Mtrx() {
	// cout << "destructor of Mtrx ("
	// << name << ")" << endl;
	/*
	for (int i=0; i<n_row; i++)
	delete [] dM[i];
	delete [] dM;
	*/
}
const Mtrx Mtrx::operator+(const Mtrx& mA) {
	int i, j;

	Mtrx mR("mR", n_row, n_col);
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++) {
			mR.dM[i][j] = dM[i][j] + mA.dM[i][j];
		}
	}

	return mR;
}
const Mtrx Mtrx::operator-(const Mtrx& mA) {
	int i, j;

	Mtrx mR("mR", n_row, n_col);
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++)
			mR.dM[i][j] = dM[i][j] - mA.dM[i][j];
	}

	return mR;
}
const Mtrx Mtrx::operator*(const Mtrx& mA) {
	int i, j, k;

	Mtrx mR("mR", n_row, n_row);
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++) {
			mR.dM[i][j] = 0.0;
			for (k = 0; k < n_col; k++) {
				mR.dM[i][j] += dM[i][k] * mA.dM[k][j];
				// cout << mR.dM[i][j] << endl;
			}
			// cout << endl;
		}
	}

	return mR;
}
const Mtrx& Mtrx::operator=(const Mtrx& mA) {
	int i, j;

	// Mtrx mR("mR", mA.n_row, mA.n_col);
	this->n_row = mA.n_row;
	this->n_col = mA.n_col;
	// this->init(this->n_row, this->n_col);
	//cout <<"Mtrx constructor (int size: "
	// << size << ")\n";
	// init part
	dM = new DBLPTR[n_row];
	for (i = 0; i < n_row; i++) {
		dM[i] = new double[n_col];
	}
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++)
			dM[i][j] = 0.0;
	}
	// cout <<"End of Mtrx constructor... \n";
	for (i = 0; i < mA.n_row; i++) {
		for (j = 0; j < mA.n_col; j++)
			this->dM[i][j] = mA.dM[i][j];
	}

	return *this;
}
const Mtrx Mtrx::operator~() {
	int i, j;
	Mtrx mR("mR", n_col, n_row);
	for (i = 0; i < this->n_row; i++) {
		for (j = 0; j < this->n_col; j++) {
			mR.dM[j][i] = this->dM[i][j];
		}
	}
	return mR;
}
bool Mtrx::operator==(const Mtrx& mA) {
	int i, j;
	bool flag = true;
	Mtrx mR("mR", n_row, n_col);
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++) {
			if (mR.dM[i][j] != mA.dM[i][j])
				flag = false;
		}
	}
	return flag;
}
bool Mtrx::operator!=(const Mtrx& mA) {
	int i, j;
	bool flag = true;
	Mtrx mR("mR", n_row, n_col);
	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_col; j++) {
			if (mR.dM[i][j] != mA.dM[i][j])
				flag = false;
		}
	}
	return !flag;
}
