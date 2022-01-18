/** Generic Skip List.h (1) */
#ifndef GSL_H
#define GSL_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <limits>
#include <string>
#include "MyVoca.h"
#include "CyclicShiftHashCode.h"
#define PROBABILITY_OF_ABOVE_LEVEL 2
#define PLUS_INF INT_MAX
#define MINUS_INF INT_MIN
using namespace std;
template<typename Key, typename Element>
class SkipList {
protected:
	class QuadNode
	{
	private:
		Key _key;
		Element _elem;
	protected:
		QuadNode* up;
		QuadNode* down;
		QuadNode* prev;
		QuadNode* next;
		int level;
	public:
		QuadNode(Key k = Key(), Element e = Element()) // constructor
			: _key(k), _elem(e)
		{
			up = down = prev = next = NULL;
			level = -1;
		}
		Key& key() { return _key; }
		Element& element() { return _elem; }
		void setKey(Key& k) { _key = k; }
		void setElement(Element& e) { _elem = e; }
		friend class Position;
	}; // end of QuadNode
public:
	class Position
	{
	protected:
		QuadNode* pQN;
	public:
		Position(QuadNode* pSLN) { pQN = pSLN; }
		Position() {}
		Key& key() { return pQN->key(); }
		Element& element() { return pQN->element(); }
		Position below() { return Position(pQN->down); }
		Position above() { return Position(pQN->up); }
		Position after() { return Position(pQN->next); }
		Position before() { return Position(pQN->prev); }
		void setBelow(const Position& p) { pQN->down = p.pQN; }
		void setAbove(const Position& p) { pQN->up = p.pQN; }
		void setAfter(const Position& p) { pQN->next = p.pQN; }
		void setBefore(const Position& p)
		{
			pQN->prev = p.pQN;
		}
		bool operator==(const Position& q)
		{
			return pQN == q.pQN;
		}
		bool operator!=(const Position& q)
		{
			return this->pQN != q.pQN;
		}
		Position operator++()
		{
			*this = this->after();
			return *this;
		}
		Position operator--()
		{
			*this = this->before();
			return *this;
		}
		const Position& operator=(const Position& right)
		{
			this->pQN = right.pQN;
			return *this;
		}
		Element& operator*() { return pQN->element(); }
		friend class SkipList;
	}; // end of class Position

private:
	Position start; // skip list top
	Position end; // skip list bottom
	int height;
	int num_elements;
public:
	SkipList()
	{
		height = 0;
		QuadNode* pQNode = new QuadNode(MINUS_INF, Element());
		start = Position(pQNode);
		pQNode = new QuadNode(PLUS_INF, Element());
		end = Position(pQNode);
		start.setAfter(end);
		start.setBefore(Position(NULL));
		start.setAbove(Position(NULL));
		start.setBelow(Position(NULL));
		end.setBefore(start);
		end.setAfter(Position(NULL));
		end.setBelow(Position(NULL));
		end.setAbove(Position(NULL));
		this->num_elements = 0;
		//bottom = Position(NULL);
		srand(time(NULL));
	}
	bool empty()
	{
		return this->num_elements == 0;
	}
	int size()
	{
		return this->num_elements;
	}
	Position SkipListSearch(const Key& k)
	{
		Position pos = start;
		while (pos.below() != Position(NULL))
		{
			pos = pos.below();
			while ((pos.after() != Position(NULL)) && (k >= ((pos.after()).key())))
			{
				pos = pos.after();
				if (pos.after() == (Position)NULL)
					break;
			} // inner while
		} // outer while
		return pos;
	}
	Position SkipListInsert(Key k, const Element e)
	{
		Position p, q, t;
		p = SkipListSearch(k);
		q = Position(NULL);
		int i = -1;
		do {
			i = i + 1;
			if (i >= this->height)
			{
				height = height + 1;
				t = start.after();
				start = insertAfterAbove(Position(NULL), start, MINUS_INF,Element());
				insertAfterAbove(start,
					t, PLUS_INF, Element());
			}
			q = insertAfterAbove(p, q, k, e);
			while (p.above() == (Position)NULL)
			{
				p = p.before(); // scan backward
			}
			p = p.above(); // jump up to higher level
			//q = insertAfterAbove(p, q, k, e);
		} while (rand() % 2 == 0);
		// flip coin and continue if head occurs
		++num_elements;
		return q;
	}
	void SkipListNodeDelete(Position p)
	{
		Position pprev, pnext;
		if (p != Position(NULL))
		{
			pprev = p.before();
			pnext = p.after();
			if (pprev != Position(NULL))
				pprev.setAfter(pnext);
			if (pnext != Position(NULL))
				pnext.setBefore(pprev);
			delete p.pQN;
		}
	}
	void SkipListRemove(Key k)
	{
		Position p, pprev, pnext, p00, px0;
		Position p0y, pxy, old_p;
		int h_max, h;
		p = SkipListSearch(k);
		if ((p.key() != k) || (p.key() == MINUS_INF))
		{
			cout << "Key (" << k << ") is not found";
			cout << "in SkipList !!" << endl;
			return;
		}
		while (p != Position(NULL))
		{
			old_p = p;
			p = p.above();
			SkipListNodeDelete(old_p);
		}
		cout << "deleted skip list node (Key: ";
		cout << k << ")" << endl;
		// compare the height of the skip list
		// and the highest tower level
		p00 = start;
		for (int i = height; i > 0; i--)
		{
			p00 = p00.below();
		}
		px0 = p00.after();
		pxy = start;
		h_max = 0;
		while (px0.key() != PLUS_INF)
		{
			pxy = px0; h = 0; while (pxy != Position(NULL))
			{
				++h; pxy = pxy.above();
			}if (h_max < h) h_max = h; px0 = px0.after();
		}if (h_max < height) {
			cout << "Current height is less than";
			cout << " the new h_max(" << h_max;
			cout << ") ==> need adjustment !!";
			cout << endl;
		}for (int i = 0; i < (height - h_max); i++)
		{
			p0y = start; pxy = start.after(); start = start.below(); SkipListNodeDelete(pxy); SkipListNodeDelete(p0y);
		}
		height = h_max;
	}
	void PrintSkipList()
	{
		int h = 0;
		Position p, p00, px0, p0y, pxy, q, q0, qx;
		int level;
		cout << "Print Skip List Inside :";
		cout << "current height(" << height << ")";
		cout << endl;
		p00 = start;
		level = height;
		for (int i = height; i > 0; i--)
		{
			p00 = p00.below();
		}
		p0y = start;
		pxy = start;
		for (level = height; level >= 0; level--)
		{
			cout << "level" << setw(2);
			cout << level << " ";
			if (pxy.key() == MINUS_INF)
				cout << "-oo";
			else
				cout << setw(11) << pxy.element()->getKeyWord();
			px0 = p00.after();
			for (pxy = p0y.after();; pxy = pxy.after())
			{
				while ((px0.key() != pxy.key()))
				{
					cout << " -----------";
					px0 = px0.after();
				}
				if (pxy.key() == PLUS_INF) {
					break;
				}
				else {
					cout << " -" << setw(10);
					cout << pxy.element()->getKeyWord();
				}
				px0 = px0.after();
			}
			if (pxy.key() == PLUS_INF)
				cout << " + oo";
			else
				cout << setw(11) << pxy.element()->getKeyWord();
			cout << endl;
			p0y = p0y.below();
			pxy = p0y;
		}
		cout << endl;
	}
	Position insertAfterAbove(Position p, Position q, const Key& k, const Element e)
	{
		QuadNode* pNewNode = new QuadNode(k, e);
		Position n(pNewNode);
		n.setAbove(Position(NULL));
		n.setBelow(Position(NULL));
		n.setBefore(Position(NULL));
		n.setAfter(Position(NULL));
		if (p == Position(NULL))
		{
			if (q == Position(NULL))
			{
				cout << "Trying to insert at";
				cout << "(NULL, NULL) position ";
				cout << endl;
				return Position(NULL);
			}
			else {
				q.setAbove(n);
				n.setBelow(q);
				n.setAbove(Position(NULL));
				n.setAfter(Position(NULL));
				return n;
			}
		}
		else
		{
			if (q == Position(NULL)) {
				Position nx, ny;
				cout << "insert a node (" << n.element()->getKeyWord();
				cout << ") at level 0 " << endl;
				nx = p.after();
				p.setAfter(n);
				n.setBefore(p);
				n.setAfter(nx);
				nx.setBefore(n);
				n.setBelow(Position(NULL));
				n.setAbove(Position(NULL));
				return n;
			}
			else {
				Position nx, ny;
				nx = p.after();
				n.setAfter(nx);
				if (nx != Position(NULL))
					nx.setBefore(n);
				p.setAfter(n);
				n.setBefore(p);
				ny = q.above();
				q.setAbove(n);
				n.setBelow(q);
				n.setAbove(ny);
				if (ny != Position(NULL))
					ny.setBelow(n);
			}
		}
		return n;
	}
};
#endif