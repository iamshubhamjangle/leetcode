/*
Graphs_Adjacency_List_and_Matrix.cpp

https://www.youtube.com/watch?v=bTtm2ky7I3Y&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=2
*/

// Adjacency Matrix
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;		// # of vertex, # of input relations
	cin >> n >> m;

	int adj[n+1][n+1];	// adjacency matrix

	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u] = v;		// directed, undirected
		adj[v] = u;		// undirected
	}

	return 0;
}


// Adjacency List
int main(){
	int n, m;		// # of vertex, # of input relations
	cin >> n >> m;

	vector<int> adj[n+1];			// adjacency list
	vector<pair<int,int>> adj[n+1]	// If weights are mentioned. 	// vertex = {index, weight}

	for(int i=0; i<m; i++) {	// 
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);	// directed, undirected
		adj[v].push_back(u);	// undirected
	}
	
	return 0;
}