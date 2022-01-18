/* BigArray.h */
#ifndef BIG_ARRAY_H
#define BIG_ARRAY_H
#include <iostream>
#include <fstream>
using namespace std;
typedef struct
{
	int min;
	int max;
	double avg; // average
	double medi; // median
	double var; // variance
	double std_dev; // standard deviation
} ArrayStatistics;
class BigArray
{
public:
	BigArray(int n); // constructor
	~BigArray(); // destructor
	void genBigRandArray(int base_offset);
	int size() { return num_elements; }
	void suffle();
	void selection_sort();
	void quick_sort();
	void getStatistics(ArrayStatistics&);
	void fprintStatistics(ostream& fout);
	void fprintBigArray(ostream& fout, int
		elements_per_line);
	void fprintSample(ostream& fout, int
		elements_per_line, int num_sample_lines);
private:
	int* big_array;
	int num_elements;
};
#endif