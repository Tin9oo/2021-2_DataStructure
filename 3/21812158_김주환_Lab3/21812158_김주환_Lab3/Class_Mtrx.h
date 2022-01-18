/* Class_Mtrx.h */
#ifndef MTRX_H
#define MTRX_H
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SIZE 100
class Mtrx {
public:
	Mtrx(int num_row, int num_col); // 클래스 생성자
	Mtrx(double* dA, int num_data, int num_row, int num_col); // 생성자
	Mtrx(istream& fin); // 생성자
	~Mtrx(); // destructor
	int getN_row() { return n_row; } // 열 정보 반환
	int getN_col() { return n_col; } // 행 정보 반환
	void fprintMtrx(ostream& fout); // 포멧에 맞춰 출력
	void setName(string nm) { name = nm; }; // 이름 설정
	string getName() { return name; }; // 이름 반환
	Mtrx add(const Mtrx&); // 덧셈 연산
	Mtrx sub(const Mtrx&); // 뺄셈 연산
	Mtrx multiply(const Mtrx&); // 곱셈 연산
	Mtrx Transpos(const Mtrx&); // 전치행렬 연산
private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};
#endif