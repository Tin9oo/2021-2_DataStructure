/* Class_Mtrx.h */
#ifndef MTRX_H
#define MTRX_H
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SIZE 100
class Mtrx {
public:
	Mtrx(int num_row, int num_col); // Ŭ���� ������
	Mtrx(double* dA, int num_data, int num_row, int num_col); // ������
	Mtrx(istream& fin); // ������
	~Mtrx(); // destructor
	int getN_row() { return n_row; } // �� ���� ��ȯ
	int getN_col() { return n_col; } // �� ���� ��ȯ
	void fprintMtrx(ostream& fout); // ���信 ���� ���
	void setName(string nm) { name = nm; }; // �̸� ����
	string getName() { return name; }; // �̸� ��ȯ
	Mtrx add(const Mtrx&); // ���� ����
	Mtrx sub(const Mtrx&); // ���� ����
	Mtrx multiply(const Mtrx&); // ���� ����
	Mtrx Transpos(const Mtrx&); // ��ġ��� ����
private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};
#endif