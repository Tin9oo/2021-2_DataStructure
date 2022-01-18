/* InterCityDist_Map.cpp */
/* main.cpp */
/* Description
* 맵 구현 및 기능검사
* Programmed by J. H. Kim
* Last updated : 2021-12-15 */
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include "City.h"
#include "InterCityDist.h"
using namespace std;

#define Num_City_Pair 10
InterCityDist icdArray[Num_City_Pair] =
{ {"Seoul", "Daegu", 300}, {"Seoul", "Daejeon", 150}, {"Seoul", "Gwangju", 310}, {"Seoul", "Busan", 450},
{"Daejeon", "Gwangju", 160}, {"Daejeon", "Daegu", 150}, {"Daejeon", "Busan", 280},
{"Daegu", "Busan", 130}, {"Daegu", "Gwangju", 180}, {"Gwangju", "Busan", 170} };
template <typename T>
void print_set(set<T>& s);

int main()
{
	map<CityPair, int> icdMap;
	map<CityPair, int>::iterator itr;
	CityPair cp, cp1, cp2;
	InterCityDist icd;
	set<string> city_names;
	set<string>::iterator sItr, sItr1, sItr2;
	string city_name1, city_name2;
	int dist;
	for (int i = 0; i < Num_City_Pair; i++)
	{
		cp = { icdArray[i].getC1(), icdArray[i].getC2() };
		icdMap.insert({ cp, icdArray[i].getdist() }); // icdArray[]에 있는 항목을 icdMap에 추가
		city_names.insert(icdArray[i].getC1());// 도시 이름은 city_names에 추가할 것
		cp = { icdArray[i].getC2(), icdArray[i].getC1() };
		icdMap.insert({ cp, icdArray[i].getdist() });
		city_names.insert(icdArray[i].getC2());// 도시 이름은 city_names에 추가할 것
	}
	cout << "City names = ";
	print_set<string>(city_names);
	/* print icdMap */
	cout << "\nInterCityDistance Map = " << endl;
	for (itr = icdMap.begin(); itr != icdMap.end(); itr++)
	{
		cout << "(" << setw(10) << itr->first.getC1() << ", ";
		cout << setw(10) << itr->first.getC2() << ") : " << itr->second << endl;
	}

	cout << "\nInterCityDistance Table = " << endl;
	cout << setw(10) << " " << " | ";
	for (sItr = city_names.begin(); sItr != city_names.end(); sItr++)
	{
		cout << setw(10) << *sItr;
	}
	cout << endl;
	int num_cities = city_names.size();
	cout << " ----------+-";
	for (int i = 0; i < num_cities; i++)
	{
		cout << setw(10) << "----------";
	}
	cout << endl;
	/* print inter-city distance table */
	for (sItr1 = city_names.begin(); sItr1 != city_names.end(); sItr1++)
	{
		cout << setw(10) << *sItr1 << " | ";
		for (sItr2 = city_names.begin(); sItr2 != city_names.end(); sItr2++)
		{
			city_name1 = *sItr1; city_name2 = *sItr2; // 두 도시 이름을 *sItr1와 *sItr2로 추출
			cp = { city_name1, city_name2 };
			if (city_name1 != city_name2)
			{
				dist = icdMap.find(cp).operator*().second; // 추출된 두 도시 이름을 사용하여 icdMap에 있는 두 도시간 거리를 추출하여 출력
				cout << setw(10)<< dist;
			}
			else cout << setw(10) << '0'; // 만약 두 도시의 이름이 동일 할 경우, 0을 출력
		}
		cout << endl;
	}
	return 0;
}
template <typename T>
void print_set(set<T>& s)
{
	typename set<T>::iterator itr;
	int count = 0;
	cout << "[";
	for (itr = s.begin(); itr != s.end(); itr++)
	{
		cout << setw(10) << *itr << ", ";
		count++;
		if (count % 10 == 0)
			cout << endl;
	}
	cout << "]" << endl;
}