/* main.cpp */
/* Description
* Date 및 Person 클래스
* Date 객체 생성 및 출력한다.
* 원하는 날짜를 입력하고 크리스마스까지 얼마나 남았는지 확인한다.
* Person 객체 생성한다. (Date를 데이터로 가진다.)
* Programmed by J. H. Kim
* Last updated : 2021-09-15 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include "Date.h"
#include "Person.h"
using namespace std;

#define NUM_PERSON 10

int main() {
	ofstream fout;
	fout.open("output.txt");
	if (fout.fail()) {
		cout << "Error in opening output.txt !!" << endl;
		exit;
	}

	/* part 1 - handling class Date */
	Date AD010101(1, 1, 1); // 객체 생성
	int year, month, day;
	int daysToChristmas;
	time_t currentTime;
	struct tm* time_and_date;

	time(&currentTime);
	time_and_date = localtime(&currentTime);
	year = time_and_date->tm_year + 1900;
	month = time_and_date->tm_mon + 1;
	day = time_and_date->tm_mday;
	Date newYearDay(year, 1, 1), today(year, month, day); // 객체 생성

	fout << "AD Jan. 1, 1 is ";
	AD010101.fprintDate(fout); // 서기 1년 1월 1일 정보 출력
	fout << endl;

	fout << "Today is ";
	today.fprintDate(fout); // 오늘 정보 출력
	fout << endl;

	fout << "New year's day of this year was ";
	newYearDay.fprintDate(fout); // 신년 정보 출력
	fout << endl;

	Date christmas(year, 12, 25); // 객체 생성
	fout << "Christmas of this year is ";
	christmas.fprintDate(fout); // 크리스마스 정보 출력
	fout << endl;

	if (today.getMonth() == christmas.getMonth() && today.getDay() == christmas.getDay()) // 크리스마스인지 확인
		fout << "Today is Christmas! Happy Christmas to you all !!" << endl;
	else { // 아니라면 크리스마스까지 남은 일수 출력
		fout << "Sorry, today is not Christmas!" << endl;
		daysToChristmas = christmas.getElapsedDaysFromAD010101()
			- today.getElapsedDaysFromAD010101();
		fout << "You must wait " << daysToChristmas << " day(s) to Christmas !" << endl;
	}
	fout << endl;

	/* part 2 - handling class Person */
	Person p1(string("Hong, Gil-Dong"), Date(2000, 1, 1)), p2; // 객체 생성
	fout << "Person p1 : " << endl;
	p1.fprintPerson(fout); // 지정 생성한 객체 정보 출력
	fout << endl;

	fout << "Person p2 : " << endl;
	p2.setName(string("Lee, Soo-Jeong"));
	p2.setBirthDate(Date(2018, 9, 1));
	p2.fprintPerson(fout); // 생성 후 init 해준 객체 정보 출력
	fout << endl;

	// 객체 배열 생성
	fout << endl << "Generating array of persons ..." << endl;
	Person* persons; // 
	persons = (Person*) new Person[NUM_PERSON];
	for (int i = 0; i < NUM_PERSON; i++) {
		persons[i].setRandPersonAttributes(); // error
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	fout << endl;
	
	// 객체 배열 정렬(이름)
	fout << endl << "Sorting array of persons by Name ..." << endl;
	persons->sortByName(persons, NUM_PERSON);
	for (int i = 0; i < NUM_PERSON; i++) {
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	fout << endl;

	// 객체 배열 정렬(생일)
	fout << endl << "Sorting array of persons by BirthDay ..." << endl;
	persons->sortByBirthDay(persons, NUM_PERSON);
	for (int i = 0; i < NUM_PERSON; i++) {
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	fout << endl;

	delete[] persons; // 소멸
	fout.close();

	return 0;
}