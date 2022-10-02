/*
Topological_sort.cpp

Given a Directed Acyclic Graph (DAG) with V vertices and E edges, 
Find any Topological Sorting of that Graph.

https://practice.geeksforgeeks.org/problems/topological-sort/1
*/


// IMP: is only possible in DAG - Directed Acyclic Graph
// // DFS
// class Solution {
// 	public:
// 	void dfs(int node, vector<int> &visited, stack<int> &s, vector<int> adj[]) {
// 		visited[node] = 1;

// 		for(auto it: adj[node]) {
// 			if(!visited[it]) {
// 				dfs(it, visited, s, adj);
// 			}
// 		}

// // 	visit all nodes till end and start pushing from last nodes.		
// 		s.push(node);
// 	}


// 	vector<int> topoSort(int V, vector<int> adj[]) {
// 		stack<int> s;
// 		vector<int> visited(V, 0);

// 		for(int i=0; i<V; i++) {
// 			if(!visited[i]) {
// 				dfs(i, visited, s, adj);
// 			}
// 		}

// 	    vector<int> ans;
// 		while(!s.empty()) { ans.push_back(s.top()); s.pop(); }
// 		return ans;
// 	}
// };



// BFS
// Kahn;s Algorithm
class Solution {
public: 
	vector<int> topoSort(int V, vector<int> adj[]) {
		queue<int> q;
		vector<int> indegree(V, 0);

		// calculate all the indegree nodes
		for(int i=0; i<V; i++) {
			for(auto it: adj[i]) {
				indegree[it]++;
			}
		}

		// if indegree is 0 push to queue.
		for(int i=0; i<V; i++) {
			if(indegree[i] == 0) q.push(i);
		}

		vector<int> topo;
		while(!q.empty()) {
			int node = q.front(); q.pop();
			topo.push_back(node);

			for(auto it: adj[node]) {
				indegree[it]--;				// reduce indegree for adj
				if(indegree[it] == 0) q.push(it);	// if zero push to queue.
			}
		}

		return topo;
	}
}




