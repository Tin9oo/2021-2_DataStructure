/* main.cpp - T_Array<Student, K> */
/* Description
* Programmed by J. H. Kim
* Last updated : 2021-10-15 */
#include <iostream>
#include <fstream>
#include <string>
#include "Time.h"
using namespace std;

void main()
{
	Time times[10] =
	{
	Time(3, 0, 30), Time(7, 30, 0), Time(2, 0, 50), Time(5, 30, 0), Time(1, 10, 0),
	Time(9, 20, 10), Time(1, 20, 15), Time(10, 0, 0), Time(11, 15, 10), Time(2, 0, 5)
	};
	cout << "Before sorting times :" << endl;
	print_times(times, 10, 5);
	sort_times(times, 10);
	cout << "After sorting times :" << endl;
	print_times(times, 10, 5);
}