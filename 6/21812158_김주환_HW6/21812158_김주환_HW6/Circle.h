/* Circle.h */
#ifndef Circle_H
#define Circle_H
#include "Shape.h"

#define PI 3.141592

class Circle : public Shape { // 파생 클래스
	friend ostream& operator<<(ostream&, Circle&); // 출력
public:
	// 생성자
	Circle();
	Circle(string name);
	Circle(Position pos, int r, double ang, COLORREF color, string name);

	//Circle(Circle &tr);
	~Circle(); // 소멸자
	double getArea(); // 면적 반환

	// 파생 클래스에 맞는 가상 함수 구현
	virtual void draw(ostream&);

	void fprint(ostream&); // 출력
	int getRadius() const { return radius; } // Radius 반환
	void setRadius(int r) { radius = r; } // Radius 설정
	Circle& operator=(const Circle& right); // 대입연산자
protected:
	int radius;
};
#endif