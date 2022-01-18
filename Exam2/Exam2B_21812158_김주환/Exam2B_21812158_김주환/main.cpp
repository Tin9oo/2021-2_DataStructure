/* main.cpp */
/* Description
* Student 구현
* list 출력
* Programmed by J. H. Kim
* Last updated : 2021-10-21 */
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Student.h"
#include "StlContainerHandler.h"
using namespace std;

#define NUM_TIMES 10
#define NUM_DATES 10
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
	list<Student> L_students(students, students + NUM_STUDENTS);
	printList(L_students, "STL list of Students - before sorting", 1);
	L_students.sort();
	printList(L_students, "STL list of Students - after sorting", 1);
}