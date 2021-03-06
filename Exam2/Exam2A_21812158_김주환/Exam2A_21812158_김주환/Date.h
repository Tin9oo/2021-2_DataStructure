/* Date.h */
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

#define WEEKDAY_AD01Jan01 MON // the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7

class Date
{
	friend ostream& operator<<(ostream&, const Date&);
public:
	Date(); // default constructor
	Date(int y, int m, int d); // constructor
	~Date(); // destructor
	int getWeekDay();
	int getElapsedDaysFromAD010101() const; // elapsed days from AD 1. 1. 1.
	int getElapsedDaysFromAD010101(Date) const;
	bool operator<(const Date&) const;
	bool operator<=(const Date&) const;
	bool operator>(const Date&) const;
	bool operator>=(const Date&) const;
	bool operator==(const Date&) const;
private:
	bool isValidDate(int y, int m, int d);
	int year;
	int month;
	int day;
};
bool isLeapYear(int y); // check whether the given year y is leap year
int getYearDay(int year, int month, int day); // 해당 연도의 몇번째 일인지 반환
#endif 