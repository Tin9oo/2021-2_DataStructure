/* ElpsCylinder.cpp */
#include "ElpsCylinder.h"
using namespace std;

ostream& operator<<(ostream& ostr, const ElpsCylinder& elpcyl) {
	ostr << elpcyl.name;
	ostr << " : pos (" << setw(3) << elpcyl.pos_x << ", " << setw(3) << elpcyl.pos_y;
	ostr << "), angle (" << elpcyl.angle;
	ostr << "), color (" << setw(6) << setfill('0') << uppercase << hex << elpcyl.color;
	ostr << "), radius (" << elpcyl.radius_1 << ", " << elpcyl.radius_2;
	ostr << "), height (" << elpcyl.height<< ")," << endl;
	ostr << "               ellipse area (" << elpcyl.Elps::getArea();
	ostr << "), elp_cyl area (" << elpcyl.getArea();
	ostr << "), elp_cyl volume (" << elpcyl.getVolume() << ")";
	ostr << setfill(' ');

	return ostr;
}
ElpsCylinder::ElpsCylinder()
	: Elps()
{
	height = 0;
}
ElpsCylinder::ElpsCylinder(string n)
	: Elps(n)
{
	height = 0;
}
ElpsCylinder::ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n)
	: Elps(px, py, r1, r2, ang, clr, n)
{
	height = h;
}
ElpsCylinder::~ElpsCylinder() {
	//cout << "ElpsCylinder::Destructor (" << name << ")." << endl;
}
double ElpsCylinder::getArea() const {
	double c = 2.0 * 3.141592 * (radius_1 + radius_2) / 2.0;
	return  c * height + 2.0 * Elps::getArea();
}
double ElpsCylinder::getVolume() const {
	return height * radius_1 * radius_2 * 3.141592;
}
void ElpsCylinder::draw() {
	/* virtual function that will be late-binded to sub-class's draw() */
}
void ElpsCylinder::print(ostream&) {
	cout << name;
	cout << "pos (" << setw(3) << pos_x << ", " << setw(3) << pos_y;
	cout << "), angle (" << angle;
	cout << "), color (" << setw(6) << setfill('0') << uppercase << hex << color;
	cout << "), radius (" << radius_1 << ", " << radius_2;
	cout << "), height (" << height << ")," << endl;
	cout << "               ellipse area (" << Elps::getArea();
	cout << "), elp_cyl area (" << getArea();
	cout << "), elp_cyl volume (" << getVolume() << ")";
	cout << setfill(' ');
}
ElpsCylinder& ElpsCylinder::operator=(const ElpsCylinder& right) {
	Elps::operator=(right);
	height = right.height;

	return *this;
}