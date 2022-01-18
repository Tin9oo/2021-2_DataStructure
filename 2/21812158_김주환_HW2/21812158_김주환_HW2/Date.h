/* Date.h */
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstdlib>
using namespace std;

#define WEEKDAT_AD01JAN01 MON
#define DAYS_PER_WEEK 7
#define Secs_in_Minute 60
#define Secs_in_Hour (Secs_in_Minute * 60)
#define Secs_in_DAY (Secs_in_Hour * 24)
#define LOCAL_GMT_OFFSET_HOUR 9

class Date {
public:
	Date(); // ������
	Date(int y, int m, int d); // ���� ����
	~Date(); // �Ҹ���
	void input(); // �Է�
	void print(); // ���
	void setDate(int y, int m, int dy); // ���� ����
	void setRandDateAttributes(); // ���� ���� ����
	void setMonth(int m); // �� ���� ����
	void setYear(int y); // �� ���� ����
	int getYear() { return year; } // �� ���� ��ȯ
	int getMonth() { return month; } // �� ���� ��ȯ
	int getDay() { return day; } // �� ���� ��ȯ
	int getYearDay(); // ��� �� ��
	int getYearDay(int m, int d);
	int getWeekDay(); // ���� ��ȯ
	int getElapsedDays(); // ���ʺ��� ��� �� ��
	int getElapsedDays(Date); // ���ʺ��� ��� �� ��
	void fprintCalendar_Month(ostream& fout);
private:
	bool isLeapYear(); // ���� Ȯ��
	bool isLeapYear(int y); // ���� ���� Ȯ��
	bool isValidDate(int y, int m, int d); // ��ȿ�� ��¥���� Ȯ��
	int year, month, day;
};
#endif