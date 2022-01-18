/* main.cpp - T_Array<Student, K> */
/* Description
* 템플릿 구현
* STL 기능 사용과 기능 직접 구현
* 각 단계별 동작 확인
* Programmed by J. H. Kim
* Last updated : 2021-10-15 */

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
using namespace std;

#define NUM_STUDENTS 10

void main()
{
	Student students[NUM_STUDENTS] =
	{
	Student(5234, string("Kim,  G-M"), Time(3, 0, 30), 3.57),
	Student(1999, string("Yoon, S-M"), Time(7, 30, 0), 4.37),
	Student(4141, string("Byun, S-S"), Time(2, 0, 50), 2.72),
	Student(2167, string("Lee,  K-M"), Time(5, 30, 0), 3.35),
	Student(3890, string("Hong, G-M"), Time(1, 10, 0), 3.89),
	Student(6543, string("Jang, S-M"), Time(9, 20, 10), 4.42),
	Student(7080, string("Park, S-T"), Time(1, 20, 15), 4.12),
	Student(9564, string("Choi, Y-H"), Time(10, 0, 0), 3.85),
	Student(1000, string("Shin, D-J"), Time(11, 15, 10), 3.21),
	Student(8812, string("Ahn,  S-B"), Time(2, 0, 5), 4.45),
	};
	cout << "students before sorting :" << endl;
	print_students(students, NUM_STUDENTS);
	sort_students_by_arrival_time(students, NUM_STUDENTS);
	cout << "\nstudents after sorting by arrival time :" << endl;
	print_students(students, NUM_STUDENTS);
}