/* Exceptions.h */
#ifndef EXCP_H
#define EXCP_H
#include <string>
class NonexistentElement
{
public:
	NonexistentElement()
		: err_mail(NULL) { }
	NonexistentElement(string em)
		: err_mail(em) { }
private:
	string err_mail;
};
#endif // !EXCP_H