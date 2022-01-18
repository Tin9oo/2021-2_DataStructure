/* Shape.h */
#ifndef S_H
#define S_H
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Position.h"
using namespace std;

#define PI 3.141592

const COLORREF RGB_RED = 0x000000FF;
const COLORREF RGB_GREEN = 0x0000FF00;
const COLORREF RGB_BLUE = 0x00FF0000;
const COLORREF RGB_BLACK = 0x00000000;
const COLORREF RGB_ORANGE = 0x0000A5FF;
const COLORREF RGB_YELLOW = 0x0000FFFF;
const COLORREF RGB_MAGENTA = 0x00FF00FF;
const COLORREF RGB_CYAN = 0x0000FFFF;
const COLORREF RGB_WHITE = 0x00FFFFFF;

class Shape { // 기반 클래스
	friend ostream& operator<<(ostream&, Shape&); // 출력
public:
	// 생성자
	Shape(); // default constructor
	Shape(string name);
	Shape(Position pos, double ang, COLORREF color, string name);

	// 가상함수
	virtual ~Shape();
	virtual void draw(ostream&);

	void fprint(ostream&); // 출력
	int get_pos_x() const { return pos.x; } // x 좌표 반환
	int get_pos_y() const { return pos.y; } // y 좌표 반환
	void set_pos_x(int x) { pos.x = x; } // x 좌표 설정
	void set_pos_y(int y) { pos.y = y; } // y 좌표 설정
	string getName() { return name; } // 이름 반환
	void setName(string n) { name = n; } // 이름 설정
	Shape& operator=(const Shape& s); // 대입연산자
	// ostream& fprintRGB(ostream&, COLORREF);
protected:
	Position pos;
	double angle;
	string name;
	COLORREF color;
};
#endif