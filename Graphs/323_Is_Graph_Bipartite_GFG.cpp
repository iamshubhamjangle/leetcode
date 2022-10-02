/*
Is_Graph_Bipartite_GFG.cpp

Return true if and only if it is bipartite.
Graph can be colored alternating => bipartite = true;
Adjacent nodes cannot be colored => bipartite = false;

https://practice.geeksforgeeks.org/problems/bipartite-graph/1
*/


class Solution {
public:
    bool bfs(int i, vector<int> adj[], vector<int> &color) {
		queue<int> q;
		q.push(i);
		color[i] = 1;	// initial color

		while(!q.empty()) {
			int node = q.front();
			q.pop();

			for(auto it: adj[node]) {
				if(color[it] == -1) {	// if not visited
					color[it] = 1 - color[node];	// 1-0=1	//1-1=0
					q.push(it);
				} else if(color[it] == color[node]) {
					return false;
				}
			}
		}

		return true;
	}


	bool isBipartite(int V, vector<int>adj[]){
		vector<int> color(V, -1);

		for(int i=0; i<V; i++) {
			if(color[i] == -1) {
				if(bfs(i, adj, color) == false) // any component not bipartite
					return false;	// graph is not bipartite.
			}
		}

		return true;
	}
};