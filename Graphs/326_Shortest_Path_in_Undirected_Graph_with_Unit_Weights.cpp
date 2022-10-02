/*
Shortest_Path_in_Undirected_Graph_with_Unit_Weights.cpp


*/

// BFS

class Solution {
public: 
	void bfs(int V, int src, vector<int> adj[]) {
		// we will be carrying a distance arr and a queue
		// initialise with INT_MAX as we need minimum distance from each point to source
		vector<int> dist(V, INT_MAX);
		queue<int> q;

		dist[src] = 0;
		q.push(src);

		while(!q.empty()) {
			int node = q.front(); q.pop();

			for(auto it: adj[node]) {
				if(dist[node] + 1 < dist[it]) {
					dist[it] = dist[node] + 1;
					q.push(it);
				}
			}
		}

		// printing distance from source to each ith point
		for(auto i: dist) cout << i << " ";
	}
}