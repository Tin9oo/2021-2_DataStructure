/* main.cpp */
/* Description
* �л� Ŭ������ ���
* Programmed by J. H. Kim
* Last updated : 2021-10-01 */
#include <iostream>
#include <fstream>
#include "StudentArray.h"
#include <string>
#define NUM_STUDENTS 10

void main() {
	StudentArray studentArray(NUM_STUDENTS);
	Student st;
	ofstream fout;
	int st_ids[NUM_STUDENTS];

	fout.open("output.txt");
	if (fout.fail()) {
		cout << "Fail to open an output file (output.txt)" << endl;
		exit(1);
	}

	genST_ids(NUM_STUDENTS, st_ids);
	fout << "Initializing student array (num students : " << NUM_STUDENTS << ")" << endl;
	for (int i = 0; i < NUM_STUDENTS; i++) {
		st = genRandStudent(st_ids[i]);
		studentArray[i] = st;
	}
	fout << studentArray;

	// �й� ����
	fout << endl << "Sorting studentArray by student id : " << endl;
	studentArray.sortByST_ID();
	fout << studentArray;

	// �̸� ����
	fout << endl << "Sorting studentArray by student name : " << endl;
	studentArray.sortByName();
	fout << studentArray;

	// ���� ����
	fout << endl << "Sorting studentArray by GPA : " << endl;
	studentArray.sortByGPA();
	fout << studentArray;

	// ���� ����
	fout << endl << "Sorting studentArray by BirthDate : " << endl;
	studentArray.sortByBirthDate();
	fout << studentArray;

	fout << endl;
	fout.close();
}