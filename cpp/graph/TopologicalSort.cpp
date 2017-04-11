//============================================================================
// Name        : TopologicalSort.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : topological sort in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
	int V; // no. of vertices

	list<int> *adj; // Pointer to the adjacency list for this graph

	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V);

	void addEdge(int v, int w);
	void topologicalSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w); // Add w to v adjacency list
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack){

	visited[v] = true;
	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); i++){
		if(!visited[*i]){
			topologicalSortUtil(*i, visited, Stack);
		}
	}
	Stack.push(v);
}

void Graph::topologicalSort(){
	stack <int> Stack;
	bool *visited = new bool[V]; // Create an array maintain visited flags

	for(int i =0 ; i < V; i++){
		visited[i] = false;
	}

	for (int i=0; i<V; i++){
		if(!visited[i])
			topologicalSortUtil(i, visited, Stack );
	}
	while(!Stack.empty()){
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main() {
	cout << "!!! Topological sort  !!!" << endl; // prints !!! Topological sort  !!!

	Graph myGraph(6)  ;
	myGraph.addEdge(5,2);
	myGraph.addEdge(5,0);
	myGraph.addEdge(4,0);
	myGraph.addEdge(4,1);
	myGraph.addEdge(2,3);
	myGraph.addEdge(3,1);

	cout << "Sorted" << endl;
	myGraph.topologicalSort();

	return 0;
}
