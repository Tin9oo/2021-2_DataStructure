/* ConsolePixelDrawing */
#ifndef PIXEL_DRAWING_H
#define PIXEL_DRAWING_H
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Shape.h"
#include "Color.h"
using namespace std;

/* PEN_Styles */
#define PS_SOLID 0
#define PS_DASH 1 // -------
#define PS_DOT 2 // .......
#define PS_DASHDOT 3 // _._._._
#define PS_DASHDOTDOT 4 // _.._.._
#define PS_NULL 5
#define PS_INSIDEFRAME 6
#define PS_USERSTYLE 7
#define PS_ALTERNATE 8
#define MAX_NUM_SHAPES 100

class Shape;
class ConsolePixelFrame {
public:
	ConsolePixelFrame(int org_x, int org_y); // 생성자
	~ConsolePixelFrame(); // 소멸자

	// 기반 클래스의 포인터 배열에 파생 클래스의 포인터를 추가
	void addShape(Shape* new_shape);
	
	// 저장된 포인터의 클래스에 맞는 가상함수를 실행
	void drawShapes();

	int get_pos_org_x() { return pos_org_x; }
	int get_pos_org_y() { return pos_org_y; }
	HDC getConsole_DC() { return console_DC; }
private:
	HWND console;
	HDC console_DC; // device context
	Shape** pShapes; // Array of Shape Pointers
	int num_shapes;
	int capacity;
	int pos_org_x;
	int pos_org_y;
	bool isValidIndex(int index);
};
#endif // !PIXEL_DRAWING_H 
