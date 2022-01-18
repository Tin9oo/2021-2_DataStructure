/* Time.cpp */
#include <iomanip>
#include "Time.h"

ostream& operator<<(ostream& fout, const Time& t) {
	cout << "(" << setw(2) << t.hour << ":" << setw(2) << t.min << ":" << setw(2) << t.sec << ")";
	return fout;
}
Time::Time(int h, int m, int s)
	: hour(h), min(m), sec(s) {
	// cout << "Constructor for Time << endl";
}
int Time::elasedSec() const {
	return 3600 * hour + 60 * min + sec;
}
bool Time::operator<(const Time& t) const {
	if (this->elasedSec() < t.elasedSec())
		return true;
	else
		return false;
}
bool Time::operator<=(const Time& t) const {
	if (this->elasedSec() <= t.elasedSec())
		return true;
	else
		return false;
}
bool Time::operator>(const Time& t) const {
	if (this->elasedSec() > t.elasedSec())
		return true;
	else
		return false;
}
bool Time::operator>=(const Time& t) const {
	if (this->elasedSec() >= t.elasedSec())
		return true;
	else
		return false;
}
bool Time::operator==(const Time& t) const {
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