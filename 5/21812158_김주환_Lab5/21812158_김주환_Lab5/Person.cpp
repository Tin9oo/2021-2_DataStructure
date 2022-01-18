#include <fstream>
#include <iomanip>
#include <string>
#include "Person.h"
#include "Date.h"
using namespace std;

ostream& operator<<(ostream& fout, const Person& p) {
	fout << " Person [name: ";
	fout.setf(ios::left);
	fout << setw(16) << p.name;
	fout << ", birth date: ";
	fout.unsetf(ios::left);
	fout << p.birthDate;
	fout << "]";
	return fout;
}
const Person& Person::operator=(const Person& right) {
	name = right.name;
	birthDate = right.birthDate;

	return *this;
}