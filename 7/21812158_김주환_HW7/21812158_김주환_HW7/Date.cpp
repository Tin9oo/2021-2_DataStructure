/* Date.cpp*/
#include <iomanip>
#include "Date.h"

ostream& operator<<(ostream& fout, const Date& d) {
	fout << "(" << setw(2) << d.year << "." << setw(2) << d.month << "." << setw(2) << d.day << ")";
	return fout;
}
Date::Date()
	: year(0), month(0), day(0) {
	// cout << "constructor for Date" << endl;
}
Date::Date(int y, int m, int d)
	: year(y), month(m), day(d) {
	// cout << "constructor for Date" << endl;
}
Date::~Date() {
	// cout << "destructor for Date" << endl;
}
int Date::getWeekDay() {
	int weekDay_AD010101 = 1;
	int weekDay;
	int elapsedDays = 0;

	elapsedDays = getElapsedDaysFromAD010101();
	weekDay = (elapsedDays + weekDay_AD010101 - 1) % 7; // 최초는 월욜이면 추가 안하면 대지않나?

	// cout << ", Elapsed days from AD Jan. 1, 1 (" << elapsedDays << ")";

	return weekDay;
}
int Date::getElapsedDaysFromAD010101() const {
	int yearDay;
	int elpsDay = 0;

	for (int y = 1; y < this->year; y++) {
		if (isLeapYear(y)) elpsDay += 366;
		else elpsDay += 365;
	}
	yearDay = getYearDay(this->year, this->month, this->day);
	elpsDay += yearDay;

	return elpsDay;
}
int Date::getElapsedDaysFromAD010101(Date d) const {
	return d.getElapsedDaysFromAD010101();
}
bool Date::operator<(const Date& d) const {
	int tl, tr;
	tl = getElapsedDaysFromAD010101();
	tr = d.getElapsedDaysFromAD010101();
	if (tl < tr) return true;
	else return false;
}
bool Date::operator<=(const Date& d) const {
	int tl, tr;
	tl = getElapsedDaysFromAD010101();
	tr = d.getElapsedDaysFromAD010101();
	if (tl <= tr) return true;
	else return false;
}
bool Date::operator>(const Date& d) const {
	int tl, tr;
	tl = getElapsedDaysFromAD010101();
	tr = d.getElapsedDaysFromAD010101();
	if (tl > tr) return true;
	else return false;
}
bool Date::operator>=(const Date& d) const {
	int tl, tr;
	tl = getElapsedDaysFromAD010101();
	tr = d.getElapsedDaysFromAD010101();
	if (tl >= tr) return true;
	else return false;
}
bool Date::operator==(const Date& d) const {
	int tl, tr;
	tl = getElapsedDaysFromAD010101();
	tr = d.getElapsedDaysFromAD010101();
	if (tl == tr) return true;
	else return false;
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
int getYearDay(int year, int month, int day) {
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yearDay = 0;

	if (isLeapYear(year))
		days_month[2] = 29;

	for (int i = 1; i < month; i++)
		yearDay += days_month[i];

	return yearDay + day;
}