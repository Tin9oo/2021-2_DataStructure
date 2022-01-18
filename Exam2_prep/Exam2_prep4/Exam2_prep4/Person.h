/* Person.h */
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Time.h"

class Person
{
	friend ostream& operator<< (ostream& fout, const Person& p);
public:
	Person();
	Person(string n);
	void setName(string n);
	string getName();
	void setArrivalTime(Time t);
	const Time getArrivalTime() const;
protected:
	string name;
	Time arrivalTime;
};
#endif