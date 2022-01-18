#ifndef CP_H
#define CP_H
#include <iostream>
using namespace std;

class CityPair
{
public:
	CityPair() {};
	CityPair(string c1, string c2) :city1_name(c1), city2_name(c2) { };
	string getC1() const { return city1_name; }
	string getC2() const { return city2_name; }
	bool operator<(const CityPair other) const {
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
};
#endif // !CP_H
