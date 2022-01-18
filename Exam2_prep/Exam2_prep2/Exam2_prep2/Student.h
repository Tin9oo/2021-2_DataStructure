/* Student.h */
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Time.h"

class Student : public Person
{
	friend ostream& operator<< (ostream&, Student&);
public:
	Student(); // default constructor
	Student(int s_id, string n, Time avt, double gpa);
	const int getST_id() const { return st_id; }
	void setST_id(int id) { st_id = id; }
	const double getGPA() const { return gpa; }
	void setGPA(double g) { gpa = g; }
private:
	int st_id;
	double gpa;
};
void print_students(Student* students, int size);
void sort_students_by_arrival_time(Student * students, int size);
#endif