/* main.cpp - T_Array<Student> */
/* Description
* 템플릿 구현
* STL의 기능을 직접 구현
* 오름/내림차순 선택/퀵정렬
* Programmed by J. H. Kim
* Last updated : 2021-10-15 */
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "T_Array.h"
#include "Student.h"
using namespace std;

#define ELEMENTS_PER_LINE 10
#define SAMPLE_LINES 5
#define NUM_ELEMENTS 500
#define MIN_NUM_ELEMENTS 10
#define NUM_STUDENTS 10

Student students[10] = {
Student(21811000, string("Kim, G-M"), Date(1990, 10, 5), Time(3, 0, 30), 3.57),
Student(21611075, string("Yoon, S-M"), Date(1990, 4, 5), Time(7, 30, 0), 4.37),
Student(21411015, string("Hwang, S-S"), Date(1989, 1, 10), Time(2, 0, 50), 2.72),
Student(21611054, string("Lee, K-M"), Date(1991, 5, 15), Time(5, 30, 0), 3.35),
Student(21311340, string("Hong, G-M"), Date(1990, 2, 5), Time(1, 10, 0), 3.89),
Student(21811001, string("Kim, M-J"), Date(1992, 11, 7), Time(4, 1, 25), 3.50),
Student(21611076, string("Yoon, S-H"), Date(1993, 5, 1), Time(8, 35, 20), 4.40),
Student(21411016, string("Hwang, S-H"), Date(1988, 2, 13), Time(6, 1, 55), 2.08),
Student(21611055, string("Lee, K-S"), Date(1996, 6, 14), Time(3, 26, 32), 3.59),
Student(21311341, string("Hong, M-E"), Date(1997, 3, 6), Time(0, 10, 10), 3.97),
};

void main() {
	ofstream fout;
	T_Array<Student> studentArray(NUM_STUDENTS, "Array of Students");
	Student* pStudent;
	fout.open("output.txt");
	if (fout.fail()) {
		cout << "Fail to open output.txt file for results !!" << endl;
		exit;
	}
	for (int i = 0; i < NUM_STUDENTS; i++) {
		pStudent = &students[i];
		studentArray.insert(i, *pStudent);
	}
	fout << "Elements in studentArray after initialization :" << endl;
	studentArray.fprint(fout, 1);

	// 오름차순 선택정렬
	fout << "Elements in studentArray after selection sorting by increasing order of arrival time :" << endl;
	studentArray.selection_sort(INCREASING);
	studentArray.fprint(fout, 1);

	// 내림차순 퀵정렬
	fout << "Elements in studentArray after quick sorting by decreasing order of arrival time :" << endl;
	studentArray.quick_sort(DECREASING);
	studentArray.fprint(fout, 1);

	fout.close();
}