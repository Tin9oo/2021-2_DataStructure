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
	Date(); // 생성자
	Date(int y, int m, int d); // 지정 생성
	~Date(); // 소멸자
	void input(); // 입력
	void print(); // 출력
	void setDate(int y, int m, int dy); // 정보 설정
	void setRandDateAttributes(); // 랜덤 정보 설정
	void setMonth(int m); // 월 정보 설정
	void setYear(int y); // 연 정보 설정
	int getYear() { return year; } // 연 정보 반환
	int getMonth() { return month; } // 월 정보 반환
	int getDay() { return day; } // 일 정보 반환
	int getYearDay(); // 경과 일 수
	int getYearDay(int m, int d);
	int getWeekDay(); // 요일 반환
	int getElapsedDays(); // 최초부터 경과 일 수
	int getElapsedDays(Date); // 최초부터 경과 일 수
	void fprintCalendar_Month(ostream& fout);
private:
	bool isLeapYear(); // 윤년 확인
	bool isLeapYear(int y); // 윤년 지정 확인
	bool isValidDate(int y, int m, int d); // 유효한 날짜인지 확인
	int year, month, day;
};
#endif