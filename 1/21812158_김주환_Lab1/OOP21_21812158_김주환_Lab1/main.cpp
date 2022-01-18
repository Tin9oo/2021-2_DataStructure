/* main.cpp */
/* Description:
*	�л� ������ ����ü�� ����
*	�л� ������ ���ϴ� ũ�⸸ŭ ���� �Ҵ�
*	�л� ������ �������� �ʱ�ȭ
*	ID�� �������� ��������
*	gpa�� �������� ��������, ���� gpa�� ID�� �������� ��������
*	ID ���� Ž��
* Programmed by J. H. Kim
* Last updated : 2021. 09. 03 */

#include <iostream>
#include <iomanip>
#include <fstream>

//#include <stdlib.h>

#include "Student.h"
using namespace std;

#define NUM_STUDNETS 5000
#define NUM_SEARCH 5
#define NUM_FIRST_LAST_BLOCK 100

void genBigRandArray(int* randArray, int num_rands);

void main() {
	ofstream fout;
	int* student_ids;
	Student* students, * pSt;
	int studnet_search[NUM_SEARCH] = { 1, 123, 999, 2500, 4999 };

	fout.open("output.txt");
	if (fout.fail()) {
		cout << "Error in opening output.txt" << endl;
		exit;
	}
	student_ids = (int*)malloc(sizeof(int) * NUM_STUDNETS);
	students = (Student*)malloc(sizeof(Student) * NUM_STUDNETS);
	genBigRandArray(student_ids, NUM_STUDNETS);
	initStudents(students, student_ids, NUM_STUDNETS);

	//	�л� ���� ����
	//printStudent_IDs(students, NUM_STUDENTS);
	fout << endl << endl;
	fout << "Initialized array of students : " << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDNETS, NUM_FIRST_LAST_BLOCK);

	// ID �������� ��������
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDNETS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDNETS, NUM_FIRST_LAST_BLOCK);
	
	// GPA �������� ���� �� ���� ID �������� ����
	fout << endl << endl;
	fout << "Sorting array of students by (decreasing order of GPA, increasing order of ID) : " << endl;
	sortStudentsByGPA_ID(students, NUM_STUDNETS);
	fprintBigArrayOfStudent_GPA_IDs(fout, students, NUM_STUDNETS, NUM_FIRST_LAST_BLOCK);

	// Ž���� ���� ������
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDNETS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDNETS, NUM_FIRST_LAST_BLOCK);

	// �л� ID ���� Ž��
	fout << endl << endl;
	fout << "Searching student with student_ID : " << endl;
	for (int i = 0; i < NUM_SEARCH; i++) {
		pSt = searchStudentByID(students, NUM_STUDNETS, studnet_search[i]);
		fout << "Student search by ID (" << setw(4) << studnet_search[i] << ") : ";
		if (pSt != NULL)
			fprintStudent(fout, pSt);
		else
			fout << "NULL - student was not found !!";
		fout << endl;
	}
	fout.close();
}

void genBigRandArray(int* randArray, int num_rands) {
	char* flag;
	int count = 0;
	unsigned int u_int32 = 0;
	unsigned int bigRand;

	flag = (char*)calloc(sizeof(char), num_rands);
	while (count < num_rands) {
		u_int32 = ((long)rand() << 15) | rand(); // ��Ʈ�̵����� bigRand ����
		bigRand = u_int32 % num_rands; // ���ϴ� ũ��� �����ϸ�
		if (flag[bigRand] == 1) continue; // �ߺ� Ȯ��

		flag[bigRand] = 1; // �ߺ� üũ
		randArray[count++] = bigRand;
	}
}