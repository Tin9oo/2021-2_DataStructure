#ifndef M
#define M
#include <string>
using namespace std;
class Mtrx {
	friend ostream& operator<< (ostream&, const Mtrx&);
public:
	Mtrx(); // default constructor
	Mtrx(string nm, int n_row, int n_col);
	Mtrx(string nm, double* pA, int n_row, int n_col);
	~Mtrx();
	void init(int n_row, int n_col);
	void set_name(string nm) { name = nm; }
	string get_name() const { return name; }
private:
	string name;
	int n_row;
	int n_col;
	double** dM;
};
#endif // !M
