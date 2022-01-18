/* main.cpp */
/* Description
* T_Array 로 Student 다루기
* Programmed by J. H. Kim
* Last updated : 2021-10-21 */
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "T_Array.h"
using namespace std;

#define NUM_STUDENTS 10
void main()
{
	Student students[NUM_STUDENTS] =
	{
	Student(5555, string("Kim"), Date(1998, 7, 15), Time(13, 20, 30), 3.57),
	Student(1234, string("Yoon"), Date(1999, 12, 25), Time(17, 30, 0), 4.37),
	Student(4444, string("Byun"), Date(2001, 3, 10), Time(22, 10, 50), 2.72),
	Student(2222, string("Lee"), Date(1997, 10, 9), Time(15, 30, 0), 3.35),
	Student(3333, string("Hong"), Date(2005, 3, 1), Time(11, 10, 0), 3.89),
	Student(6666, string("Jang"), Date(2000, 5, 21), Time(9, 20, 10), 4.42),
	Student(7777, string("Park"), Date(2002, 5, 1), Time(14, 20, 15), 4.12),
	Student(9999, string("Choi"), Date(1995, 6, 10), Time(10, 30, 0), 3.85),
	Student(1000, string("Shin"), Date(2003, 4, 5), Time(8, 15, 10), 3.21),
	Student(8888, string("Ahn"), Date(1996, 1, 1), Time(12, 5, 7), 4.45),
	};
	Student* pSt;
	int id_to_search, key_index;
	T_Array<Student, int> stArray_keyID(NUM_STUDENTS, "T_Array<Student, keyST_ID>");
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		stArray_keyID.insert(i, students[i]);
	}
	cout << "T_Array<Student_keyID> at initialization : " << endl;
	stArray_keyID.print(1);

	stArray_keyID[5].getKey(string("ST_ID"), &id_to_search);
	key_index = stArray_keyID.sequential_search(string("ST_ID"), id_to_search);
	cout << "id_to_search (" << id_to_search << ") => key_index : (" << key_index
		<< ")" << endl;
	cout << "stArray_keyID[" << key_index << "] = " << stArray_keyID[key_index]
		<< endl << endl;

	stArray_keyID.selection_sort(string("ST_ID"), INCREASING);
	cout << "T_Array<Student_keyID> after selection sorting (increasing order) by ST_ID : " << endl;
		stArray_keyID.print(1);

	T_Array<Student, double> stArray_keyGPA(NUM_STUDENTS, "T_Array<Student, keyGPA > ");
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		stArray_keyGPA.insert(i, students[i]);
	}
	stArray_keyGPA.selection_sort(string("GPA"), DECREASING);
	cout << "T_Array<Student, keyGPA> after selection_sorting (decreasing order) by GPA : " << endl;
	stArray_keyGPA.print(1);
}