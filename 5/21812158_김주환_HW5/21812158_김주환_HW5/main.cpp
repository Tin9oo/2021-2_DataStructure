/* main.cpp */
/* Description
* 타원기둥에 대한 클래스
* Programmed by J. H. Kim
* Last updated : 2021-10-06 */
#include <iostream>
#include <fstream>
#include <string>
#include "Color.h"
#include "Shape.h"
#include "Elps.h"
#include "ElpsCylinder.h"
using namespace std;
int main()
{
	fstream fout;
	
	// 클래스 생성 및 초기화
	Shape shape(1, 1, 0, RGB_BLACK, "Shape");
	Elps red_elps(8, 8, 3.0, 4.0, 0, RGB_RED, "Red_Elps");
	ElpsCylinder blue_elpcyl(9, 9, 5.0, 6.0, 7.0, 0.0, RGB_BLUE, "Blue_Elp_Cyl");

	fout.open("output.txt", 'w'); // 파일 열기
	if (fout.fail())
	{
		cout << "Failed in opening output.txt file !!" << endl;
		exit;
	}
	
	// 출력
	fout << "List of shapes using operator<<() friend function " << endl;
	fout << shape << endl;
	fout << red_elps << endl;
	fout << blue_elpcyl << endl;

	fout.close(); // 파일 닫기

	return 0;
} // end of main()