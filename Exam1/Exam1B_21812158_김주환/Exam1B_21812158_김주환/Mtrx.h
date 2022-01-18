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
	Mtrx(string nm, int n_row, int n_col); // ������
	~Mtrx(); // �Ҹ���
	void set_name(string nm) { name = nm; } // �̸� ����
	string get_name() const { return name; } // �̸� ��ȯ
	int get_n_row() const { return n_row; } // �� ��ȯ
	int get_n_col() const { return n_col; } // �� ��ȯ
	const Mtrx operator+(const Mtrx&); // ���� ������ �����ε�
	const Mtrx operator-(const Mtrx&); // ���� ������ �����ε�
	const Mtrx operator*(const Mtrx&); // ���� ������ �����ε�
	const Mtrx& operator=(const Mtrx&); // ���� ������ �����ε�
private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};
#endif // !M
