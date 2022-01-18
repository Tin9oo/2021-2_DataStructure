/* Mtrx.h */
#ifndef M
#define M
#include <string>
using namespace std;
class Mtrx {
	friend ostream& operator<< (ostream&, const Mtrx&);
	friend istream& operator>> (istream&, Mtrx&);
public:
	Mtrx(); // default constructor
	Mtrx(string nm, int n_row, int n_col); // 생성자
	~Mtrx(); // 소멸자
	void set_name(string nm) { name = nm; } // 이름 설정
	string get_name() const { return name; } // 이름 반환
	int get_n_row() const { return n_row; } // 열 반환
	int get_n_col() const { return n_col; } // 행 반환
	const Mtrx operator+(const Mtrx&); // 덧셈 연산자 오버로딩
	const Mtrx operator-(const Mtrx&); // 뺄셈 연산자 오버로딩
	const Mtrx operator*(const Mtrx&); // 곱셈 연산자 오버로딩
	const Mtrx& operator=(const Mtrx&); // 대입 연산자 오버로딩
private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};
#endif // !M
