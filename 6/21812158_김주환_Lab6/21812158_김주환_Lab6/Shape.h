/* Shape.h */
#ifndef S_H
#define S_H
#include <string>
#include <Windows.h>
#include <conio.h>
#include "ConsolePixelDrawing.h"
#include "Color.h"
using namespace std;

#define PI 3.141592

class ConsolePixelFrame;
class Shape { // 기반 클래스
	friend ostream& operator<<(ostream&, Shape&); // 출력
public:
	// 생성자
	Shape(); // default constructor
	Shape(string name);
	Shape(int px, int py, double ang, COLORREF ln_clr, COLORREF br_clr,
		int pen_thick, string name);
	
	// 가상함수
	virtual ~Shape();
	virtual void draw(ConsolePixelFrame cp_frame);

	void fprint(ostream&); // 출력
	int get_pos_x() const { return pos_x; } // x 좌표 반환
	int get_pos_y() const { return pos_y; } // y 좌표 반환
	void set_pos_x(int x) { pos_x = x; } // x 좌표 설정
	void set_pos_y(int y) { pos_y = y; } // y 좌표 설정
	string getName() { return name; } // 이름 반환
	void setName(string n) { name = n; } // 이름 설정
	Shape& operator=(const Shape& s); // 대입연산자
protected:
	int pos_x; // position x
	int pos_y; // position y
	double angle;
	string name;
	int pen_thickness;
	COLORREF line_color;
	COLORREF brush_color;
};
#endif