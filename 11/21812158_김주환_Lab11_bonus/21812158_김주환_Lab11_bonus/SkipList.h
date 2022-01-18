/** Generic Skip List.h (1) */
#ifndef SK_H
#define SK_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <limits>
#include <string>
#define PROBABILITY_OF_ABOVE_LEVEL 2
#define PLUS_INF "ZZZZZZZZZZ"
#define MINUS_INF "a"
using namespace std;
template<typename K, typename V>
class SkipList {
protected:
	class QuadNode
	{
	private:
		K _key;
		V _value;
	protected:
		QuadNode* up;
		QuadNode* down;
		QuadNode* prev;
		QuadNode* next;
		int level;
	public:
		QuadNode(K k = K(),
			V e = V()) // constructor
			:_key(k), _value(e)
		{
			up = down = prev = next = NULL;
			level = -1;
		}
		K& key() { return _key; }
		V& value() { return _value; }
		void setK(K& k) { _key = k; }
		void setV(V& e) { _value = e; }
		friend class Position;
	}; // end of QuadNode
public:
	class Position
	{
	protected:
		QuadNode* pQN;
	public:
		Position(QuadNode* pSLN) { pQN = pSLN; }
		Position() : pQN(NULL) { }
		K& key() { return pQN->key(); }
		V& value() { return pQN->value(); }
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
		bool operator==(const Position& q) const
		{
			return pQN == q.pQN;
		}
		bool operator!=(const Position& q) const
		{
			return pQN != q.pQN;
		}
		int size()
		{
			return pQN->level;
		}
		V& operator*() const { return pQN->value(); }
		friend class SkipList;
	}; // end of class Position
private:
	Position start; // skip list top
	Position end; // skip list bottom
	int height;
	int num_valueents;
public:
	SkipList()
	{
		height = 0;
		QuadNode* pQNode = new QuadNode(K(MINUS_INF), V());
		start = Position(pQNode);
		pQNode = new QuadNode(K(PLUS_INF), V());
		end = Position(pQNode);
		start.setAfter(end);
		start.setBefore(Position(NULL));
		start.setAbove(Position(NULL));
		start.setBelow(Position(NULL));
		end.setBefore(start);
		end.setAfter(Position(NULL));
		end.setBelow(Position(NULL));
		end.setAbove(Position(NULL));
		//bottom = Position(NULL);
		srand(time(NULL));
	}
	Position SkipListSearch(const K& k)
	{
		Position pos = start;
		while (pos.below() != Position(NULL))
		{
			pos = pos.below();
			while (k >= ((pos.after()).key()))
			{
				pos = pos.after();
				if (pos.after() == (Position)NULL)
					break;
			} // inner while
		} // outer while
		return pos;
	}
	bool empty()
	{
		if (num_valueents == 0)
		{
			return false;
		}
		return true;
	}
	Position begin()
	{
		Position p;
		p = start.after();
		p.setBelow(Position(NULL));
		return p;
	}
	Position endSL()
	{
		Position p;
		p.setAfter(end);

		return p;
	}
	int size()
	{
		return num_valueents;
	}
	Position SkipListInsert(K k, const V e)
	{
		Position p, q, t;
		p = SkipListSearch(k);
		q = Position(NULL);
		int i = -1;
		do {
			i = i + 1;
			if (i >= height)
			{
				height = height + 1;
				t = start.after();
				start = insertAfterAbove(Position(NULL), start, PLUS_INF, V());
				insertAfterAbove(start, t, MINUS_INF, V());
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
		++num_valueents;
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
	void SkipListRemove(K k)
	{
		Position p, pprev, pnext, p00, px0;
		Position p0y, pxy, old_p;
		int h_max, h;
		p = SkipListSearch(k);
		if ((p.key() != k) || (p.key() == MINUS_INF))
		{
			cout << "K (" << k << ") is not found";
				cout << "in SkipList !!" << endl;
				return;
		}
		while (p != Position(NULL))
		{
			old_p = p;
			p = p.above();
			SkipListNodeDelete(old_p);
		}
		cout << "deleted skip list node (K: ";
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
				cout << setw(5) << pxy.key();
			px0 = p00.after();
			for (pxy = p0y.after();; pxy = pxy.after())
			{
				while ((px0.key() != pxy.key()))
				{
					cout << " ------";
					px0 = px0.after();
				}
				if (pxy.key() == PLUS_INF) {
					break;
				}
				else {
					cout << " -" << setw(5);
					cout << pxy.key();
				}
				px0 = px0.after();
			}
			if (pxy.key() == PLUS_INF)
				cout << "₩ + oo";
			else
				cout << setw(5) << pxy.key();
			cout << endl;
			p0y = p0y.below();
			pxy = p0y;
		}
		cout << endl;
	}
	Position insertAfterAbove(Position p, Position q, const K k,
		const V e)
	{
		QuadNode* pNewNode =
			new QuadNode(k, e);
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
				cout << "(NULL, NULL) position";
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
				cout << "insert a node (" << n.key();
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
#endif // !SK_H
