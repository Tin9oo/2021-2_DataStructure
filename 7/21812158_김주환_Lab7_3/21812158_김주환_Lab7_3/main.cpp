/* main.cpp - T_Array<Student, K> */
/* Description
* 템플릿 구현
* STL 기능 사용과 기능 직접 구현
* 각 단계별 동작 확인
* Programmed by J. H. Kim
* Last updated : 2021-10-15 */
#include <iostream>
#include <conio.h> // for _getch()
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "T_Array.h"
#include "Student.h"
#include "VectorHandler.h"
using namespace std;

#define STEP_1
#define STEP_2
#define STEP_3
#define STEP_4 // selection sort
#define STEP_5 // Quick sort
#define STEP_6 // Merge sort

#define NUM_TIMES 10 
#define NUM_DATES 10
#define NUM_STUDENTS 10

void main() {
	Student students[NUM_STUDENTS] = {
	Student(5234, string("Kim, G-M"), Date(2002, 7, 15), Time(3, 0, 30), 3.57),
	Student(1999, string("Yoon, S-M"), Date(1999, 12, 25), Time(7, 30, 0), 4.37),
	Student(4141, string("Byun, S-S"), Date(2001, 3, 10), Time(2, 0, 50), 2.72),
	Student(2167, string("Lee, K-M"), Date(1998, 10, 9), Time(5, 30, 0), 3.35),
	Student(3890, string("Hong, G-M"), Date(2000, 3, 1), Time(1, 10, 0), 3.89),
	Student(6543, string("Jang, S-M"), Date(2000, 5, 21), Time(9, 20, 10), 4.42),
	Student(7080, string("Park, S-T"), Date(2001, 5, 1), Time(1, 20, 15), 4.12),
	Student(9564, string("Choi, Y-H"), Date(1997, 6, 10), Time(10, 0, 0), 3.85),
	Student(1000, string("Shin, D-J"), Date(2003, 4, 5), Time(11, 15, 10), 3.21),
	Student(8812, string("Ahn, S-B"), Date(1997, 1, 1), Time(2, 0, 5), 4.45),
	};

#ifdef STEP_3
	/* Step 3 - Testing template array class T_Array<T, K> */
	Student* pSt;

	T_Array<Student, int> stArray_keyID(NUM_STUDENTS, "T_Array<Student, keyST_ID>"); // 배열 생성
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyID.insert(i, students[i]); // 배열에 삽입

	cout << "T_Array<Student_keyID> at initialization : " << endl; // 초기 배열 출력
	stArray_keyID.print(1);

	stArray_keyID.selection_sort(string("ST_ID"), INCREASING); // 선택 정렬

	cout << "\nT_Array<Student_keyID> after sorting (increasing order) by ST_ID : " << endl; // 정렬 후 배열 출력
	stArray_keyID.print(1);

	T_Array<Student, double> stArray_keyGPA(NUM_STUDENTS, "T_Array<Student, keyGPA>"); // 배열 생성
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyGPA.insert(i, students[i]); // 배열에 삽입

	stArray_keyGPA.selection_sort(string("GPA"), DECREASING); // 내림차순 선택정렬

	cout << "\nT_Array<Student, keyGPA> after sorting (decreasing order) by GPA : " << endl; // 정렬 후 배열 출력
	stArray_keyGPA.print(1);

	cout << "Hit any key to continue .... "; // 키보드 입력 대기
	_getch();
	cout << endl;
#endif

#ifdef STEP_4
	T_Array<Student, string> stArray_keyName(NUM_STUDENTS, "T_Array<Student, keyName > ");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyName.insert(i, students[i]);

	stArray_keyName.selection_sort(string("ST_NAME"), INCREASING);

	cout << "\nT_Array<Student_keyName> after selection sorting (increasing order) by name : " << endl;
	stArray_keyName.print(1);

	T_Array<Student, Date> stArray_keyDoB(NUM_STUDENTS, "Array of Students, date of birth as key");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyDoB.insert(i, students[i]);

	stArray_keyDoB.selection_sort(string("BIRTH_DATE"), INCREASING);

	cout << "\nstArray_keyDoB after selection sorting (increasing order) by date of birth : " << endl;
	stArray_keyDoB.print(1);

	T_Array<Student, Time> stArray_keyTime(NUM_STUDENTS, "Array of Students, arrival time as key");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyTime.insert(i, students[i]);

	stArray_keyTime.selection_sort(string("ARRIVAL_TIME"), INCREASING);

	cout << "\nstArray_keyArrTm after selection sorting (increasing order) by arrival time : " << endl;
	stArray_keyTime.print(1);

	cout << "Hit any key to continue .... ";
	_getch();
	cout << endl;
#endif

#ifdef STEP_5
	cout << endl << "STEP_5 : Tamplate T_Array for quick sort" << endl << endl;

	T_Array<Student, int> stArray_keyID_Q(NUM_STUDENTS, "T_Array<Student, keyST_ID>");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyID_Q.insert(i, students[i]);

	cout << "T_Array<Student_keyID> at initialization : " << endl;
	stArray_keyID_Q.print(1);

	stArray_keyID_Q.quick_sort(string("ST_ID"), INCREASING);

	cout << "\nT_Array<Student_keyID> after quick sorting (increasing order) by ST_ID : " << endl;
	stArray_keyID_Q.print(1);

	T_Array<Student, double> stArray_keyGPA_Q(NUM_STUDENTS, "T_Array<Student, keyGPA>");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyGPA_Q.insert(i, students[i]);

	stArray_keyGPA_Q.quick_sort(string("GPA"), DECREASING);

	cout << "\nT_Array<Student, keyGPA> after quick sorting (decreasing order) by GPA : " << endl;
	stArray_keyGPA_Q.print(1);

	cout << "Hit any key to continue .... ";
	_getch();
	cout << endl;

	T_Array<Student, string> stArray_keyName_Q(NUM_STUDENTS, "T_Array<Student, keyName > ");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyName_Q.insert(i, students[i]);

	stArray_keyName_Q.quick_sort(string("ST_NAME"), INCREASING);

	cout << "\nT_Array<Student_keyName> after quick sorting (increasing order) by name : " << endl;
	stArray_keyName_Q.print(1);

	T_Array<Student, Date> stArray_keyDoB_Q(NUM_STUDENTS, "Array of Students, date of birth as key");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyDoB_Q.insert(i, students[i]);

	stArray_keyDoB_Q.quick_sort(string("BIRTH_DATE"), INCREASING);

	cout << "\nstArray_keyDoB after quick sorting (increasing order) by date of birth : " << endl;
	stArray_keyDoB_Q.print(1);

	T_Array<Student, Time> stArray_keyTime_Q(NUM_STUDENTS,
		"Array of Students, arrival time as key");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyTime_Q.insert(i, students[i]);

	stArray_keyTime_Q.quick_sort(string("ARRIVAL_TIME"), INCREASING);

	cout << "\nstArray_keyArrTm after quick sorting (increasing order) by arrival time : " << endl;
	stArray_keyTime_Q.print(1);

	cout << "Hit any key to continue .... ";
	_getch();
	cout << endl;
#endif

#ifdef STEP_6
	cout << endl << "STEP_6 : Tamplate T_Array for merge sort" << endl << endl;

	T_Array<Student, int> stArray_keyID_M(NUM_STUDENTS, "T_Array<Student, keyST_ID>");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyID_M.insert(i, students[i]);

	cout << "T_Array<Student_keyID> at initialization : " << endl;
	stArray_keyID_M.print(1);

	stArray_keyID_M.merge_sort(string("ST_ID"), INCREASING);

	cout << "\nT_Array<Student_keyID> after merge sorting (increasing order) by ST_ID : " << endl;
	stArray_keyID_M.print(1);

	T_Array<Student, double> stArray_keyGPA_M(NUM_STUDENTS, "T_Array<Student, keyGPA>");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyGPA_M.insert(i, students[i]);

	stArray_keyGPA_M.merge_sort(string("GPA"), DECREASING);

	cout << "\nT_Array<Student, keyGPA> after merge sorting (decreasing order) by GPA : " << endl;
	stArray_keyGPA_M.print(1);

	cout << "Hit any key to continue .... ";
	_getch();
	cout << endl;

	T_Array<Student, string> stArray_keyName_M(NUM_STUDENTS, "T_Array<Student, keyName > ");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyName_M.insert(i, students[i]);

	stArray_keyName_M.merge_sort(string("ST_NAME"), INCREASING);

	cout << "\nT_Array<Student_keyName> after merge sorting (increasing order) by name : " << endl;
	stArray_keyName_M.print(1);

	T_Array<Student, Date> stArray_keyDoB_M(NUM_STUDENTS, "Array of Students, date of birth as key");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyDoB_M.insert(i, students[i]);

	stArray_keyDoB_M.merge_sort(string("BIRTH_DATE"), INCREASING);

	cout << "\nstArray_keyDoB after merge sorting (increasing order) by date of birth : " << endl;
	stArray_keyDoB_M.print(1);

	T_Array<Student, Time> stArray_keyTime_M(NUM_STUDENTS, "Array of Students, arrival time as key");
	for (int i = 0; i < NUM_STUDENTS; i++)
		stArray_keyTime_M.insert(i, students[i]);

	stArray_keyTime_M.merge_sort(string("ARRIVAL_TIME"), INCREASING);

	cout << "\nstArray_keyArrTm after merge sorting (increasing order) by arrival time : " << endl;
	stArray_keyTime_M.print(1);

	cout << "Hit any key to continue .... ";
	_getch();
	cout << endl;
#endif
}