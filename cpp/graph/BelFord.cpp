//============================================================================
// Name        : BelFord.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

class Edge {
public:
	int source;
	int dest;
	int weight;
};

class Graph{
public:
	int Vcnt;		// Number of vertices
	int Ecnt;		// Number of edges

	Edge * edge;

	Graph(int nVertex, int nEdge){
		this->Vcnt = nVertex;
		this->Ecnt = nEdge;
		this->edge = new Edge[nEdge];
	}
};


// Function to find the shortest distance from source 'src'
// to all other vertices
void BelFord(Graph& graph, int src){
	int V = graph.Vcnt;
	int E = graph.Ecnt;

	int * dist  =  new int[V];	// Place holder to store distance of all vertices from src

	// Initialize distance of all vertices from src to infinity
	for (int i = 0; i < V; i++){
		dist[i] = INT_MAX;
	}
	// Set the distance to self to 0
	if (src >=0 && src < V){
		dist[src] = 0;
	}

	// if dist[v] > dist[u] + weight[Euv] then
	// if distance between vertex V and U is greater than weight of the Edge between UV,
	// update the shortest distance between the two
	// Do this for all the vertices
	for (int vidx = 0;vidx < V-1; vidx++){
		for (int eidx = 0 ;eidx < E; eidx++){
			int u = graph.edge[eidx].source;
			int v = graph.edge[eidx].dest;
			int weight = graph.edge[eidx].weight;
			if (dist[u] != INT_MAX && dist[v] > dist[u] + weight){
				dist[v] = dist[u] + weight;
			}
		}
	}

	// If after doing the above reassignments
	// if the distance to a vertex v is less than
	for (int i = 0 ; i <  E; i++){
		int u = graph.edge[i].source;
		int v = graph.edge[i].dest;
		int weight = graph.edge[i].weight;
		if (dist[u] != INT_MAX && dist[v] > dist[u] + weight){
			cout << "Negative cycles detected" << endl;
		}
	}
	for (int i = 0; i < V; i ++){
		cout << i << "\t\t" << dist[i] << endl;
	}
}


int main() {
//	cout << "!!! Hello World !!!" << endl; // prints !!! Hello World !!!
	int V = 5;
	int E = 8;

	Graph* gph = new Graph(V, E);
	Graph graph = *gph;

	graph.edge[0].source = 0;
	graph.edge[0].dest = 1;
	graph.edge[0].weight = -1;

	graph.edge[1].source = 0;
	graph.edge[1].dest = 2;
	graph.edge[1].weight = 4;

	graph.edge[2].source = 1;
	graph.edge[2].dest = 2;
	graph.edge[2].weight = 3;

	graph.edge[3].source = 1;
	graph.edge[3].dest = 3;
	graph.edge[3].weight = 2;

	graph.edge[4].source = 1;
	graph.edge[4].dest = 4;
	graph.edge[4].weight = 2;

	graph.edge[5].source = 3;
	graph.edge[5].dest = 2;
	graph.edge[5].weight = 5;

	graph.edge[6].source = 3;
	graph.edge[6].dest = 1;
	graph.edge[6].weight = 1;

	graph.edge[7].source = 4;
	graph.edge[7].dest = 3;
	graph.edge[7].weight = -3;

	BelFord(graph,0);

	return 0;
}
