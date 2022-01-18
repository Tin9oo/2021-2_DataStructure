/** DepthFirstSearch.h (1)*/
#ifndef DFS_H
#define DFS_H
#include <iostream>
#include <algorithm>
#include "Graph.h"
using namespace std;
typedef Graph::Vertex Vertex;
typedef Graph::Edge Edge;
typedef std::list<Graph::Vertex> VrtxList;
typedef std::list<Graph::Vertex>::iterator VertexItor;
typedef std::list<Graph::Edge> EdgeList;
typedef std::list<Graph::Edge>::iterator EdgeItor;
class DepthFirstSearch
{
protected:
	Graph& graph;
	Vertex start;
	bool done; // flag of search done
protected:
	void initialize();
	void dfsTraversal(Vertex& v, Vertex& target, VrtxList& path);
	virtual void traverseDiscovery(const Edge& e, const Vertex& from) { }
	virtual void traverseBack(const Edge& e, const Vertex& from) { }
	virtual void finishVisit(const Vertex& v) {}
	virtual bool isDone() const { return done; }
	// marking utilities
	void visit(Vertex& v);
	void visit(Edge& e);
	void unvisit(Vertex& v);
	void unvisit(Edge& e);
	bool isVisited(Vertex& v);
	bool isVisited(Edge& e);
	void setEdgeStatus(Edge& e, EdgeStatus es);
	EdgeStatus getEdgeStatus(Edge& e);
public:
	DepthFirstSearch(Graph& g);
	void findPath(Vertex& s, Vertex& t, VrtxList& path);
	Graph& getGraph() { return graph; }
	void showConnectivity(ofstream& fout);
private:
	VrtxStatus* pVrtxStatus;
	EdgeStatus** ppEdgeStatus;
	int** ppConnectivity; // two dimensional array; table of distance[v1][v2]
}; // end of class DepthFirstSearch
DepthFirstSearch::DepthFirstSearch(Graph& g) :graph(g)
{
	int num_nodes = graph.getNumVertices();
	pVrtxStatus = new VrtxStatus[num_nodes];
	for (int i = 0; i < num_nodes; i++)
		pVrtxStatus[i] = UN_VISITED;
	ppEdgeStatus = new EdgeStatus * [num_nodes];
	for (int i = 0; i < num_nodes; i++)
		ppEdgeStatus[i] = new EdgeStatus[num_nodes];
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppEdgeStatus[i][j] = EDGE_UN_VISITED;
	ppConnectivity = new int* [num_nodes];
	for (int i = 0; i < num_nodes; i++)
		ppConnectivity[i] = new int[num_nodes];
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppConnectivity[i][j] = PLUS_INF; // initially not connected
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	EdgeList edges;
	edges.clear();
	graph.edges(edges);
	for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
	{
		vrtx_1 = *(*pe).getpVrtx_1(); vID_1 = vrtx_1.getID();
		vrtx_2 = *(*pe).getpVrtx_2(); vID_2 = vrtx_2.getID();
		ppConnectivity[vID_1][vID_2] = (*pe).getDistance();
	}
	for (int i = 0; i < num_nodes; i++)
		ppConnectivity[i][i] = 0; // distance of same node
}
void DepthFirstSearch::initialize()
{
	int num_nodes = graph.getNumVertices();
	VrtxList verts;
	graph.vertices(verts);
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	done = false;
	for (int i = 0; i < num_nodes; i++)
		pVrtxStatus[i] = UN_VISITED;
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppEdgeStatus[i][j] = EDGE_UN_VISITED;
}
void DepthFirstSearch::showConnectivity(ofstream& fout)
{
	int num_nodes = graph.getNumVertices();
	int dist;
	Graph g = getGraph();
	Vertex* pVrtxArray = g.getpVrtxArray();
	fout << "Connectivity of graph: " << endl;
	fout << " |";
	for (int i = 0; i < num_nodes; i++)
		fout << setw(5) << pVrtxArray[i].getName();
	fout << endl;
	fout << "-----+";
	for (int i = 0; i < num_nodes; i++)
		fout << "-----";
	fout << endl;
	for (int i = 0; i < num_nodes; i++) {
		fout << " " << pVrtxArray[i].getName() << " | ";
		for (int j = 0; j < num_nodes; j++) {
			dist = ppConnectivity[i][j];
			if (dist == PLUS_INF)
				fout << " +oo";
			else
				fout << setw(5) << dist;
		} // end inner for
		fout << endl;
	} // end outer for
}
void DepthFirstSearch::dfsTraversal(Vertex& v, Vertex& target, VrtxList& path)
{
	//startVisit(v);
	visit(v);
	if (v == target) {
		done = true;
		return;
	}
	EdgeList incidentEdges;
	incidentEdges.clear();
	graph.incidentEdges(v, incidentEdges);
	EdgeItor pe = incidentEdges.begin();
	while (!isDone() && pe != incidentEdges.end())
	{
		Edge e = *pe++;
		EdgeStatus eStat = getEdgeStatus(e);
		if (eStat == EDGE_UN_VISITED)
		{
			visit(e);
			Vertex w = e.opposite(v);
			if (!isVisited(w))
			{
				//traverseDiscovery(e, v);
				path.push_back(w);
				setEdgeStatus(e, DISCOVERY);
				if (!isDone()) {
					dfsTraversal(w, target, path); // recursive call
					if (!isDone()) {
						//traverseBack(e, v);
						// check whether node w is already in path as a cycle
						Vertex last_pushed = path.back(); // for debugging
						path.pop_back();
					}
				}
			}
			else // w is VISITED
			{
				setEdgeStatus(e, BACK);
			}
		} // end if (eStat == EDGE_UN_VISITED)
	} // end of while - processing of all incedent edges
}
void DepthFirstSearch::findPath(Vertex& start, Vertex& target, VrtxList& path)
{
	initialize();
	path.clear();
	path.push_back(start);
	dfsTraversal(start, target, path);
}
void DepthFirstSearch::visit(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	if (graph.isValidvID(vID))
	{
		pVrtxStatus[vID] = VISITED;
	}
}
void DepthFirstSearch::visit(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	int numNodes = getGraph().getNumVertices();
	vrtx_1 = *e.getpVrtx_1(); vID_1 = vrtx_1.getID();
	vrtx_2 = *e.getpVrtx_2(); vID_2 = vrtx_2.getID();
	if (graph.isValidvID(vID_1) && graph.isValidvID(vID_2))
	{
		ppEdgeStatus[vID_1][vID_2] = EDGE_VISITED;
	}
}
void DepthFirstSearch::unvisit(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	if (graph.isValidvID(vID))
	{
		pVrtxStatus[vID] = UN_VISITED;
	}
}
void DepthFirstSearch::unvisit(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	int numNodes = getGraph().getNumVertices();
	vrtx_1 = *e.getpVrtx_1(); vID_1 = vrtx_1.getID();
	vrtx_2 = *e.getpVrtx_2(); vID_2 = vrtx_2.getID();
	if (graph.isValidvID(vID_1) && graph.isValidvID(vID_2))
	{
		ppEdgeStatus[vID_1][vID_2] = EDGE_UN_VISITED;
	}
}
bool DepthFirstSearch::isVisited(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	if (graph.isValidvID(vID))
	{
		return (pVrtxStatus[vID] == VISITED);
	}
}
bool DepthFirstSearch::isVisited(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	EdgeStatus eStat;
	int numNodes = getGraph().getNumVertices();
	vrtx_1 = *e.getpVrtx_1(); vID_1 = vrtx_1.getID();
	vrtx_2 = *e.getpVrtx_2(); vID_2 = vrtx_2.getID();
	if (graph.isValidvID(vID_1) && graph.isValidvID(vID_2))
	{
		eStat = ppEdgeStatus[vID_1][vID_2];
		if ((eStat == EDGE_VISITED) || (eStat == DISCOVERY) || (eStat == BACK))
			return true;
		else
			return false;
	}
	return false;
}
void DepthFirstSearch::setEdgeStatus(Edge& e, EdgeStatus es)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	int numNodes = getGraph().getNumVertices();
	vrtx_1 = *e.getpVrtx_1(); vID_1 = vrtx_1.getID();
	vrtx_2 = *e.getpVrtx_2(); vID_2 = vrtx_2.getID();
	if (graph.isValidvID(vID_1) && graph.isValidvID(vID_2))
	{
		ppEdgeStatus[vID_1][vID_2] = es;
	}
}
EdgeStatus DepthFirstSearch::getEdgeStatus(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	int numNodes = getGraph().getNumVertices();
	EdgeStatus eStat;
	vrtx_1 = *e.getpVrtx_1(); vID_1 = vrtx_1.getID();
	vrtx_2 = *e.getpVrtx_2(); vID_2 = vrtx_2.getID();
	if (graph.isValidvID(vID_1) && graph.isValidvID(vID_2))
	{
		eStat = ppEdgeStatus[vID_1][vID_2];
		return eStat;
	}
	else {
		cout << "Edge (" << e << ") was not found from AdjacencyList" << endl;
		return EDGE_NOT_FOUND;
	}
}
#endif