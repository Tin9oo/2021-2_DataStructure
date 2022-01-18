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
	~Mtrx();
	void set_name(string nm) { name = nm; }
	string get_name() const { return name; }
	int get_n_row() const { return n_row; }
	int get_n_col() const { return n_col; }
private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};
#endif // !M
