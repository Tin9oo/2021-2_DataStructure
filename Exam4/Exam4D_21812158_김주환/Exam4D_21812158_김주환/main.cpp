/* main.cpp */
/* Description
* Graph 구현
* Programmed by J. H. Kim
* Last updated : 2021-12-15 */
#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "BFS_Dijkstra.h"
using namespace std;

void print_path(ofstream& fout, Vertex* v, int v_start, int v_end, VrtxList& path); // 추가 구현

void main()
{
	ofstream fout;
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Failed to open output.txt file !!" << endl;
		exit;
	}
#define NUM_NODES 9
#define NUM_EDGES 32
	enum vids { STL, RPD, SF, CHG, LA, DLS, MIA, NY, BOS };
	Vertex v[NUM_NODES] =
	{ Vertex("STL", 0), Vertex("RPD", 1), Vertex("SF", 2),
	Vertex("CHG", 3), Vertex("LA", 4), Vertex("DLS", 5),
	Vertex("MIA", 6), Vertex("NY", 7), Vertex("BOS", 8) };
	Edge edges[NUM_EDGES] =
	{
		Edge(v[0], v[1], 949), Edge(v[1], v[0], 949),
		Edge(v[0], v[2], 680), Edge(v[2], v[0], 680),

		Edge(v[1], v[2], 1090), Edge(v[2], v[1], 1090),
		Edge(v[1], v[3], 801), Edge(v[3], v[1], 801),

		Edge(v[2], v[3], 1846), Edge(v[3], v[2], 1846),
		Edge(v[2], v[4], 337), Edge(v[4], v[2], 337),
		Edge(v[2], v[5], 1464), Edge(v[5], v[2], 1464),

		Edge(v[3], v[5], 802), Edge(v[5], v[3], 802),
		Edge(v[3], v[7], 740), Edge(v[7], v[3], 740),
		Edge(v[3], v[8], 867), Edge(v[8], v[3], 867),

		Edge(v[4], v[5], 1235), Edge(v[5], v[4], 1235),
		Edge(v[4], v[6], 2342), Edge(v[6], v[4], 2342),

		Edge(v[5], v[6], 1121), Edge(v[6], v[5], 1121),

		Edge(v[6], v[7], 1090), Edge(v[7], v[6], 1090),
		Edge(v[6], v[8], 1258), Edge(v[8], v[6], 1258),

		Edge(v[7], v[8], 187), Edge(v[8], v[7], 187),
	};

	Graph simpleGraph("GRAPH_Simple_USA_9_Cities", NUM_NODES);
	fout << "Inserting vertices .." << endl;
	for (int i = 0; i < NUM_NODES; i++) {
		simpleGraph.insertVertex(v[i]);
	}
	VrtxList vtxLst;
	simpleGraph.vertices(vtxLst);
	fout << "Inserted vertices: ";
	for (VrtxItor vItor = vtxLst.begin(); vItor != vtxLst.end(); ++vItor) {
		fout << *vItor << ", ";
	}
	fout << endl;
	fout << "Inserting edges .." << endl;
	for (int i = 0; i < NUM_EDGES; i++)
	{
		simpleGraph.insertEdge(edges[i]);
	}
	fout << "Inserted edges: " << endl;
	int count = 0;
	EdgeList egLst;
	simpleGraph.edges(egLst);
	for (EdgeItor p = egLst.begin(); p != egLst.end(); ++p)
	{
		count++;
		fout << *p << ", ";
		if (count % 5 == 0)
			fout << endl;
	}
	fout << endl;
	fout << "Print out Graph based on Adjacency List .." << endl;
	simpleGraph.fprintGraph(fout);

	// enum vids { STL, RPD, SF, CHG, LA, DLS, MIA, NY, BOS };
	/* ==========================================*/
	VrtxList path;
	BreadthFirstSearch bfsGraph(simpleGraph);

	fout << "\nTesting Breadth First Search with Dijkstra Algorithm" << endl;
	bfsGraph.initDistMtrx();
	bfsGraph.fprintDistMtrx(fout);

	int vid_1 = STL;
	int vid_2 = MIA;
	path.clear();
	fout << "\nDijkstra Shortest Path Finding from " << v[vid_1].getName() << " to " << v[vid_2].getName()
		<< " .... " << endl;
	bfsGraph.DijkstraShortestPath(fout, v[vid_1], v[vid_2], path);
	fout << "Path found by DijkstraShortestPath from " << v[vid_1] << " to " << v[vid_2] << " : ";
	print_path(fout, v, vid_1, vid_2, path);
	path.clear();
	fout << "\nDijkstra Shortest Path Finding from " << v[vid_2].getName() << " to " << v[vid_1].getName()
		<< " .... " << endl;
	bfsGraph.DijkstraShortestPath(fout, v[vid_2], v[vid_1], path);
	fout << "Path found by DijkstraShortestPath from " << v[vid_2] << " to " << v[vid_1] << " : ";
	print_path(fout, v, vid_2, vid_1, path);

	fout.close();
}
void print_path(ofstream& fout, Vertex* v, int v_start, int v_end, VrtxList& path)
{
	for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
	{
		fout << *vItor;
		if (*vItor != v[v_end])
			fout << " -> ";
	}
	fout << endl;
}