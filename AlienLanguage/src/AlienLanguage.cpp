//============================================================================
// Name        : AlienLanguage.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <stack>
#include <cstring>
using namespace std;

class Graph{
	int V; // Number of vertices

	list<int> * adj;// Pointer to array containing adjacency list for all vertices
	void topologicalSortUtil(int v,bool visited[], stack <int> &Stack);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void topologicalSort();
};

Graph::Graph(int V){
	this->V=V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w); // Add w to vertex V's adjacency list
}

// For Topological sort we must first visit all the children and then visit the parent
// So recursively visit all the children, which would already pushed children on to the stack
// All required children are on the stack, now push the parent, this will ensure that parent gets
// accessed first when accessing
// V: given vertex
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack){
	visited[v] = true; // Mark the current vertex as visited
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++) // For all vertices in Vertex V's adjacency list
	{
		if (visited[*i] == false) // if they are not already visited
		{
			topologicalSortUtil(*i, visited, Stack);
		}
	}
	Stack.push(v); // Since this
}

void Graph::topologicalSort(){
	stack<int> Stack;

	bool *visited = new bool[V];

	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < V; i++) {
		if(visited[i] == false){
			topologicalSortUtil(V,visited,Stack);
		}
	}
	while(Stack.empty() == false){
		cout << (char) ('a' + Stack.top()) << " ";
		Stack.pop();
	}
}

int min(int a, int b){
	return (a < b) ? a:b;
}


// n : size of words array,
// alpha: size of alphabets
void printOrder(string words[], int n, int alpha){
	Graph g(alpha); // initialize a graph alphabet size

	for (int i = 0; i < n-1; i++) {
		// Take the current mismatching words find first mismatching char
		string w1 = words[i];
		string w2 = words[i+1];

		for (int j = 0; j < min(w1.length(), w2.length()) ; j++) {
			// IF we find a mismatching word character, then  add an edge from
			// character in w1, to character in w2 (w1 comes before w2)
			if( w1[j] != w2[j] ){
				g.addEdge( (w1[j]-'a'), (w2[j]-'a') );
				break;
			}

		}
	}
	g.topologicalSort();
}

int main() {
	cout << "!!! fs !!!" << endl; // prints !!! fs !!!

	string words[] = {"caa", "aaa", "aab"};
	    printOrder(words, 3, 3);
	    return 0;
}
