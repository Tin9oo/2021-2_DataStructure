/* Prism.h */
#ifndef PSM_H
#define PSM_H
#include "Triangle.h"

class Prism : public Triangle { // 파생 클래스
	friend ostream& operator<<(ostream&, const Prism&); // 출력
public:
	// 생성자
	Prism();
	Prism(string name);
	Prism(Position pos, int b, int th, int ht, double ang, COLORREF color, string name);

	//Cylinder(Cylinder &cyl);
	~Prism(); // 소멸자
	double getArea(); // 표면적 반환

	// 가상함수 구현
	virtual void draw(ostream& fout);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // 출력
	int getBase() const { return base; } // 밑변 반환
	int getTriHeight() { return tri_height; } // 밑면 높이 반환
	Prism& operator=(const Prism& right); // 대입연산자
protected:
	int height;
};
#endif // !PSM_H
