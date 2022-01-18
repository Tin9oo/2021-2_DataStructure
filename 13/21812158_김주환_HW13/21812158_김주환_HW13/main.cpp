/* main.cpp */
/* Description
* Graph 구현및 기능 검사 (DFS)
* Programmed by J. H. Kim
* Last updated : 2021-12-07 */
#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "DepthFirstSearch.h"
#define NUM_NODES 25
#define NUM_EDGES 50
typedef Graph::Vertex Vertex;
typedef Graph::Edge Edge;
typedef std::list<Graph::Vertex> VrtxList;
typedef std::list<Graph::Edge> EdgeList;
typedef std::list<Graph::Vertex>::iterator VrtxItor;
typedef std::list<Graph::Edge>::iterator EdgeItor;
void main()
{
	ofstream fout;
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Fail to open output.txt file !!" << endl;
		exit(1);
	}
	Vertex
		v[NUM_NODES] =
	{
	Vertex("0", 0), Vertex("1", 1),
	Vertex("2", 2), Vertex("3", 3),
	Vertex("4", 4), Vertex("5", 5),
	Vertex("6", 6), Vertex("7", 7),
	Vertex("8", 8), Vertex("9", 9),
	Vertex("10", 10), Vertex("11", 11),
	Vertex("12", 12), Vertex("13", 13),
	Vertex("14", 14), Vertex("15", 15),
	Vertex("16", 16), Vertex("17", 17),
	Vertex("18", 18), Vertex("19", 19),
	Vertex("20", 20), Vertex("21", 21),
	Vertex("22", 22), Vertex("23", 23),
	Vertex("24", 24)
	};
	Edge edges[NUM_EDGES] =
	{
	Edge(v[0], v[1], 1), Edge(v[1], v[0], 1),
	Edge(v[0], v[5], 1), Edge(v[5], v[0], 1),
	Edge(v[1], v[2], 1), Edge(v[2], v[1], 1),
	Edge(v[1], v[6], 1), Edge(v[6], v[1], 1),
	Edge(v[3], v[8], 1), Edge(v[8], v[3], 1),
	Edge(v[4], v[9], 1), Edge(v[9], v[4], 1),

	Edge(v[6], v[7], 1), Edge(v[7], v[6], 1),
	Edge(v[6], v[11], 1), Edge(v[11], v[6], 1),
	Edge(v[7], v[8], 1), Edge(v[8], v[7], 1),
	Edge(v[8], v[13], 1), Edge(v[13], v[8], 1),
	Edge(v[9], v[14], 1), Edge(v[14], v[9], 1),

	Edge(v[10], v[11], 1), Edge(v[11], v[10], 1),
	Edge(v[10], v[15], 1), Edge(v[15], v[10], 1),
	Edge(v[12], v[17], 1), Edge(v[17], v[12], 1),
	Edge(v[13], v[14], 1), Edge(v[14], v[13], 1),
	Edge(v[14], v[19], 1), Edge(v[19], v[14], 1),

	Edge(v[15], v[16], 1), Edge(v[15], v[16], 1),
	Edge(v[15], v[20], 1), Edge(v[15], v[20], 1),
	Edge(v[16], v[21], 1), Edge(v[16], v[21], 1),
	Edge(v[17], v[18], 1), Edge(v[18], v[17], 1),
	Edge(v[17], v[22], 1), Edge(v[22], v[17], 1),
	Edge(v[18], v[19], 1), Edge(v[19], v[18], 1),
	Edge(v[18], v[23], 1), Edge(v[23], v[18], 1),

	Edge(v[21], v[22], 1), Edge(v[22], v[21], 1),
	Edge(v[23], v[24], 1), Edge(v[24], v[23], 1)
	};
	Graph simpleGraph("GRAPH_SQUARE_16_NODES", NUM_NODES);
	cout << "Inserting vertices .." << endl;
	for (int i = 0; i < NUM_NODES; i++) {
		simpleGraph.insertVertex(v[i]);
	}
	VrtxList vrtxLst;
	simpleGraph.vertices(vrtxLst);
	int count = 0;
	cout << "Inserted vertices: ";
	for (VrtxItor vItor = vrtxLst.begin(); vItor != vrtxLst.end(); ++vItor) {
		cout << *vItor << " ";
	}
	cout << endl;
	cout << "Inserting edges .." << endl;
	for (int i = 0; i < NUM_EDGES; i++)
	{
		simpleGraph.insertEdge(edges[i]);
	}
	cout << "Inserted edges: " << endl;
	count = 0;
	EdgeList egLst;
	simpleGraph.edges(egLst);
	for (EdgeItor p = egLst.begin(); p != egLst.end(); ++p)
	{
		count++;
		cout << *p << ", ";
		if (count % 5 == 0)
			cout << endl;
	}
	cout << endl;
	cout << "Print out Graph based on Adjacency List .." << endl;
	simpleGraph.printGraph();
	cout << "Testing dfsGraph..." << endl;
	DepthFirstSearch dfsGraph(simpleGraph);
	VrtxList path;
	dfsGraph.findPath(v[0], v[24], path);
	cout << endl << "Path(" << v[0] << " = > " << v[24] << ") : ";
	for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
		cout << *vItor << " ";
	cout << endl;
	dfsGraph.findPath(v[24], v[0], path);
	cout << endl << "Path(" << v[24] << " = > " << v[0] << ") : ";
	for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
		cout << *vItor << " ";
	cout << endl;
}