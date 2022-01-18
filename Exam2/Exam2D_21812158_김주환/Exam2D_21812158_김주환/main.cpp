/* main.cpp */
/* Description
* T_Array 로 Student 다루기
* 병합정렬 추가
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
	int key_index;
	T_Array<Student, string> stArray_keyName(NUM_STUDENTS, "T_Array<Student, keyName > ");
		for (int i = 0; i < NUM_STUDENTS; i++)
		{
			stArray_keyName.insert(i, students[i]);
		}
	stArray_keyName.selection_sort(string("ST_NAME"), INCREASING);
	cout << endl << "T_Array<Student_keyName> after selection sorting (increasing order) by name : " << endl;
		stArray_keyName.print(1);
	string name_to_search;
	stArray_keyName[5].getKey(string("ST_NAME"), &name_to_search);
	cout << "name_to_search (" << name_to_search << ")" << endl;
	key_index = stArray_keyName.binary_search(string("ST_NAME"),
		name_to_search);
	cout << "stArray_keyName[" << key_index << "] = "
		<< stArray_keyName[key_index] << endl;
	T_Array<Student, Date> stArray_keyDoB(NUM_STUDENTS, "Array of Students, date of birth as key");
		for (int i = 0; i < NUM_STUDENTS; i++)
		{
			stArray_keyDoB.insert(i, students[i]);
		}
	stArray_keyDoB.merge_sort(string("BIRTH_DATE"), DECREASING);
	cout << endl << "stArray_keyDoB after merge sorting (decreasing order) by date of birth : " << endl;
		stArray_keyDoB.print(1);
	T_Array<Student, Time> stArray_keyTime(NUM_STUDENTS, "Array of Students, arrival time as key");
		for (int i = 0; i < NUM_STUDENTS; i++)
		{
			stArray_keyTime.insert(i, students[i]);
		}
	stArray_keyTime.merge_sort(string("ARRIVAL_TIME"), INCREASING);
	cout << endl << "stArray_keyArrTm after merge sorting (increasing order) by arrival time : " << endl;
		stArray_keyTime.print(1);
	Time time_to_search;
	stArray_keyTime[5].getKey(string("ARRIVAL_TIME"), &time_to_search);
	cout << "time_to_search (" << time_to_search << ")" << endl;
	key_index = stArray_keyTime.binary_search(string("ARRIVAL_TIME"),
		time_to_search);
	cout << "stArray_keyTime[" << key_index << "] = "
		<< stArray_keyTime[key_index] << endl;
}