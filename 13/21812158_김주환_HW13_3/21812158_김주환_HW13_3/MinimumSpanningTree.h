/** MinimumSpanningTree.h */
#ifndef MST_H
#define MST_H
#include <algorithm>
#include "Graph.h"
#include <fstream>
using namespace std;
typedef Graph::Vertex Vertex;
typedef Graph::Edge Edge;
typedef std::list<Graph::Vertex> VrtxList;
typedef std::list<Graph::Edge> EdgeList;
typedef std::list<Graph::Vertex>::iterator VrtxItor;
typedef std::list<Graph::Edge>::iterator EdgeItor;
class MinimumSpanningTree
{
protected:
	Graph& graph;
	bool done; // flag of search done
	int** ppDistMtrx; // distance matrix
protected:
	void initialize();
	bool isValidvID(int vid) { return graph.isValidvID(vid); }
	int getNumVertices() { return graph.getNumVertices(); }
public:
	MinimumSpanningTree(Graph& g) :graph(g) {
		int num_nodes;
		num_nodes = g.getNumVertices();
		// initialize DistMtrx
		// for (int i = 0; i < num_nodes; i++)
		ppDistMtrx = new int* [num_nodes];
		for (int i = 0; i < num_nodes; i++)
			ppDistMtrx[i] = new int[num_nodes];
		for (int i = 0; i < num_nodes; i++) {
			for (int j = 0; j < num_nodes; j++)
			{
				ppDistMtrx[i][j] = PLUS_INF;
			}
		}
	}
	void initDistMtrx();
	void fprintDistMtrx(ofstream& fout);
	Graph& getGraph() { return graph; }
	int** getppDistMtrx() { return ppDistMtrx; }
	void PrimJarnikMST();
};
void MinimumSpanningTree::initialize()
{
	Vertex* pVrtx = getGraph().getpVrtxArray();
	VrtxList vrtxLst;
	graph.vertices(vrtxLst);
	int num_vertices = graph.getNumVertices();
	for (int vID = 0; vID < num_vertices; vID++)
		pVrtx[vID].setVrtxStatus(UN_VISITED);
	EdgeList edges;
	graph.edges(edges);
	for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
		pe->setEdgeStatus(EDGE_UN_VISITED);
}
void MinimumSpanningTree::initDistMtrx()
{
	int** ppDistMtrx;
	int* pLeaseCostMtrx;
	int num_nodes;
	Vertex* pVrtxArray;
	EdgeList* pAdjLstArray;
	int curVID, vID;
	num_nodes = getNumVertices();
	pVrtxArray = graph.getpVrtxArray();
	pAdjLstArray = graph.getpAdjLstArray();
	ppDistMtrx = getppDistMtrx();
	for (int i = 0; i < num_nodes; i++)
	{
		curVID = pVrtxArray[i].getID();
		EdgeItor pe = pAdjLstArray[curVID].begin();
		while (pe != pAdjLstArray[curVID].end())
		{
			vID = (*(*pe).getpVrtx_2()).getID();
			ppDistMtrx[curVID][vID] = (*pe).getDistance();
			pe++;
		}
		ppDistMtrx[curVID][curVID] = 0;
	}
}
void MinimumSpanningTree::fprintDistMtrx(ofstream& fout)
{
	int** ppDistMtrx;
	Vertex* pVrtxArray;
	int num_nodes;
	int dist;
	int vID;
	string vName;
	pVrtxArray = graph.getpVrtxArray();
	num_nodes = getNumVertices();
	ppDistMtrx = getppDistMtrx();
	fout << "\nDistance Matrix of Graph (" << graph.getName() << ") :" << endl;
	fout << "      |";
	for (int i = 0; i < num_nodes; i++) {
		vName = pVrtxArray[i].getName();
		fout << setw(5) << vName;
	}
	fout << endl;
	fout << "-------+";
	for (int i = 0; i < num_nodes; i++) {
		fout << "-----";
	}
	fout << endl;
	for (int i = 0; i < num_nodes; i++) {
		vName = pVrtxArray[i].getName();
		fout << setw(5) << vName << " |";
		for (int j = 0; j < num_nodes; j++) {
			dist = ppDistMtrx[i][j];
			if (dist == PLUS_INF)
				fout << "  +oo";
			else
				fout << setw(5) << dist;
		}
		fout << endl;
	}
	fout << endl;
}
enum VertexStatus { NOT_SELECTED, SELECTED };
void MinimumSpanningTree::PrimJarnikMST()
{
	int num_nodes;
	int num_edges;
	Vertex* pVrtxArray;
	EdgeList* pAdjLstArray;
	int curVrtx_ID, vrtxID;
	int** ppDistMtrx;
	int* pDist;
	int start, min_id, dist, min_dist, min_dist_org, min_dist_end, end_ID;
	VertexStatus* pVrtxStatus;
	Edge* pParentEdge;
	Edge edge, min_edge; // edge that connects this node to the cloud
	std::list<Edge> selectedEdgeLst;
	std::list<Edge>::iterator edgeItor;
	num_nodes = graph.getNumVertices();
	pVrtxArray = graph.getpVrtxArray();
	pAdjLstArray = graph.getpAdjLstArray();
	initDistMtrx();
	ppDistMtrx = getppDistMtrx();
	pDist = new int[num_nodes];
	pVrtxStatus = new VertexStatus[num_nodes];
	pParentEdge = new Edge[num_nodes];
	for (int i = 0; i < num_nodes; i++) {
		pDist[i] = PLUS_INF;
		pVrtxStatus[i] = NOT_SELECTED;
		pParentEdge[i] = Edge();
	}
	srand(time(0)); 
	start = rand() % num_nodes; // randomly select start node
	cout << "Start node : " << start << endl;
	pDist[start] = 0;
	selectedEdgeLst.clear();
	for (int round = 0; round < num_nodes; round++) {
		min_dist = PLUS_INF;
		min_id = -1;
		for (int n = 0; n < num_nodes; n++)
		{
			if ((pVrtxStatus[n] == NOT_SELECTED) && (pDist[n] < min_dist)) {
				min_dist = pDist[n];
				min_id = n;
			} // end if
		} // end for
		if (min_id == -1)
		{
			cout << "Error in finding Prim-Jarnik's algorithm !!";
			break;
		}
		pVrtxStatus[min_id] = SELECTED;
		// edge relaxation
		EdgeItor pe = pAdjLstArray[min_id].begin();
		while (pe != pAdjLstArray[min_id].end())
		{
			end_ID = ((*pe).getpVrtx_2())->getID();
			dist = (*pe).getDistance();
			if ((pVrtxStatus[end_ID] == NOT_SELECTED) && (dist <= pDist[end_ID])) {
				pDist[end_ID] = dist;
				pParentEdge[end_ID] = *pe;
			}
			pe++;
		} // end while
		if (min_id != start) {
			min_edge = pParentEdge[min_id];
			selectedEdgeLst.push_back(min_edge);
		}
		cout << "Dist after round [" << setw(2) << round << "] : ";
		for (int i = 0; i < num_nodes; i++) {
			if (pDist[i] == PLUS_INF)
				cout << " +oo ";
			else
				cout << setw(4) << pDist[i] << " ";
		}
		cout << endl;
	} // end for
	cout << "\nEnd of finding Minimum Spanning Tree by Prim-Jarnik's Algorithm";
	cout << "selectedEdgeLst.size = " << selectedEdgeLst.size() << endl;
	cout << "Selected edges: " << endl;
	edgeItor = selectedEdgeLst.begin();
	int cnt = 0;
	while (edgeItor != selectedEdgeLst.end())
	{
		cout << *edgeItor << ", ";
		edgeItor++;
		if ((++cnt % 5) == 0)
			cout << endl;
	}
	cout << endl;
}
#endif