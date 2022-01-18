/* Cylinder.h */
#ifndef CYLINDER_H
#define CYLINDER_H
#include <string>
#include "Shape.h"
using namespace std;

class Cylinder : public Shape { // 파생 클래스
	friend ostream& operator<<(ostream&, const Cylinder&); // 출력
public:
	// 생성자
	Cylinder();
	Cylinder(string name);
	Cylinder(int px, int py, int r, int ang, int height,
		COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	
	//Cylinder(Cylinder &cyl);
	~Cylinder(); // 소멸자
	double getArea(); // 넓이

	// 가상함수 구현
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // 출력
	int getRadius() const { return radius; } // 반지름 반환
	void setRadius(int r) { radius = r; } // 반지름 설정
	Cylinder& operator=(const Cylinder& right); // 대입연산자
protected:
	int radius;
	int height;
};
#endif