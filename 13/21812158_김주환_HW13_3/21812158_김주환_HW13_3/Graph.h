/** Graph.h */
#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;
#define PLUS_INF INT_MAX / 2 // �����÷ο� ����
enum VrtxStatus { UN_VISITED, VISITED, VRTX_NOT_FOUND };
enum EdgeStatus { DISCOVERY, BACK, CROSS, EDGE_UN_VISITED, EDGE_VISITED, EDGE_NOT_FOUND };
class Graph // Graph based on Adjacency Matrix
{
public:
	class Vertex;
	class Edge;
	typedef std::list<Graph::Vertex> VrtxList;
	typedef std::list<Graph::Edge> EdgeList;
	typedef std::list<Vertex>::iterator VrtxItor;
	typedef std::list<Edge>::iterator EdgeItor;
public:
	class Vertex // Graph::Vertex
	{
		friend ostream& operator<<(ostream& fout, Vertex v)
		{
			fout << v.getName();
			return fout;
		}
	public:
		Vertex() : name(), ID(-1) {}
		Vertex(string n, int id) : name(n), ID(id) { }
		Vertex(int id) : ID(id) {}
		string getName() { return name; }
		void setName(string c_name) { name = c_name; }
		int getID() { return ID; }
		void setID(int id) { ID = id; }
		void setVrtxStatus(VrtxStatus vs) { vrtxStatus = vs; }
		VrtxStatus getvrtxStatus() { return vrtxStatus; }
		bool operator==(Vertex v) { return ((ID == v.getID()) && (name == v.getName())); }
		bool operator!=(Vertex v) { return ((ID != v.getID()) || (name != v.getName())); }
	private:
		string name;
		int ID;
		VrtxStatus vrtxStatus;
	}; // end class Vertex
	class Edge // Graph::Edge
	{
		friend ostream& operator<<(ostream& fout, Edge& e)
		{
			fout << "Edge(" << setw(2) << *e.getpVrtx_1() << ", " << setw(2)
				<< *e.getpVrtx_2() << ", " << setw(4) << e.getDistance() << ")";
			return fout;
		}
	public:
		Edge() : pVrtx_1(NULL), pVrtx_2(NULL), distance(PLUS_INF) {}
		Edge(Vertex& v1, Vertex& v2, int d)
			:distance(d), pVrtx_1(&v1), pVrtx_2(&v2), edgeStatus(EDGE_UN_VISITED)
		{ }
		void endVertices(VrtxList& vrtxLst) // ���۰� ���� �����ϴµ� ��¼��� ����
		{
			vrtxLst.push_back(*pVrtx_1);
			vrtxLst.push_back(*pVrtx_2);
		}
		Vertex opposite(Vertex v)
		{
			if (v == *pVrtx_1)
				return *pVrtx_2;
			else if (v == *pVrtx_2)
				return *pVrtx_1;
			else {
				//cout << "Error in opposite()" << endl;
				return Vertex(NULL);
			}
		}
		Vertex* getpVrtx_1() { return pVrtx_1; }
		Vertex* getpVrtx_2() { return pVrtx_2; }
		int getDistance() { return distance; }
		void setpVrtx_1(Vertex* pV) { pVrtx_1 = pV; }
		void setpVrtx_2(Vertex* pV) { pVrtx_2 = pV; }
		void setDistance(int d) { distance = d; }
		bool operator!=(Edge e) { return ((pVrtx_1 != e.getpVrtx_1()) || (pVrtx_2 != e.getpVrtx_2())); }
		bool operator==(Edge e) { return ((pVrtx_1 == e.getpVrtx_1()) && (pVrtx_2 == e.getpVrtx_2())); }
		void setEdgeStatus(EdgeStatus es) { edgeStatus = es; }
		EdgeStatus getEdgeStatus() { return edgeStatus; }
	private:
		Vertex* pVrtx_1; // �ֽ�ȭ�� �����͸� ����ϱ� ���� ������ ���
		Vertex* pVrtx_2;
		int distance;
		EdgeStatus edgeStatus;
	}; // end class Edge
public:
	Graph() : name(""), pVrtxArray(NULL), pAdjLstArray(NULL) {} // default constructor
	Graph(string nm, int num_nodes) : name(nm), pVrtxArray(NULL), pAdjLstArray(NULL)
	{
		num_vertices = num_nodes;
		pVrtxArray = new Graph::Vertex[num_vertices]; // ������ num_vertices�� ����
		for (int i = 0; i < num_nodes; i++)
			pVrtxArray[i] = NULL;
		pAdjLstArray = new EdgeList[num_vertices]; // ������ num_vertices�� ����
		for (int i = 0; i < num_vertices; i++)
			pAdjLstArray[i].clear();
	}
	string getName() { return name; }
	void vertices(VrtxList& vrtxLst);
	void edges(EdgeList&);
	bool isAdjacentTo(Vertex v, Vertex w);
	void insertVertex(Vertex& v);
	void insertEdge(Edge& e);
	void eraseEdge(Edge e);
	void eraseVertex(Vertex v);
	int getNumVertices() { return num_vertices; }
	void incidentEdges(Vertex v, EdgeList& edges);
	Vertex* getpVrtxArray() { return pVrtxArray; }
	EdgeList* getpAdjLstArray() { return pAdjLstArray; }
	void fprintGraph(ofstream& fout);
	bool isValidvID(int vid);
private:
	string name;
	Vertex* pVrtxArray;
	EdgeList* pAdjLstArray;
	int num_vertices;
};
bool Graph::isAdjacentTo(Vertex v, Vertex w)
{
	return true;
}
void Graph::eraseEdge(Edge e)
{

}
void Graph::eraseVertex(Vertex v)
{

}
void Graph::insertVertex(Vertex& v)
{
	int vID;
	vID = v.getID();
	if (pVrtxArray[vID] == NULL) {
		pVrtxArray[vID] = v;
	}
}
void Graph::vertices(VrtxList& vrtxLst)
{
	vrtxLst.clear();
	for (int i = 0; i < getNumVertices(); i++)
		vrtxLst.push_back(pVrtxArray[i]);
}
void Graph::insertEdge(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	Vertex* pVtx;
	int vID_1, vID_2;
	vrtx_1 = *e.getpVrtx_1(); vID_1 = vrtx_1.getID();
	vrtx_2 = *e.getpVrtx_2(); vID_2 = vrtx_2.getID();
	if (pVrtxArray[vID_1] == NULL) {
		pVrtxArray[vID_1] = vrtx_1;
	}
	if (pVrtxArray[vID_2] == NULL) {
		pVrtxArray[vID_2] = vrtx_2;
	}
	e.setpVrtx_1(&pVrtxArray[vID_1]);
	e.setpVrtx_2(&pVrtxArray[vID_2]);
	pAdjLstArray[vID_1].push_back(e); // �ش� vertex�� edge �߰�
}
void Graph::edges(EdgeList& edges)
{
	EdgeItor eItor;
	Graph::Edge e;
	edges.clear();
	for (int i = 0; i < getNumVertices(); i++)
	{
		eItor = pAdjLstArray[i].begin();
		while (eItor != pAdjLstArray[i].end())
		{
			e = *eItor;
			edges.push_front(e);
			eItor++;
		}
	}
}
void Graph::incidentEdges(Vertex v, EdgeList& edgeLst)
{
	Graph::Edge e;
	EdgeItor eItor;
	int vID = v.getID();
	eItor = pAdjLstArray[vID].begin();
	while (eItor != pAdjLstArray[vID].end())
	{
		e = *eItor;
		edgeLst.push_back(e);
		eItor++;
	}
}
bool Graph::isValidvID(int vid)
{
	if ((vid >= 0) && (vid < num_vertices))
		return true;
	else
	{
		cout << "Vertex ID (" << vid << ") is invalid for Graph (" << getName()
			<< ") with num_vertices (" << num_vertices << ")" << endl;
	}
}
void Graph::fprintGraph(ofstream& fout)
{
	int i, j;
	EdgeItor eItor;
	Graph::Edge e;
	int numOutgoingEdges;
	fout << this->getName() << " with " << this->getNumVertices()
		<< " vertices has following connectivity :" << endl;
	for (i = 0; i < num_vertices; i++)
	{
		fout << " vertex (" << setw(3) << pVrtxArray[i].getName() << ") : ";
		numOutgoingEdges = pAdjLstArray[i].size();
		eItor = pAdjLstArray[i].begin();
		while (eItor != pAdjLstArray[i].end())
		{
			e = *eItor;
			fout << e << " ";
			eItor++;
		}
		fout << endl;
	}
}
#endif