/* Rectang.h */
#ifndef Rectang_H
#define Rectang_H
#include <string>
#include "Shape.h"
using namespace std;

class Rectang : public Shape { // 파생 클래스
	//friend ostream& operator<<(ostream &, Rectangle &);
public:
	// 생성자
	Rectang();
	Rectang(string name);
	Rectang(int px, int py, int w, int l, double ang,
		COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	
	~Rectang(); // 소멸자
	double getArea(); // 표면적 반환

	// 가상함수 구현
	virtual void draw(ConsolePixelFrame cp_frame);

	void fprint(ostream&); // 출력
	int getWidth() { return width; } // 가로 반환
	int getLength() { return length; } // 세로 반환
	Rectang& operator=(Rectang& rec); // 대입연산자
protected:
	int width;
	int length;
};
#endif