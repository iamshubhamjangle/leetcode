/*
Shortest_Path_in_Directed_Acyclic_Graph_(DAG).cpp

- Use Topological sort then from topo stack calculate the mini distance.
TC: O(2N+2E) SC: O(2N)
*/
#define INF INT_MAX

void dfsTopoSort(int i, vector<int> &visited, stack<int> &st, vector<pair<int, int>> adj) {
	visited[i] = 1;
	for(auto it: adj[i]) {
		if(!visited[it.first]) {
			dfsTopoSort(it.first, visited, st, adj);
		}
	}
	st.push(i);
}

void shortestPath(int src, int N, vector<pair<int, int>> adj[]) {
	vector<int> visited(N ,0);
	
	// prepare the topo sort stack
	stack<int> st;
	for(int i=0; i<N; i++) {
		if(!visited[i]) 
			dfsTopoSort(i, visited, st, adj);
	}

	// create distance array
	vector<int> dist(N, 1e9);
	dist[src] = 0;

	// for each element in topo sort
	while(!st.empty()) {
		int node = st.top(); st.pop();

		if(dist[node] != INF) {
			for(auto it: adj[node]) {
				if(dist[node] + it.second < dist[it.first]) {
					dist[it.first] = dist[node] + it.second;
				}
			}
		}
	}

	// print values in shortest dist array
	for(auto i: dist) cout << i << " ";

}