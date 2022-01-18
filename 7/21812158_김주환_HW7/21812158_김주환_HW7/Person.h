/* Person.h */
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "Date.h"
#include "Time.h"

class Person {
	friend ostream& operator<< (ostream& fout, const Person& p) { // Ãâ·Â
		fout << " Person [name: " << p.name << "]";
		return fout;
	}
public:
	Person() { name = "noname"; }
	Person(string n) { name = n; }
protected:
	Date dateOfBirth;
	string name;
};
#endif