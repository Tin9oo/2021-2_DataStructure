/* Student.cpp */
#include <iomanip>
#include "Student.h"

ostream& operator<< (ostream& fout, Student& st) {
	fout << "Student [ st_id: " << setw(5) << st.st_id;
	fout << ", name: " << setw(10) << std::left << st.name;
	fout << ", gpa: ";
	fout.precision(2);
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout << setw(5) << st.gpa;
	fout << ", date_of_birth: " << std::right << st.dateOfBirth;
	fout << ", arrival: " << st.arrivalTime << "]";
	return fout;
}
Student::Student()
	: Person(), st_id(0), gpa(0.0) {
	name = "noname";
	dateOfBirth = Date(0, 0, 0);
	arrivalTime = Time(0, 0, 0);

	// cout << "constructor for Student class << endl;
}
Student::Student(int s_id, string n, Date dob, Time avt, double gpa)
	: Person(n), st_id(s_id), gpa(gpa) {
	dateOfBirth = dob;
	arrivalTime = avt;
	// cout << "constructor for Student class << endl;
}
bool Student::operator<(const Student& s) const {
	if (this->st_id < s.st_id)
		return true;
	else
		return false;
}
bool Student::operator<=(const Student& s) const {
	if (this->st_id <= s.st_id)
		return true;
	else
		return false;
}
bool Student::operator>(const Student& s) const {
	if (this->st_id > s.st_id)
		return true;
	else
		return false;
}
bool Student::operator>=(const Student& s) const {
	if (this->st_id >= s.st_id)
		return true;
	else
		return false;
}
bool Student::operator==(const Student& s) const {
	if (this->st_id == s.st_id)
		return true;
	else
		return false;
}