/* Student.cpp */
#include <iomanip>
#include "Student.h"

ostream& operator<< (ostream& fout, const Student& st) {
	fout << "Student [ st_id: " << setw(5) << st.st_id;
	fout << ", name: " << setw(10) << std::left << st.name;
	fout.precision(2);
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout << ", date_of_birth: " << std::right << st.dateOfBirth;
	fout << ", arrival: " << std::right << st.arrivalTime;
	fout << ", gpa: " << setw(5) << st.gpa << "]";
	return fout;
}
Student::Student()
	: Person(), st_id(0), gpa(0) {
	arrivalTime = Time(0, 0, 0);
}
Student::Student(int id, string n, Date d, Time avt, double gpa)
	: Person(n), st_id(id), gpa(gpa) {
	dateOfBirth = d;
	arrivalTime = avt;
}
bool Student::operator<(Student& st) {
	if (this->arrivalTime < st.arrivalTime)
		return true;
	else
		return false;
}
bool Student::operator<=(Student& st) {
	if (this->arrivalTime <= st.arrivalTime)
		return true;
	else
		return false;
}
bool Student::operator>(Student& st) {
	if (this->arrivalTime > st.arrivalTime)
		return true;
	else
		return false;
}
bool Student::operator>=(Student& st) {
	if (this->arrivalTime >= st.arrivalTime)
		return true;
	else
		return false;
}