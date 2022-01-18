/* Date.h */
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

#define WEEKDAY_AD01Jan01 MON // the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7

class Date {
	friend ostream& operator<<(ostream&, const Date&); // ���
public:
	// ������ & �Ҹ���
	Date(); // default constructor
	Date(int y, int m, int d); // constructor
	~Date(); // destructor

	int getWeekDay(); // ���� ��ȯ
	int getElapsedDaysFromAD010101() const; // get elapsed days from AD 1. 1. 1.
	int getElapsedDaysFromAD010101(Date) const;

	// �񱳿�����
	bool operator<(const Date&) const;
	bool operator<=(const Date&) const;
	bool operator>(const Date&) const;
	bool operator>=(const Date&) const;
	bool operator==(const Date&) const;
private:
	bool isValidDate(int y, int m, int d); // ��ȿ�� Date �������� �Ǵ�
	int year;
	int month;
	int day;
};
bool isLeapYear(int y); // check whether the given year y is leap year
int getYearDay(int year, int month, int day); // �ش� ������ ���° ������ ��ȯ
#endif 