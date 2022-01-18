/* Date.h */
#ifndef D
#define D
#include <fstream>
using namespace std;
class Date {
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);
public:
	Date(); // 생성자
	Date(int y, int m, int d); // 생성자
	void setDate(int newYear, int newMonth, int newDay); // Date 설정
	int getYear() { return year; } // 연도 반환
	int getYearDay(); // 이번년도 지난 일 수 반환
	int getWeekDay(); // 요일 반환
	int getElapsedDays(); // 최초부터 지난 일 수 반환
	const Date operator=(const Date rightSide); // 대입연산자
	bool operator>(Date rightSide); // 비교연산자
	bool operator<(Date rightSide); // 비교연산자
	bool operator==(Date rightSide); // 비교연산자
	bool operator!=(Date rightSide); // 비교연산자
	bool isLeapYear(int y); // 윤년 확인
private:
	bool isLeapYear(); // 윤년 확인
	bool isValidDate(int y, int m, int d); // 유효한 Date 인지 확인
	int year;
	int month;
	int day;
};

bool isLeapYear(int y); // 윤년 확인
Date genRandDate(); // Date 랜덤 생성
#endif // !D
