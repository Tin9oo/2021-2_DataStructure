/* Student.cpp */
#include <iomanip>
#include "Student.h"

ostream& operator<< (ostream& fout, Student& st) {
	fout << "Student [ st_id: " << setw(5) << std::right << st.st_id;
	fout << ", name: " << setw(9) << std::left << st.name;
	fout << ", gpa: ";
	fout.precision(2);
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout << setw(5) << st.gpa;
	fout << ", arrival: " << std::right << st.arrivalTime << "]";
	return fout;
}
Student::Student()
	:Person(), st_id(0), gpa(0.0) {
	name = "noname";
	arrivalTime = Time(0, 0, 0);
}
Student::Student(int s_id, string n, Time avt, double gpa)
	: Person(n), st_id(s_id), gpa(gpa) {
	arrivalTime = avt;
}
void print_students(Student* students, int size) {
	for (int i = 0; i < size; i++) {
		cout << students[i] << endl;
	}
}
void sort_students_by_arrival_time(Student* students, int size) {
	int index_min, index_max; // index of the element with minimum value
	Student tempElement;
	int minKey, key;

	for (int i = 0; i < size - 1; i++) {
		index_min = i;
		minKey = students[i].getArrivalTime().elasedSec();
		for (int j = i + 1; j < size; j++) {
			key = students[j].getArrivalTime().elasedSec();
			if (key < minKey) {
				index_min = j;
				minKey = key;
			}
		}
		if (index_min != i) { // if a smaller element is found, then swap
			tempElement = students[index_min];
			students[index_min] = students[i];
			students[i] = tempElement;
		}
	} // end for
}