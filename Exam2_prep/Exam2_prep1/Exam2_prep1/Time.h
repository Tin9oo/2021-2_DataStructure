/* Time.h */
#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time
{
	friend ostream& operator<<(ostream&, const Time&);
public:
	Time(); // default constructor
	Time(int h, int m, int s);
	int elasedSec() const;
	Time getTime();
	bool operator<(const Time&) const;
	bool operator<=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator>=(const Time&) const;
	bool operator==(const Time&) const;
private:
	bool isValidTime(int, int, int);
	int hour;
	int min;
	int sec;
};
void sort_times(Time* times, int size);
void print_times(Time * times, int size, int per_line);
#endif