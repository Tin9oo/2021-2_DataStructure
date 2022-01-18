/* Student.h */
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Date.h"
#include "Time.h"

class Student : public Person {
	friend ostream& operator<< (ostream&, Student&); // 출력
public:
	// 생성자
	Student(); // default constructor
	Student(int s_id, string n, Date dob, Time avt, double gpa);

	void getKey(string keyName, void* pKey); // 키 반환

	// 비교연산자
	bool operator<(const Student&) const;
	bool operator<=(const Student&) const;
	bool operator>(const Student&) const;
	bool operator>=(const Student&) const;
	bool operator==(const Student&) const;
private:
	int st_id;
	double gpa;
};
#endif 