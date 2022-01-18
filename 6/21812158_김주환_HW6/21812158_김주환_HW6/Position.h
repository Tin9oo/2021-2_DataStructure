/* Position.h */
#ifndef P_H
#define P_H
#include <iostream>
using namespace std;
typedef struct Position{
	int x;
	int y;
	Position(int px, int py) {
		x = px;
		y = py;
	};
} Position;
#endif // !P_H
