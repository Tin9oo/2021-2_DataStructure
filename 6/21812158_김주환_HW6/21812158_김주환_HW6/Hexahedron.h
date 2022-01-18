/* Hexahedron.h */
#ifndef HXHD_H
#define HXHD_H
#include "Rect.h"

class Hexahedron : public Rect { // 파생 클래스
	friend ostream& operator<<(ostream&, const Hexahedron&); // 출력
public:
	// 생성자
	Hexahedron();
	Hexahedron(string name);
	Hexahedron(Position pos, int w, int l, int ht, double ang, COLORREF color, string name);

	//Cylinder(Cylinder &cyl);
	~Hexahedron(); // 소멸자
	double getArea(); // 표면적

	// 가상함수 구현
	virtual void draw(ostream& fout);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // 출력
	int getWidth() const { return width; } // 가로 반환
	int getLength() { return length; } // 세로 반환
	Hexahedron& operator=(const Hexahedron& right); // 대입연산자
protected:
	int height;
};
#endif // !HXHD_H