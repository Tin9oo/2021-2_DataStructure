/* Student.cpp */
#include <iomanip>
#include "Student.h"
#include "MyString.h"
#include "Date.h"
using namespace std;

ostream& operator<<(ostream& fout, const Student& s) {
	int count = 0;
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);

	fout << "Student(ID : " << setw(4) << s.st_id;
	fout << ", Name : " << setw(16) << s.name;
	fout << ", Dept : " << setw(6) << s.dept_name;
	fout << ", birth date : " << setw(13) << s.birthDate;
	fout << ", Grade : " << s.gpa;

	return fout;
}
Student::Student()
	: Person()
{
	st_id = 0;
	dept_name = "";
	gpa = 0.0;
}
Student::Student(int id)
	: Person()
{
	st_id = id;
	dept_name = "";
	gpa = 0.0;
}
Student::Student(int id, string n, Date dob, string dept_n, double gpa)
	: Person(n, dob), st_id(id), dept_name(dept_n), gpa(gpa)
{
	
}
const Student& Student::operator=(const Student& right) {
	st_id = right.st_id;
	dept_name = right.dept_name;
	gpa = right.gpa;
	// name = right.name;
	// birthDate = right.birthDate;
	Person::operator=(right);

	return *this;
}
bool Student::operator>(const Student& right) {
	bool temp = true;
	if (st_id <= right.st_id) temp = false;
	if (dept_name <= right.dept_name) temp = false;
	if (gpa <= right.gpa) temp = false;
	if (name <= right.name) temp = false;
	if (birthDate > right.birthDate);
	else temp = false;

	return temp;
}
bool Student::operator==(const Student& right) {
	bool temp = true;
	if (st_id == right.st_id) temp = false;
	if (dept_name == right.dept_name) temp = false;
	if (gpa == right.gpa) temp = false;
	if (name == right.name) temp = false;
	if (birthDate == right.birthDate) temp = false;

	return temp;
}

Student genRandStudent(int id) {
	Student st(id);
	Date d;
	double f, b;

	st.setBirthDate(genRandDate());
	st.setName(genRandName());
	st.setDept_name(genRandDeptName());
	f = double(rand() % 100);
	b = double(rand() % 100);
	b /= 100.0;
	st.setGPA(f + b);

	return st;
}
void genST_ids(int num_students, int* st_ids) {
	int* flag = NULL;
	int count = 0;
	unsigned int u_int32 = 0;
	int bigRand;

	flag = new int[40000];
	for (int i = 0; i < num_students; i++) {
		flag[i] = 0;
	}
	while (count < num_students) {
		u_int32 = ((long)rand() << 15) | rand(); // 비트이동으로 bigRand 생성
		bigRand = u_int32 % 40000 + 10000; // 원하는 크기로 스케일링
		if (flag[bigRand - 10000] == 1) continue; // 중복 확인

		flag[bigRand - 10000] = 1; // 중복 체크
		st_ids[count++] = bigRand;
	}

	delete[]flag;
}
