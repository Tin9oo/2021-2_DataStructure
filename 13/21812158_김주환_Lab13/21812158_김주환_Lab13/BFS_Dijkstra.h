/** BFS_Dijkstra.h */
#ifndef BFS_DIJKSTRA_H
#define BFS_DIJKSTRA_H
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
class BreadthFirstSearch
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
	BreadthFirstSearch(Graph& g) :graph(g) {
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
	void DijkstraShortestPathTree(ofstream& fout, Vertex& s, int* pPrev);
	void DijkstraShortestPath(ofstream& fout, Vertex& s, Vertex& t, VrtxList& path);
	Graph& getGraph() { return graph; }
	int** getppDistMtrx() { return ppDistMtrx; }
};
void BreadthFirstSearch::initialize()
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
void BreadthFirstSearch::initDistMtrx()
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
void BreadthFirstSearch::fprintDistMtrx(ofstream& fout)
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
enum BFS_PROCESS_STATUS { NOT_SELECTED, SELECTED };
void BreadthFirstSearch::DijkstraShortestPath(ofstream& fout, Vertex& start, Vertex& target,
	VrtxList& path)
{
	int** ppDistMtrx;
	int* pLeastCost;
	int num_nodes, num_selected;
	int minID, minCost;
	BFS_PROCESS_STATUS* pBFS_Process_Stat;
	int* pPrev;
	Vertex* pVrtxArray;
	Vertex vrtx, * pPrevVrtx, v;
	Edge e;
	int start_vID, target_vID, curVID, vID;
	EdgeList* pAdjLstArray;
	pVrtxArray = graph.getpVrtxArray();
	pAdjLstArray = graph.getpAdjLstArray();
	start_vID = start.getID();
	target_vID = target.getID();
	num_nodes = getNumVertices();
	ppDistMtrx = getppDistMtrx();
	pLeastCost = new int[num_nodes];
	pPrev = new int[num_nodes];
	pBFS_Process_Stat = new BFS_PROCESS_STATUS[num_nodes];
	// initialize L(n) = w(start, n);
	for (int i = 0; i < num_nodes; i++)
	{
		pLeastCost[i] = ppDistMtrx[start_vID][i]; // 시작점으로부터 목적지까지의 edge weight 반환
		pPrev[i] = start_vID;
		pBFS_Process_Stat[i] = NOT_SELECTED;
	}
	pBFS_Process_Stat[start_vID] = SELECTED; // 클라우드 선택
	num_selected = 1;
	path.clear();
	int round = 0;
	int cost;
	string vName;
	fout << "Dijkstra::Least Cost from Vertex (" << start.getName() << ") at each round : " << endl;
	fout << "           |";
	for (int i = 0; i < num_nodes; i++)
	{
		vName = pVrtxArray[i].getName();
		fout << setw(5) << vName;
	}
	fout << endl;
	fout << "-----------+";
	for (int i = 0; i < num_nodes; i++)
	{
		fout << setw(5) << "-----";
	}
	fout << endl;

	while (num_selected < num_nodes)
	{
		round++;
		fout << "round [" << setw(2) << round << "] |";
		minID = -1;
		minCost = PLUS_INF;

		for (int i = 0; i < num_nodes; i++)
		{
			if ((pLeastCost[i] < minCost) && (pBFS_Process_Stat[i] != SELECTED)) {
				minID = i;
				minCost = pLeastCost[i];
			}
		}

		if (minID == -1) { // 연결되지 않은 vertex 존재
			fout << "Error in Dijkstra() -- found not connected vertex !!" << endl;
			break;
		}
		else
		{
			pBFS_Process_Stat[minID] = SELECTED; // 가장 작은 vertex cloud 선택
			num_selected++;
			if (minID == target_vID) // 목적지 도착
			{
				fout << endl << "reached to the target node ("
					<< pVrtxArray[minID].getName() << ") at Least Cost = " << minCost << endl;
				vID = minID;
				do { // 목적지부터 출발지까지 역추적
					vrtx = pVrtxArray[vID];
					path.push_front(vrtx);
					vID = pPrev[vID];
				} while (vID != start_vID);
				vrtx = pVrtxArray[vID];
				path.push_front(vrtx); // start node
				break;
			}
		}
		/* Edge relaxation */
		int pLS, ppDistMtrx_i;
		for (int i = 0; i < num_nodes; i++)
		{
			pLS = pLeastCost[i];
			ppDistMtrx_i = ppDistMtrx[minID][i];
			if ((pBFS_Process_Stat[i] != SELECTED) && (pLeastCost[i] >
				(pLeastCost[minID] + ppDistMtrx[minID][i])))
			{
				pPrev[i] = minID;
				pLeastCost[i] = pLeastCost[minID] + ppDistMtrx[minID][i];
			}
		}
		// print out the pLeastCost[] for debugging
		for (int i = 0; i < num_nodes; i++)
		{
			cost = pLeastCost[i];
			if (cost == PLUS_INF)
				fout << "  +oo";
			else
				fout << setw(5) << pLeastCost[i];
		}
		fout << " ==> selected vertex : " << pVrtxArray[minID] << endl;
	} // end while()
} // end DijkstraShortestPath()

#endif