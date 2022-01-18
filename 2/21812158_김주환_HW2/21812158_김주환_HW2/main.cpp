/* main.cpp */
/* Description
* Date 객체를 생성한다.
* 원하는 날짜를 입력하고 크리스마스까지 얼마나 남았는지 확인한다.
* Programmed by J. H. Kim
* Last updated : 2021-09-15 */
#include <iostream>
#include "Date.h"
using namespace std;
int main() {
	Date AD010101(1, 1, 1), newYearDay(2021, 1, 1), today, christmas(2021, 12, 25); // 객체 생성
	int year;
	int daysToChristmas;
	cout << "AD Jan. 1, 1 is ";
	AD010101.print(); // 서기 1년 1월 1일 정보 출력
	cout << endl;
	cout << "New year's day of 2020 is ";
	newYearDay.print(); // 금년 1월 1일 정보 출력
	cout << endl;
	cout << "Christmas of this year is ";
	christmas.print(); // 크리스마스 정보 출력
	cout << endl;
	today.input(); // 오늘 정보 입력
	cout << "Today is ";
	today.print(); // 오늘 정보 출력
	cout << endl;
	if (today.getMonth() == christmas.getMonth() && // 입력받은 Date가 크리스마스인지 확인
		today.getDay() == christmas.getDay()) {
		cout << "Happy Christmas !!\n";
	}
	else { // 아닐경우
		cout << "Sorry, today is not Christmas!";
		daysToChristmas = christmas.getElapsedDays() - today.getElapsedDays(); // 크리스마스까지 얼마나 남았는지 계산
		cout << " You must wait " << daysToChristmas << " day(s) to Christmas !" << endl;
	}
	return 0;
}