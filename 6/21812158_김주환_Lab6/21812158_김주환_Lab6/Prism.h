/* Prism.h */
#ifndef PSM_H
#define PSM_H
#include <string>
#include "Shape.h"
using namespace std;

class Prism : public Shape { // 파생 클래스
	friend ostream& operator<<(ostream&, const Prism&); // 출력
public:
	// 생성자
	Prism();
	Prism(string name);
	Prism(int px, int py, int b, int th, double ang, int ht, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	
	//Cylinder(Cylinder &cyl);
	~Prism(); // 소멸자
	double getArea(); // 표면적 반환

	// 가상함수 구현
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // 출력
	int getBase() const { return base; } // 밑변 반환
	int getTriHeight() { return tri_height; } // 밑면 높이 반환
	Prism& operator=(const Prism& right); // 대입연산자
protected:
	int base;
	int tri_height;
	int height;
};
#endif // !PSM_H
