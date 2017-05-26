//============================================================================
// Name        : Dijkstra.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <set>

using namespace std;

#define V 9

set<int> shrtPathSet;

int getMinDistVert(int dist[V], set<int>& shrtPathSet){
	int minDistSoFar = INT_MAX;
	int minVert;

	set<int>::iterator it;
	for (int vtx = 0; vtx < V; ++vtx) {
		it = shrtPathSet.find(vtx);
		if( (it == shrtPathSet.end()) && dist[vtx] < minDistSoFar){
			minDistSoFar = dist[vtx];
			minVert = vtx;

//			cout << "minVert = " << minVert << endl;
		}
	}
	return minVert;
}


void dijkstra(int graph[V][V], int source) {
	int distance[V];

//	bool shrtPathSet[V];

	for (int i = 0; i < V; ++i) {
		distance[i] = INT_MAX;
	}
	if (source >= 0 && source < V) {
		distance[source] = 0;
	}else{
		cout << "Invalid source" << endl;
		return;
	}
	for (int vtx = 0; vtx < V-1; ++vtx) {
		int u = getMinDistVert(distance, shrtPathSet);// source vertex with minimum distance not yet in shortest path set
//		cout << "u " << u << endl;
		shrtPathSet.insert(u);

		set<int>::iterator it;
//		for(it = shrtPathSet.begin(); it != shrtPathSet.end(); it++){
//			cout <<  ", " << *it;
//		}
//		cout << endl;


		for (int adjV = 0; adjV < V; ++adjV) {
			it = shrtPathSet.find(adjV);
			if(( (it == shrtPathSet.end()) && graph[vtx][adjV]
			    && distance[vtx] != INT_MAX)
				&& (distance[vtx] + graph[vtx][adjV] < distance[adjV])){
				distance[adjV] = distance[vtx] + graph[vtx][adjV];
			}


		}
	}
	for (int j = 0; j < V; ++j) {
		cout << j<< ", "<< distance[j] << endl;
	}



}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
