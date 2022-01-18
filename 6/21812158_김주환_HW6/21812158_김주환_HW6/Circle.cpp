/* Circle.cpp */
#include "Circle.h"

ostream& operator<<(ostream& fout, Circle& c) {
	c.fprint(fout);

	return fout;
}
Circle::Circle()
	: Shape(), radius(0) {
	
}
Circle::Circle(string name)
	: Shape(name), radius(0) {
	
}
Circle::Circle(Position pos,  int r, double ang, COLORREF color, string name)
	: Shape(pos, ang, color, name), radius(r) {
	
}
//Circle(Circle &tr);
Circle::~Circle() {
	//cout << "Circle::Destructor (" << name << ").₩n";
}
double Circle::getArea() {
	return PI * radius * radius;
}
void Circle::draw(ostream& fout) {
	fout << "Circle::draw()      =>     ";
	fprint(fout);
}
void Circle::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << "radius(" << radius << "), ";
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	fout << hex << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << "), " << dec;
	fout << endl << "                           ";
	fout << "circle area(" << getArea() << ")]" << dec;
	fout << endl << endl;
}
Circle& Circle::operator=(const Circle& right) {
	Shape::operator=(right);
	radius = right.radius;

	return *this;
}