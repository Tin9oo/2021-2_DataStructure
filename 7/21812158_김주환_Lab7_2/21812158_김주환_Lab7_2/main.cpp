/* main.cpp – STL vector and algorithm for class Student */
/* Description
* VectorHandler 템플릿 구현
* Programmed by J. H. Kim
* Last updated : 2021-10-15 */
#include <iostream>
#include <conio.h> // for _getch()
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Time.h"
#include "Date.h"
#include "Student.h"
#include "VectorHandler.h"
using namespace std;

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

	vector<Student> v_students(students, students + NUM_DATES); // 벡터

	cout << "Initial v_students :" << endl; // 초기 출력
	printVector(v_students);

	sort(v_students.begin(), v_students.end()); // 벡터 정렬

	cout << "₩nstudents after sorting by st_id :" << endl; // 정렬 후 벡터 출력
	printVector(v_students);

	cout << "Hit any key to continue .... "; // 키보드 입력 대기
	_getch();
	cout << endl;
}