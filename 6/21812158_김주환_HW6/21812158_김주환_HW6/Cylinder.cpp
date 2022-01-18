/* Cylinder.cpp */
#include <math.h>
#include "Cylinder.h"
using namespace std;

ostream& operator<<(ostream& fout, const Cylinder& cyl) {
	

	return fout;
}
Cylinder::Cylinder() // default constructor
	: Circle("no_name"), height(0) {
	//cout << "Cylinder::Default AngleArc constructor (" << name << ").₩n";
}
Cylinder::Cylinder(string name)
	: Circle(name), height(0) {
	//cout << "AngleArc::Consb tructor (" << name << ").₩n";
}
Cylinder::Cylinder(Position pos, int r, int ht, int ang, COLORREF color, string name)
	: Circle(pos, r, ang, color, name), height(ht) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
}
Cylinder::~Cylinder() {
	//cout << "Cylinder::Destructor (" << name << ").₩n";
}
double Cylinder::getArea() {
	return 2 * PI * radius * radius + 2 * PI * radius * height;
}
void Cylinder::draw() {
	cout << "draw() of Cylinder";
	fprint(cout);
}
void Cylinder::draw(ostream& fout) {
	fout << "Cylinder::draw()    =>     ";
	fprint(fout);
}
void Cylinder::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << "radius(" << radius << "), height(" << height << "), ";
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	fout << hex << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << "), " << dec;
	fout << endl << "                           ";
	fout << "cylinder surface area(" << getArea() << "), ";
	fout << "cylinder volume(" << PI * radius * radius * height << ")]";
	fout << endl << endl;
}
Cylinder& Cylinder::operator=(const Cylinder& right) {
	Shape::operator=(right);
	radius = right.radius;
	height = right.height;

	return *this;
}