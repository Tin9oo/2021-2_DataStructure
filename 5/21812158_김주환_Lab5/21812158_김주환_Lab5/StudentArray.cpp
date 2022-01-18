#include <iostream>
#include "StudentArray.h"
#include "Student.h"
using namespace std;
ostream& operator<<(ostream& fout, const StudentArray& sA) {
	for (int i = 0; i < sA.num_students; i++) {
		fout << sA.students[i] << endl;
	}
	return fout;
}
StudentArray::StudentArray(int size) {
	num_students = size;
	students = new Student[num_students];
}
StudentArray::StudentArray(const StudentArray& obj) {
	num_students = obj.num_students;
	for (int i = 0; i < num_students; i++)
		students[i] = obj.students[i];
}
StudentArray::~StudentArray() {
	/*if (students != NULL)
		delete[] students;*/
}
Student& StudentArray::operator[] (int index) const {
	if (isValidIndex(index))
		return students[index];
	else {
		cout << "ERROR: Subscript out of range.₩n";
		exit(0);
	}
}
void StudentArray::sortByBirthDate() {
	int i, j, mx;
	Student tmp;
	int min_p;
	Date min_BD;

	for (i = 0; i < num_students - 1; i++) {
		min_p = i;
		min_BD = students[min_p].birthDate;
		for (j = i + 1; j < num_students; j++) {
			if (students[j].birthDate.getElapsedDays() < min_BD.getElapsedDays()) {
				min_p = j;
				min_BD = students[j].birthDate;
			}
		}

		if (min_p != i) {
			tmp = students[i];
			students[i] = students[min_p];
			students[min_p] = tmp;
		}
	}
}
void StudentArray::sortByName() {
	int i, j, mx;
	Student tmp;
	int min_p;
	string min_N;

	for (i = 0; i < num_students - 1; i++) {
		min_p = i;
		min_N = students[min_p].name;
		for (j = i + 1; j < num_students; j++) {
			if (students[j].name.compare(min_N) < 0) {
				min_p = j;
				min_N = students[j].name;
			}
		}

		if (min_p != i) {
			tmp = students[i];
			students[i] = students[min_p];
			students[min_p] = tmp;
		}
	}
}
void StudentArray::sortByST_ID() {
	int i, j, mx;
	char minName[16] = { 0 };
	Student tmp;
	int min_st, min_ID;

	for (i = 0; i < num_students - 1; i++) {
		min_st = i;
		min_ID = students[min_st].st_id;
		for (j = i + 1; j < num_students; j++) {
			if (students[j].st_id < min_ID) {
				min_st = j;
				min_ID = students[j].st_id;
			}
		}

		if (min_st != i) {
			tmp = students[i];
			students[i] = students[min_st];
			students[min_st] = tmp;
		}
	}
}
void StudentArray::sortByGPA() {
	int i, j, mx;
	char minName[16] = { 0 };
	Student tmp;
	int min_st;
	double min_GPA;

	for (i = 0; i < num_students - 1; i++) {
		min_st = i;
		min_GPA = students[min_st].st_id;
		for (j = i + 1; j < num_students; j++) {
			if (students[j].st_id < min_GPA) {
				min_st = j;
				min_GPA = students[j].gpa;
			}
		}

		if (min_st != i) {
			tmp = students[i];
			students[i] = students[min_st];
			students[min_st] = tmp;
		}
	}
}
bool StudentArray::isValidIndex(int index) const {
	if (index < 0 || index >= num_students)
		return false;
	else
		return true;
}
