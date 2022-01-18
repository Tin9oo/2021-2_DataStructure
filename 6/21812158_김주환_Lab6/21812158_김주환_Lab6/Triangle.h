/* Triangle.h */
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include "Shape.h"
using namespace std;

class Triangle : public Shape { // 파생 클래스
	//friend ostream& operator<<(ostream &, Triangle &);
public:
	// 생성자
	Triangle();
	Triangle(string name);
	Triangle(int px, int py, int b, int h, double ang, COLORREF ln_clr, COLORREF br_clr,
		int pen_thick, string name);

	~Triangle(); // 소멸자
	double getArea(); // 표면적 반환

	// 가상함수 구현
	virtual void draw(ConsolePixelFrame cp_frame);

	void fprint(ostream&); // 출력
	int getBase() { return base; } // 밑변 반환
	int getHeight() { return tri_height; } // 높이 반환
	Triangle& operator=(const Triangle& tri); // 대입연산자
protected:
	int base;
	int tri_height;
};
#endif