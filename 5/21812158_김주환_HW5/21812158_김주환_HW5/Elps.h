/* Elps.h */
#ifndef E
#define E
#include <string>
#include "Shape.h"
#include "Color.h"
class Elps : public Shape // Ellipse 타원
{
	friend ostream& operator<<(ostream&, const Elps&);
public:
	Elps(); // 생성자
	Elps(string name); // 생성자
	Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name); // 생성자
	~Elps(); // 생성자
	double getArea() const; // 타원 면적 계산
	void draw(); // 타원 작도에 필요한 파라메터 출력
	void print(ostream&); // 타원에 대한 출력기능
	double getRadius_1() const { return radius_1; }
	double getRadius_2() const { return radius_2; }
	void setRadius(double r1, double r2) { radius_1 = r1; radius_2 = r2; }
	Elps& operator=(const Elps& elp); // 대입연산자
protected:
	double radius_1;
	double radius_2;
};
#endif // !E
