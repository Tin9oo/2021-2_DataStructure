#ifndef ICD_H
#define ICD_H
#include <iostream>
using namespace std;

class InterCityDist
{
public:
	InterCityDist() {};
	InterCityDist(string c1, string c2, int dist) :city1_name(c1), city2_name(c2), dist(dist) { };
	string getC1() const { return city1_name; }
	string getC2() const { return city2_name; }
	int getdist() const { return dist; }
	bool operator<(const InterCityDist other) const {
		if (city1_name < other.city1_name)
			return true;
		else if ((city1_name == other.city1_name) && (city2_name < other.city2_name))
			return true;
		else
			return false;
	}
private:
	string city1_name;
	string city2_name;
	int dist;
};
#endif // !CP_H
