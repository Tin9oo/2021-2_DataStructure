/* Elps.cpp */
#include "Elps.h"
using namespace std;

ostream& operator<<(ostream& fout, const Elps& e) {
	fout << "    " << e.name;
	fout << " : pos (" << setw(3) << e.pos_x << ", " << setw(3) << e.pos_y;
	fout << "), angle (" << e.angle;
	fout << "), color (" << setw(6) << setfill('0') << uppercase << hex << e.color;
	fout << "), radius (" << setprecision(2) << e.radius_1 << ", " << setprecision(2) << e.radius_2;
	fout << "), ellipse area (" << e.getArea() << ")";
	fout << setfill(' ');

	return fout;
}
Elps::Elps()
	: Shape()
{
	radius_1 = 0;
	radius_2 = 0;
}
Elps::Elps(string name)
	: Shape(name)
{
	radius_1 = 0;
	radius_2 = 0;
}
Elps::Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name)
	: Shape(px, py, ang, clr, name)
{
	radius_1 = r1;
	radius_2 = r2;
}
Elps::~Elps() {
	//cout << "Elps::Destructor (" << name << ")." << endl;
}
double Elps::getArea() const {
	return radius_1 * radius_2 * 3.141592;
}
void Elps::draw() {
	/* virtual function that will be late-binded to sub-class's draw() */
}
void Elps::print(ostream&) {
	cout << "    " << name;
	cout << "pos (" << setw(3) << pos_x << ", " << setw(3) << pos_y;
	cout << "), angle (" << angle;
	cout << "), color (" << setw(6) << setfill('0') << uppercase << hex << color;
	cout << "), radius (" << setprecision(2) << radius_1 << ", " << setprecision(2) << radius_2;
	cout << "), ellipse area (" << getArea() << ")";
	cout << setfill(' ');
}
Elps& Elps::operator=(const Elps& elp) {
	Shape::operator=(elp);
	radius_1 = elp.radius_1;
	radius_2 = elp.radius_2;

	return *this;
}