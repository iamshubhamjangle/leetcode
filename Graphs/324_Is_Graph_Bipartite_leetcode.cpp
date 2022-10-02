/*
Is_Graph_Bipartite.cpp

Return true if and only if it is bipartite.

https://leetcode.com/problems/is-graph-bipartite/
*/

class Solution {
public:
	// // _________________ BFS _________________
	// // TC: O(N+E) SC: O(N+E) + O(N) + O(N)	==> (node+edges) queue, color
	// bool bfs(int i, vector<int> &color, vector<vector<int>> &graph) {
	// 	queue<int> q;
	// 	q.push(i);
	// 	color[i] = 1;

	// 	while(!q.empty()) {
	// 		int curr = q.front(); q.pop();
	// 		for(auto it: graph[curr]) {
	// 			if(color[it] == 0) {	// if uncolored, color it
	// 				color[it] = -1 * color[curr];
	// 				q.push(it);
	// 			} else if(color[it] == color[curr]) {	// adjcent is matching
	// 				return false;
	// 			}
	// 		}
	// 	}

	// 	return true;
	// }

 //    bool isBipartite(vector<vector<int>>& graph) {
 //        int n = graph.size();
 //        vector<int> color(n);	// 0: uncolored, 1: color A, 2: color B

 //        queue<int> q;

 //        for(int i=0; i<n; i++) {
 //        	if(color[i] == 0) {	// uncolored / not visited
 //        		if(bfs(i, color, graph) == false)
 //        			return false;
 //        	}
 //        }

 //        return true;
 //    }



	// _________________ DFS _________________
	// TC: O(N+E) SC: O(N+E) + O(N) ASC: O(N)
	bool dfs(int i, vector<int> &color, vector<vector<int>> &graph) {
		if(color[i] == 0) color[i] = 1; // if uncolored then only color

		for(auto it: graph[i]) {
			if(color[it] == 0) {
				color[it] = -1 * color[i];
				if(dfs(it, color, graph) == false) return false;
			} else if(color[it] == color[i]) {
				return false;
			}
		}

		return true;
	}

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);	// 0: uncolored, 1: color A, 2: color B

        queue<int> q;

        for(int i=0; i<n; i++) {	// for all components
        	if(!color[i]) {		// uncolored / not visited
        		if(dfs(i, color, graph) == false)	// if not bipartite return false
        			return false;
        	}
        }

        return true;	// if all component satify bipartite
    }
};