/* Time.cpp */
#include <iomanip>
#include "Time.h"

ostream& operator<<(ostream& fout, const Time& t) {
	cout << "(" << setw(2) << t.hour << ":" << setw(2) << t.min << ":" << setw(2) << t.sec << ")";
	return fout;
}
Time::Time()
	: hour(0), min(0), sec(0) {
		// cout << "Constructor for Time << endl";
}
Time::Time(int h, int m, int s)
	: hour(h), min(m), sec(s) {
	// cout << "Constructor for Time << endl";
}
int Time::elasedSec() const {
	return 3600 * hour + 60 * min + sec;
}
Time Time::getTime() {
	return Time(hour, min, sec);
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
void sort_times(Time* times, int size) {
	int index_min, index_max; // index of the element with minimum value
	Time tempElement;
	int minKey, key;

	for (int i = 0; i < size - 1; i++) {
		index_min = i;
		minKey = times[i].elasedSec();
		for (int j = i + 1; j < size; j++) {
			key = times[j].elasedSec();
			if (key < minKey) {
				index_min = j;
				minKey = key;
			}
		}
		if (index_min != i) { // if a smaller element is found, then swap
			tempElement = times[index_min];
			times[index_min] = times[i];
			times[i] = tempElement;
		}
	} // end for
}
void print_times(Time* times, int size, int per_line) {
	for (int i = 0; i < size; i++) {
		cout << times[i];
		if (!((i + 1) % per_line))
			cout << endl;
	}
	cout << endl;
}