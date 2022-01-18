/* Prism.cpp */
#include <math.h>
#include "Prism.h"

ostream& operator<<(ostream& fout, Prism& p) {
	p.fprint(fout);

	return fout;
}
Prism::Prism() // default constructor
	: Triangle("no_name"), height(0) {
	//cout << "Cylinder::Default AngleArc constructor (" << name << ").₩n";
}
Prism::Prism(string name)
	: Triangle(name), height(0) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
}
Prism::Prism(Position pos, int b, int th, int ht, double ang, COLORREF color, string name)
	: Triangle(pos, b, th, ang, color, name), height(ht) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
}
Prism::~Prism() {
	//cout << "Cylinder::Destructor (" << name << ").₩n";
}
double Prism::getArea() {
	return base * tri_height + base * height +
		2 * sqrt(base * base / 4.0 + tri_height * tri_height) * height;
}
void Prism::draw() {
	cout << "draw() of Cylinder";
	fprint(cout);
}
void Prism::draw(ostream& fout) {
	fout << "Prism::draw()       =>     ";
	fprint(fout);
}
Prism& Prism::operator=(const Prism& right) {
	Shape::operator=(right);
	base = right.base;
	tri_height = right.tri_height;
	height = right.height;

	return *this;
}
void Prism::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << "base(" << base << "), tri_height(" << tri_height << "), ";
	fout << "height(" << height << "), ";
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	fout << hex << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << "), " << dec;
	fout << endl << "                           ";
	fout << "prism surface area(" << getArea() << "), ";
	fout << "prism volume(" << base * tri_height * height / 2.0 << ")]";
	fout << endl << endl;
}