/* Time.h */
#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {
	friend ostream& operator<<(ostream&, const Time&); // 출력
public:
	// 생성자
	Time() { hour = 0; min = 0; sec = 0; } // default constructor
	Time(int h, int m, int s);

	int elasedSec() const; // Time 정보를 초로 환산 후 반환
	Time getTime() const { return Time(hour, min, sec); } // Time 정보 반환

	// 비교연산자
	bool operator<(const Time&) const;
	bool operator<=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator>=(const Time&) const;
	bool operator==(const Time&) const;
private:
	bool isValidTime(int, int, int); // 유효한 Time 정보인지 판단
	int hour;
	int min;
	int sec;
};
#endif