/* Polygon.h */
#ifndef PolyGon_H
#define PolyGon_H
#include <string>
#include "Shape.h"
using namespace std;

class PolyGon : public Shape { // 파생 클래스
	//friend ostream& operator<<(ostream &, PolyGonle &);
public:
	// 생성자
	PolyGon();
	PolyGon(string name);
	PolyGon(int px, int py, int radius, int num_poly, double ang, COLORREF ln_clr, COLORREF br_clr,
		int pen_thick, string name);

	~PolyGon(); // 소멸자

	// 가상함수 구현
	virtual void draw(ConsolePixelFrame cp_frame);

	void fprint(ostream&); // 출력
	int getRadius() { return radius; } // 반지름 반환
	int getNumPoly() { return num_poly; } // 꼭지점 반환
	PolyGon& operator=(PolyGon& pg); // 대입연산자
protected:
	int radius;
	int num_poly;
};
#endif