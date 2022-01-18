/* main.cpp */
/* Description
* Time & Date 클래스
* 템플릿 함수 정의
* Programmed by J. H. Kim
* Last updated : 2021-10-21 */
#include <iostream>
#include <conio.h> // for _getch()
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Time.h"
#include "Date.h"
#include "StlContainerHandler.h"
using namespace std;

#define NUM_TIMES 10
#define NUM_DATES 10
#define NUM_STUDENTS 10

void main()
{
	Time times[NUM_TIMES] =
	{
	Time(3, 0, 30), Time(7, 30, 0), Time(2, 0, 50), Time(5, 30, 0), Time(1, 10, 0),
	Time(9, 20, 10), Time(1, 20, 15), Time(10, 0, 0), Time(11, 15, 10), Time(2, 0, 5)
	};
	vector<Time> v_times(times, times + NUM_TIMES);
	printVector(v_times, "STL vector of times - before sorting", NUM_TIMES);
	sort(v_times.begin(), v_times.end());
	printVector(v_times, "STL vector of times - after sorting", NUM_TIMES);
	Date dates[10] =
	{
	Date(2003, 4, 5), Date(2002, 7, 15), Date(2001, 5, 1), Date(2001, 3, 10), Date(2000, 5, 21),
	Date(2000, 3, 1), Date(1999, 12, 25), Date(1998, 10, 9), Date(1997, 6, 10), Date(1996, 1, 1)
	};
	vector<Date> v_dates(dates, dates + NUM_DATES);
	printVector(v_dates, "STL vector of dates - before sorting", NUM_DATES);
	sort(v_dates.begin(), v_dates.end());
	printVector(v_dates, "STL vector of dates - after sorting", NUM_DATES);
}