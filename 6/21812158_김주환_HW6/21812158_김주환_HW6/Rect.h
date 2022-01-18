/* Rect.h */
#ifndef R_H
#define R_H
#include "Shape.h"

class Rect : public Shape { // 파생 클래스
	friend ostream& operator<<(ostream &, Rect &);
public:
	// 생성자
	Rect();
	Rect(string name);
	Rect(Position pos, int w, int l, double ang, COLORREF color, string name);

	~Rect(); // 소멸자
	double getArea(); // 표면적 반환

	// 가상함수 구현
	virtual void draw(ostream&);

	void fprint(ostream&); // 출력
	int getWidth() { return width; } // 가로 반환
	int getLength() { return length; } // 세로 반환
	Rect& operator=(Rect& rec); // 대입연산자
protected:
	int width;
	int length;
};
#endif // !R_H

