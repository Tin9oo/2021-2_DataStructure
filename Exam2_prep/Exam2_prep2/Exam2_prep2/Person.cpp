/* Person.cpp */
#include "Person.h"

ostream& operator<< (ostream& fout, const Person& p) {
	fout << " Person [name: " << p.name << "]";
	return fout;
}
Person::Person() {
	name = "nobody";
}
Person::Person(string n) {
	name = n;
}
void Person::setName(string n) {
	name = n;
}
string Person::getName() {
	return name;
}
void Person::setArrivalTime(Time t) {
	arrivalTime = t;
}
const Time Person::getArrivalTime() const {
	return arrivalTime;
}