/* Time.cpp */
#include <iomanip>
#include "Time.h"

ostream& operator<<(ostream& fout, const Time& t) {
	fout << "(" << setw(2) << t.hour << ":" << setw(2) << t.min << ":" << setw(2) << t.sec << ")";
	return fout;
}
Time::Time()
	: hour(0), min(0), sec(0) {
	// cout << "constructor for Time << endl;
}
Time::Time(int h, int m, int s)
	: hour(h), min(m), sec(s) {
	// cout << "constructor for Time << endl;
}
Time& Time::operator+(int s) {
	Time tTm(0, 0, 0);
	int et = this->elasedSec();
	et += s;
	tTm.sec = et % 60;
	et /= 60;
	tTm.min = et % 60;
	et /= 60;
	tTm.hour = et % 60;

	return tTm;
}
int Time::elasedSec() {
	return 3600 * hour + 60 * min + sec;
}
Time Time::getTime() {
	return Time(hour, min, sec);
}
bool Time::operator<(Time& t) {
	if (this->elasedSec() < t.elasedSec())
		return true;
	else
		return false;
}
bool Time::operator<=(Time& t) {
	if (this->elasedSec() <= t.elasedSec())
		return true;
	else
		return false;
}
bool Time::operator>(Time& t) {
	if (this->elasedSec() > t.elasedSec())
		return true;
	else
		return false;
}
bool Time::operator>=(Time& t) {
	if (this->elasedSec() >= t.elasedSec())
		return true;
	else
		return false;
}
bool Time::operator==(Time& t) {
	if (this->elasedSec() == t.elasedSec())
		return true;
	else
		return false;
}
bool Time::isValidTime(int h, int m, int s) {
	if (0 <= h && h <= 24)
		if (0 <= m && m <= 60)
			if (0 <= s && s <= 60)
				return true;
	return false;
}