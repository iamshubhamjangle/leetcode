/*
Detect_cycle_in_an_undirected_graph.cpp

BFS

https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

class Solution {
    public:
    // TC: O(N+E) SC: O(N+E)
    bool checkForCycle(int s, vector<int> adj[], vector<int> &visited) {
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (checkForCycle(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};