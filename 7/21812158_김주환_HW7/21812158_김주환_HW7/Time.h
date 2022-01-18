/* Time.h */
#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {
	friend ostream& operator<<(ostream&, const Time&);
public:
	Time(); // default constructor
	Time(int h, int m, int s); // 생성자
	Time& operator+(int s); // 연산자 오버로딩
	int elasedSec(); // 지난 초 계산
	Time getTime(); // Time 정보 반환
	
	// 비교연산자
	bool operator<(Time&);
	bool operator<=(Time&);
	bool operator>(Time&);
	bool operator>=(Time&);
	bool operator==(Time&);
private:
	bool isValidTime(int, int, int); // 유효한 Time 정보인지 판단
	int hour;
	int min;
	int sec;
}; 
#endif