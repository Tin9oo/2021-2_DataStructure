/* Date.h */
#ifndef D_H
#define D_H
#include <iostream>
#include <iomanip>
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

	void setDate(int newYear, int newMonth, int newDay); // Date ����
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
#endif // !D_H