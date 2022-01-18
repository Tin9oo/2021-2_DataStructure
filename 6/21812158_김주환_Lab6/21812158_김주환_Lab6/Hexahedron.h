/* Hexahedron.h */
#ifndef HXHD_H
#define HXHD_H
#include <string>
#include "Shape.h"
using namespace std;

class Hexahedron : public Shape { // 파생 클래스
	friend ostream& operator<<(ostream&, const Hexahedron&); // 출력
public:
	// 생성자
	Hexahedron();
	Hexahedron(string name);
	Hexahedron(int px, int py, int w, int l, double ang, int ht, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	
	//Cylinder(Cylinder &cyl);
	~Hexahedron(); // 소멸자
	double getArea(); // 표면적

	// 가상함수 구현
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // 출력
	int getWidth() const { return width; } // 가로 반환
	int getLength() { return length; } // 세로 반환
	Hexahedron& operator=(const Hexahedron& right); // 대입연산자
protected:
	int width;
	int length;
	int height;
};
#endif // !HXHD_H