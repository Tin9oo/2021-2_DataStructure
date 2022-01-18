/* Person.h */
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"

class Person {
	friend ostream& operator<< (ostream& fout, const Person& p) { // 출력
		fout << " Person [name: " << p.name << "]";
		return fout;
	}
public:
	// 생성자
	Person() { name = "nobody"; }
	Person(string n) { name = n; }

	void setName(string n) { name = n; } // 이름 설정
	string getName() { return name; } // 이름 반환
	void setDoB(Date dob) { dateOfBirth = dob; } // 생일 설정
	const Date getDoB() const { return dateOfBirth; } // 생일 반환
	void setArrivalTime(Time t) { arrivalTime = t; } // 시간 설정
	const Time getArrivalTime() const { return arrivalTime; } // 시간 반환
protected:
	string name;
	Date dateOfBirth; // date of birth
	Time arrivalTime;
};
#endif