/* Date.cpp */
#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };
enum MONTH { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, NUM_MONTHS };
const char* weekDayName[DAYS_PER_WEEK] = { "Sunday", "Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday" };
const char* weekDayNameShort[DAYS_PER_WEEK] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July",
"August", "September", "October", "November", "December" };

Date::Date() {
	year = 0, month = 0, day = 0;
}
Date::Date(int y, int m, int d) {
	year = y, month = m, day = d;
}
Date::~Date() {
	// cout << "Date object instance is destructed" << endl;
}
bool Date::isValidDate(int y, int m, int d) {
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(y)) days_month[2] = 29; // 윤년 확인
	if ((m >= 1) && (m <= 12) && (d >= 1) && (d <= days_month[m])) return true; // 범위 내의 Date인지 확인
	else {
		cout << "Illegal date! (" << m << ", " << d << ") ==> Program aborted." << endl;
		return false;
	}
}
void Date::setDate(int y, int m, int d) {
	if (isValidDate(y, m, d)) year = y, month = m, day = d;
	else {
		cout << "Invalid date (" << y << ", " << m << ", " << d << ")";
		cout << "Program aborted !!" << endl;
		exit(1);
	}
}
void Date::setRandDateAttributes() {
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	year = rand() % 2000 + 1000;
	month = rand() % 12 + 1;
	if (isLeapYear(year) && month == 2) days_month[2] = 29; // 윤년 확인
	day = rand() % days_month[month] + 1;
}
void Date::setMonth(int newMonth) {
	if ((newMonth >= 1) && (newMonth <= 12)) month = newMonth;
	else {
		cout << "Illegal month value! Program aborted." << endl;
		exit(1);
	}
	day = 1;
}
void Date::setYear(int y) {
	year = y;
}
int Date::getYearDay() {
	int yearDay = 0;
	getYearDay(this->month, this->day);

	return yearDay;
}
int Date::getYearDay(int month, int day) {
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yearDay = 0;

	if (isLeapYear(this->year))
		days_month[2] = 29;

	for (int i = 1; i < month; i++)
		yearDay += days_month[i];

	return yearDay + day;
}
int Date::getElapsedDays() {
	int elpsDay = 0;
	elpsDay = getElapsedDays(*this);

	return elpsDay;
}
int Date::getElapsedDays(Date d) {
	int yearDay;
	int elpsDay = 0;

	for (int y = 1; y < d.year; y++) {
		if (isLeapYear(y)) elpsDay += 366;
		else elpsDay += 365;
	}
	yearDay = getYearDay(d.month, d.day);
	elpsDay += yearDay;

	return elpsDay;
}
int Date::getWeekDay() {
	int weekDay_AD010101 = MON;
	int weekDay;
	int elapsedDays = 0;

	elapsedDays = getElapsedDays();
	weekDay = (elapsedDays + weekDay_AD010101 - 1) % 7; // 최초는 월욜이면 추가 안하면 대지않나?

	// cout << ", Elapsed days from AD Jan. 1, 1 (" << elapsedDays << ")";

	return weekDay;
}
void Date::input() {
	int y, m, d;

	cout << "Enter date in year month day : ";
	cin >> y >> m >> d;
	if (isValidDate(y, m, d)) year = y, month = m, day = d;
	else {
		cout << "Illegal date! Program aborted." << endl;
		exit(1);
	}
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
void Date::print() {
	const char* weekDayName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday" };
	const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July",
		"August", "September", "October", "November", "December" };
	int yearDay = 0;
	int weekDay;
	if ((month >= 1) && (month <= 12))
		cout << setw(10) << string(monthName[month]);
	cout << " " << setw(2) << day << ", " << setw(4) << year;
	yearDay = getYearDay();
	weekDay = getWeekDay();
	cout << " (" << setw(10) << string(weekDayName[weekDay]) << ")";
}