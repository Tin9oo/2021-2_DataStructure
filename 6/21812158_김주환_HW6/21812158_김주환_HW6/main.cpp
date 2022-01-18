/* main.cpp */
/* Description
* 도형에 대한 클래스 상속
* 가상함수
* Programmed by J. H. Kim
* Last updated : 2021-10-13 */

#include <fstream>
#include "Position.h"
#include "Shape.h"
#include "Triangle.h"
#include "Prism.h"
#include "Rect.h"
#include "Hexahedron.h"
#include "Circle.h"
#include "Cylinder.h"
using namespace std;

#define NUM_SHAPES 7

int main() {
	ofstream fout;

	// 객체 생성 및 초기화
	Shape s1(Position(1, 1), 0, RGB_BLUE, "Blue Shape");
	Triangle t1(Position(2, 2), 3, 4, 0, RGB_RED, "Red Triangle");
	Prism p1(Position(3, 3), 6, 7, 8, 0, RGB_GREEN, "Green Prism");
	Rect r1(Position(4, 4), 1, 2, 0, RGB_YELLOW, "Yellow Rectangle");
	Hexahedron hx1(Position(5, 5), 5, 6, 7, 0, RGB_ORANGE, "Orange Hexahedtron");
	Circle cir(Position(6, 6), 6, 0, RGB_MAGENTA, "Magenta Circle");
	Cylinder cyl(Position(7, 7), 8, 6, 0, RGB_WHITE, "White Cylinder");
	
	// 체계에 사용할 기반클래스 포인터 배열 생성
	Shape * shapes[NUM_SHAPES];
	
	fout.open("Output.txt");
	if (fout.fail())
	{
		cout << "Fail to open an output file (Output.txt)" << endl;
		exit(1);
	}

	// 생성한 객체 포인터를 저장
	shapes[0] = &s1;
	shapes[1] = &t1;
	shapes[2] = &p1;
	shapes[3] = &r1;
	shapes[4] = &hx1;
	shapes[5] = &cir;
	shapes[6] = &cyl;

	// 출력을 위한 체계
	for (int i = 0; i < NUM_SHAPES; i++)
		shapes[i]->draw(fout);

	fout.close();

	return 0;
} // end of main()