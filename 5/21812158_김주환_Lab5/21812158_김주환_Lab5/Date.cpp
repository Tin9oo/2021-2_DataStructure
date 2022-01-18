/* Date.cpp */
#include <iostream>
#include <iomanip>
#include "Date.h"

istream& operator>>(istream& fin, Date& d) {
	fin >> d.year >> d.month >> d.day;
	return fin;
}
ostream& operator<<(ostream& fout, const Date& d) {
	fout << "Birth date : (" << d.year << "-" << setw(2) << d.month << "-" << setw(2) << d.day << ")";
	return fout;
}
Date::Date() {
	year = 0, month = 0, day = 0;
}
Date::Date(int y, int m, int d) {
	year = y, month = m, day = d;
}
void Date::setDate(int newYear, int newMonth, int newDay) {
	if (isValidDate(newYear, newMonth, newDay))
		year = newYear, month = newMonth, day = newDay;
	else {
		cout << "Invalid date (" << newYear << ", " << newMonth << ", " << newDay << ")";
		cout << "Program aborted !!" << endl;
		exit(1);
	}
}
int Date::getYearDay() {
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yearDay = 0;

	if (isLeapYear(this->year))
		days_month[2] = 29;

	for (int i = 1; i < month; i++)
		yearDay += days_month[i];

	return yearDay + day;

	return yearDay;
}
int Date::getWeekDay() {
	int weekDay_AD010101 = 1;
	int weekDay;
	int elapsedDays = 0;

	elapsedDays = getElapsedDays();
	weekDay = (elapsedDays + weekDay_AD010101 - 1) % 7; // 최초는 월욜이면 추가 안하면 대지않나?

	// cout << ", Elapsed days from AD Jan. 1, 1 (" << elapsedDays << ")";

	return weekDay;
}
int Date::getElapsedDays() {
	int yearDay;
	int elpsDay = 0;

	for (int y = 1; y < this->year; y++) {
		if (isLeapYear(y)) elpsDay += 366;
		else elpsDay += 365;
	}
	yearDay = getYearDay();
	elpsDay += yearDay;

	return elpsDay;
}
const Date Date::operator=(const Date rightSide) {
	year = rightSide.year;
	month = rightSide.month;
	day = rightSide.day;

	return *this;
}
bool Date::operator>(Date rightSide) {
	int tl, tr;
	tl = getElapsedDays();
	tr = rightSide.getElapsedDays();
	if (tl > tr) return true;
	else return false;
}
bool Date::operator<(Date rightSide) {
	int tl, tr;
	tl = getElapsedDays();
	tr = rightSide.getElapsedDays();
	if (tl < tr) return true;
	else return false;
}
bool Date::operator==(Date rightSide) {
	int tl, tr;
	tl = getElapsedDays();
	tr = rightSide.getElapsedDays();
	if (tl == tr) return true;
	else return false;
}
bool Date::operator!=(Date rightSide) {
	int tl, tr;
	tl = getElapsedDays();
	tr = rightSide.getElapsedDays();
	if (tl != tr) return true;
	else return false;
}
bool Date::isLeapYear(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	else
		return false;
}
bool Date::isLeapYear() {
	return isLeapYear(year);
}
bool Date::isValidDate(int y, int m, int d) {
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(y)) days_month[2] = 29;
	if ((m >= 1) && (m <= 12) && (d >= 1) && (d <= days_month[m])) return true; // 범위 내의 정보인지 확인
	else {
		cout << "Illegal date! (" << m << ", " << d << ") ==> Program aborted." << endl;
		return false;
	}
}
bool isLeapYear(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	else
		return false;
}
Date genRandDate() {
	Date d;
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;

	year = rand() % 2000 + 1000;
	month = rand() % 12 + 1;
	if (isLeapYear(year) && month == 2) days_month[2] = 29; // 윤년 확인
	day = rand() % days_month[month] + 1;

	d.setDate(year, month, day);

	return d;
}