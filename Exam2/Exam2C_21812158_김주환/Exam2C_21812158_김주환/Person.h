/* Person.h */
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"

class Person {
	friend ostream& operator<< (ostream& fout, const Person& p) { // ���
		fout << " Person [name: " << p.name << "]";
		return fout;
	}
public:
	// ������
	Person() { name = "nobody"; }
	Person(string n) { name = n; }

	void setName(string n) { name = n; } // �̸� ����
	string getName() { return name; } // �̸� ��ȯ
	void setDoB(Date dob) { dateOfBirth = dob; } // ���� ����
	const Date getDoB() const { return dateOfBirth; } // ���� ��ȯ
	void setArrivalTime(Time t) { arrivalTime = t; } // �ð� ����
	const Time getArrivalTime() const { return arrivalTime; } // �ð� ��ȯ
protected:
	string name;
	Date dateOfBirth; // date of birth
	Time arrivalTime;
};
#endif