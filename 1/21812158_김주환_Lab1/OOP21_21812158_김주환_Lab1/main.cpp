/* main.cpp */
/* Description:
*	학생 정보를 구조체로 생성
*	학생 정보를 원하는 크기만큼 동적 할당
*	학생 정보를 무작위로 초기화
*	ID로 오름차순 선택정렬
*	gpa로 내림차순 선택정렬, 같은 gpa에 ID로 오름차순 선택정렬
*	ID 이진 탐색
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

	//	학생 정보 생성
	//printStudent_IDs(students, NUM_STUDENTS);
	fout << endl << endl;
	fout << "Initialized array of students : " << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDNETS, NUM_FIRST_LAST_BLOCK);

	// ID 오름차순 선택정렬
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDNETS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDNETS, NUM_FIRST_LAST_BLOCK);
	
	// GPA 내림차순 정렬 후 동일 ID 내림차순 정렬
	fout << endl << endl;
	fout << "Sorting array of students by (decreasing order of GPA, increasing order of ID) : " << endl;
	sortStudentsByGPA_ID(students, NUM_STUDNETS);
	fprintBigArrayOfStudent_GPA_IDs(fout, students, NUM_STUDNETS, NUM_FIRST_LAST_BLOCK);

	// 탐색을 위한 재정렬
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDNETS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDNETS, NUM_FIRST_LAST_BLOCK);

	// 학생 ID 이진 탐색
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
		u_int32 = ((long)rand() << 15) | rand(); // 비트이동으로 bigRand 생성
		bigRand = u_int32 % num_rands; // 원하는 크기로 스케일링
		if (flag[bigRand] == 1) continue; // 중복 확인

		flag[bigRand] = 1; // 중복 체크
		randArray[count++] = bigRand;
	}
}