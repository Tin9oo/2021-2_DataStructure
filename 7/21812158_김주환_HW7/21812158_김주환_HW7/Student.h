/* Student.h */
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person {
	friend ostream& operator<< (ostream&, const Student&);
public:
	Student(); // default constructor
	Student(int id, string n, Date d, Time avt, double gpa);
	bool operator<(Student& st); // compare by arrival time
	bool operator<=(Student& st); // compare by arrival time
	bool operator>(Student& st); // compare by arrival time
	bool operator>=(Student& st); // compare by arrival time
private:
	int st_id;
	double gpa;
	Time arrivalTime;
};
#endif 