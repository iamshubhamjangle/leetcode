/*
Detect_cycle_in_an_undirected_graph_BFS.cpp

DFS - If next is visited we have found a cycle

https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

class Solution {
    public:
    // TC: O(N+E) SC: O(N+E)
    bool dfs(int i, int prev, vector<int> adj[], vector<int> &visited) {
        visited[i] = 1;
        for(auto it: adj[i]) {
            if(!visited[it]) {
                if(dfs(it, i, adj, visited)) return true;
            }
            if(visited[it] && it != prev) {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};