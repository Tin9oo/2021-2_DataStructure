/* Date.h */
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

#define WEEKDAY_AD01Jan01 MON // the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7

class Date {
	friend ostream& operator<<(ostream&, const Date&); // 출력
public:
	// 생성자 & 소멸자
	Date(); // default constructor
	Date(int y, int m, int d); // constructor
	~Date(); // destructor

	int getWeekDay(); // 요일 반환
	int getElapsedDaysFromAD010101() const; // get elapsed days from AD 1. 1. 1.
	int getElapsedDaysFromAD010101(Date) const;

	// 비교연산자
	bool operator<(const Date&) const;
	bool operator<=(const Date&) const;
	bool operator>(const Date&) const;
	bool operator>=(const Date&) const;
	bool operator==(const Date&) const;
private:
	bool isValidDate(int y, int m, int d); // 유효한 Date 정보인지 판단
	int year;
	int month;
	int day;
};
bool isLeapYear(int y); // check whether the given year y is leap year
int getYearDay(int year, int month, int day); // 해당 연도의 몇번째 일인지 반환
#endif 