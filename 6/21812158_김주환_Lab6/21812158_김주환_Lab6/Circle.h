/* Circle.h */
#ifndef Circle_H
#define Circle_H
#include <string>
#include "Shape.h"
using namespace std;

#define PI 3.141592

class Circle : public Shape { // 파생 클래스
	friend ostream& operator<<(ostream&, Circle&); // 출력
public:
	// 생성자
	Circle();
	Circle(string name);
	Circle(int px, int py, int r, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick,
		string name);

	//Circle(Circle &tr);
	~Circle(); // 소멸자
	double getArea(); // 면적 반환

	// 파생 클래스에 맞는 가상 함수 구현
	virtual void draw(ConsolePixelFrame cp_frame);
	
	void fprint(ostream&); // 출력
	int getRadius() const { return radius; } // Radius 반환
	void setRadius(int r) { radius = r; } // Radius 설정
	Circle& operator=(const Circle& right); // 대입연산자
protected:
	int radius;
};
#endif