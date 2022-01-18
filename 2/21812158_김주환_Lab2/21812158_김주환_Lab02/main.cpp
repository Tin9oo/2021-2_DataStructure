/* main.cpp */
/* Description
* Date �� Person Ŭ����
* Date ��ü ���� �� ����Ѵ�.
* ���ϴ� ��¥�� �Է��ϰ� ũ������������ �󸶳� ���Ҵ��� Ȯ���Ѵ�.
* Person ��ü �����Ѵ�. (Date�� �����ͷ� ������.)
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
	Date AD010101(1, 1, 1); // ��ü ����
	int year, month, day;
	int daysToChristmas;
	time_t currentTime;
	struct tm* time_and_date;

	time(&currentTime);
	time_and_date = localtime(&currentTime);
	year = time_and_date->tm_year + 1900;
	month = time_and_date->tm_mon + 1;
	day = time_and_date->tm_mday;
	Date newYearDay(year, 1, 1), today(year, month, day); // ��ü ����

	fout << "AD Jan. 1, 1 is ";
	AD010101.fprintDate(fout); // ���� 1�� 1�� 1�� ���� ���
	fout << endl;

	fout << "Today is ";
	today.fprintDate(fout); // ���� ���� ���
	fout << endl;

	fout << "New year's day of this year was ";
	newYearDay.fprintDate(fout); // �ų� ���� ���
	fout << endl;

	Date christmas(year, 12, 25); // ��ü ����
	fout << "Christmas of this year is ";
	christmas.fprintDate(fout); // ũ�������� ���� ���
	fout << endl;

	if (today.getMonth() == christmas.getMonth() && today.getDay() == christmas.getDay()) // ũ������������ Ȯ��
		fout << "Today is Christmas! Happy Christmas to you all !!" << endl;
	else { // �ƴ϶�� ũ������������ ���� �ϼ� ���
		fout << "Sorry, today is not Christmas!" << endl;
		daysToChristmas = christmas.getElapsedDaysFromAD010101()
			- today.getElapsedDaysFromAD010101();
		fout << "You must wait " << daysToChristmas << " day(s) to Christmas !" << endl;
	}
	fout << endl;

	/* part 2 - handling class Person */
	Person p1(string("Hong, Gil-Dong"), Date(2000, 1, 1)), p2; // ��ü ����
	fout << "Person p1 : " << endl;
	p1.fprintPerson(fout); // ���� ������ ��ü ���� ���
	fout << endl;

	fout << "Person p2 : " << endl;
	p2.setName(string("Lee, Soo-Jeong"));
	p2.setBirthDate(Date(2018, 9, 1));
	p2.fprintPerson(fout); // ���� �� init ���� ��ü ���� ���
	fout << endl;

	// ��ü �迭 ����
	fout << endl << "Generating array of persons ..." << endl;
	Person* persons; // 
	persons = (Person*) new Person[NUM_PERSON];
	for (int i = 0; i < NUM_PERSON; i++) {
		persons[i].setRandPersonAttributes(); // error
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	fout << endl;
	
	// ��ü �迭 ����(�̸�)
	fout << endl << "Sorting array of persons by Name ..." << endl;
	persons->sortByName(persons, NUM_PERSON);
	for (int i = 0; i < NUM_PERSON; i++) {
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	fout << endl;

	// ��ü �迭 ����(����)
	fout << endl << "Sorting array of persons by BirthDay ..." << endl;
	persons->sortByBirthDay(persons, NUM_PERSON);
	for (int i = 0; i < NUM_PERSON; i++) {
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	fout << endl;

	delete[] persons; // �Ҹ�
	fout.close();

	return 0;
}