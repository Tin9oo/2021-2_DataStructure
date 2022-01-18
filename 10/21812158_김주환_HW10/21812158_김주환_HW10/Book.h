/* Book.h */
#ifndef B_H
#define B_H
#include <iostream>
#include <iomanip>
#include"Date.h"
using namespace std;

class Book
{
	friend ostream& operator<<(ostream& fout, Book& bk)
	{
		fout << "[";
		fout.setf(ios::left);
		fout << setw(8) << bk.title;
		fout << ", " << setw(8) << bk.author;
		fout << ", " << bk.pubDate;
		fout << "]" ;
			return fout;
	}
public:
	Book(string bk_title, string bk_author, Date dt) :
		title(bk_title), author(bk_author), pubDate(dt) {}
	string& getTitle() { return title; }
	string getAuthor() { return author; }
	Date getPubDate() { return pubDate; }
	void setTitle(string bk_title) { title = bk_title; }
	void setAuthor(string bk_author) { author = bk_author; }
private:
	string title;
	string author;
	Date pubDate;
};
#endif // !B_H