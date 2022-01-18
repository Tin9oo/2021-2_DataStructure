/* main.cpp */
/* Description
* 다양한 도형에 대한 그림 그리기
* Programmed by J. H. Kim
* Last updated : 2021-10-08*/
#include <iostream>
#include <string>
#include <fstream>
#include "Triangle.h"
#include "Circle.h"
#include "Rectang.h"
#include "Polygon.h"
#include "Star.h"
#include "AngledArc.h"
#include "Cylinder.h"
#include "Prism.h"
#include "Hexahedron.h"
using namespace std;

int main() {
	// 여러가지 도형
	Circle cir(100, 200, 80, 0, RGB_BLACK, RGB_RED, 3, "Circle");
	Triangle tri(300, 200, 150, 130, 0, RGB_BLACK, RGB_YELLOW, 3, "Triangle");
	Rectang rec(500, 200, 150, 150, 0, RGB_BLACK, RGB_BLUE, 4, "Rectangle");
	PolyGon poly_5(700, 200, 80, 5, 0, RGB_BLACK, RGB_GREEN, 4, "Polygon_5");
	PolyGon poly_7(100, 400, 80, 7, 0, RGB_BLACK, RGB_MAGENTA, 4, "Polygon_7");
	Star star_5(300, 400, 80, 5, 0, RGB_BLACK, RGB_GREEN, 4, "Star_5");
	AngledArc angle_arc(500, 400, 80, 0, 45, 270, RGB_RED, RGB_BLUE, 4, "Angle_Arc");
	Cylinder cyl(700, 400, 80, 0, 100, RGB_BLUE, RGB_WHITE, 4, "Cylinder");
	Prism psm(100, 600, 150, 130, 30 * PI / 180, 100, RGB_BLACK, RGB_RED, 3, "Prism");
	Hexahedron hxhd(300, 600, 150, 150, 70 * PI / 180, 100, RGB_BLACK, RGB_YELLOW, 4, "Hexahedron");

	ConsolePixelFrame frame(50, 50); // 시작 지점 설정

	// 도형 추가
	frame.addShape(&cir);
	frame.addShape(&tri);
	frame.addShape(&rec);
	frame.addShape(&poly_5);
	frame.addShape(&poly_7);
	frame.addShape(&star_5);
	frame.addShape(&angle_arc);
	frame.addShape(&cyl);
	frame.addShape(&psm);
	frame.addShape(&hxhd);

	// 추가된 도형 그리기
	frame.drawShapes();

	printf("hit any key to continue ....");
	_getch();

	return 0;
} // end of main()