/* ElpsCylinder.h */
#ifndef EC
#define ED
#include <string>
#include "Elps.h"
#include "Color.h"
using namespace std;
class ElpsCylinder : public Elps // 타원 기둥
{
	friend ostream& operator<<(ostream&, const ElpsCylinder&);
public:
	ElpsCylinder(); // default constructor
	ElpsCylinder(string n); // 생성자
	ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n); // 생성자
	virtual ~ElpsCylinder(); // 소멸자
	double getArea() const; // 타원기둥 표면적
	double getVolume() const; // 타원기둥 체적
	void draw();
	void print(ostream&);
	ElpsCylinder& operator=(const ElpsCylinder& right); // 대입연산자
protected:
	double height; // Cylinder height
};
#endif // !EC
