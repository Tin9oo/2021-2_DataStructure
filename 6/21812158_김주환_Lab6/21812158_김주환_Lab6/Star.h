/* Star.h */
#ifndef Star_H
#define Star_H
#include <string>
#include "Shape.h"
using namespace std;

class Star : public Shape { // 파생 클래스
	//friend ostream& operator<<(ostream &, PolyGonle &);
public:
	// 생성자
	Star();
	Star(string name);
	Star(int px, int py, int radius, int num_vertices, double ang, COLORREF ln_clr,
		COLORREF br_clr, int pen_thick, string name);

	//PolyGonle(PolyGonle &pg);
	~Star(); // 소멸자
	//double getArea();

	// 가상함수 구현
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // 출력
	int getRadius() { return radius; } // 반지름 반환
	int getNumPoly() { return num_vertices; } // 꼭짓점 반환
	Star& operator=(Star& pg); // 대입연산자
protected:
	int radius;
	int num_vertices;
};
#endif