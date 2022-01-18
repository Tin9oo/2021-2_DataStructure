/* Shape.cpp */
#include <iomanip>
#include "Shape.h"
#include "Color.h"

ostream& operator<<(ostream& fout, Shape& s) {
	fout.setf(ios::fixed);
	fout << "       " << s.name;
	fout << " : pos (" << setw(3) << s.pos_x << ", " << setw(3) << s.pos_y;
	fout << "), angle (" << showpoint << setprecision(2) << s.angle;
	fout << "), color (" << setw(6) << setfill('0') << uppercase << hex << s.color << ")";
	fout << setfill(' ');
	
	return fout;
}
Shape::Shape()
	: pos_x(), pos_y(), angle(), name(), color()
{ // default constructor
	pos_x = 0;
	pos_y = 0;
	angle = 0.0;
	name = "";
	color = RGB_BLACK;
}
Shape::Shape(string name)
	: name(name)
{
	pos_x = 0;
	pos_y = 0;
	angle = 0.0;
	color = RGB_BLACK;
}
Shape::Shape(int px, int py, double angle, COLORREF color, string name)
	:pos_x(px), pos_y(py), angle(angle), color(color), name(name)
{ // constructor
	pos_x = px;
	pos_y = py;
	this->angle = angle;
	this->color = color;
	this->name = name;
}
Shape::~Shape() {
	//cout << "Shape::Destructor (" << name << ")." << endl;
}
void Shape::draw() {
	/* virtual function that will be late-binded to sub-class's draw() */

}
void Shape::print(ostream& fout) {
	fout.setf(ios::fixed);
	fout << "       " << name;
	fout << " : pos (" << setw(3) << pos_x << ", " << setw(3) << pos_y;
	fout << "), angle (" << showpoint << setprecision(2) << angle;
	fout << "), color (" << setw(6) << setfill('0') << uppercase << hex << color << ")";
	fout << setfill(' ');
}
Shape& Shape::operator=(const Shape& s) {
	pos_x = s.pos_x;
	pos_y = s.pos_y;
	angle = s.angle;
	name = s.name;
	color = s.color;

	return *this;
}