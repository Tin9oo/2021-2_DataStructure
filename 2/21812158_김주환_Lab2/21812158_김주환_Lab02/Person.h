/* Person.h */
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Date.h"
using namespace std;

#define MAX_NAME_LEN 15
#define MIN_NAME_LEN 5

class Person {
public:
	Person() : name(string("nobody")), birthDate(Date(1, 1, 1)) { } // 생성
	Person(string n, Date bd) : name(n), birthDate(bd) { } 
	~Person() { cout << "Person object instance is destructed" << endl; } // 소멸
	void setName(string n) { name = n; } // 이름 설정
	string getName() { return name; } // 이름 반환
	void setBirthDate(Date bd) { birthDate = bd; } // 생일 설정
	Date getBirthDate() { return birthDate; } // 생일 반환
	void setRandPersonAttributes(); // 무작위 인물 정보 설정
	void fprintPerson(ostream& fout); // 출력
	void sortByName(Person persons[], int num_person); // 이름으로 정렬
	void sortByBirthDay(Person persons[], int num_person); // 생일로 정렬
private:
	Date birthDate;
	string name;
};
#endif