/*
Detect_cycle_in_an_undirected_graph.cpp

BFS

https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

class Solution {
    public:
    // _________________ BFS _________________
    // TC: O(N+E) SC: O(N+E)
    bool bfs(int s, vector<int> adj[], vector<int> &visited) {
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
                if (bfs(i, adj, vis))
                    return true;
            }
        }
        return false;
    }





    // _________________ DFS _________________
    // DFS - If next is visited we have found a cycle
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