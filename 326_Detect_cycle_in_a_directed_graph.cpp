/*
Detect_cycle_in_a_directed_graph.cpp

Can be done in two ways:
1. DFS
2. BFS (Kahn's algorithm)

Given a Directed Graph with V vertices (Numbered from 0 to V-1) 
and E edges, check whether it contains any cycle or not.

https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/


class Solution {
  public:
  	bool dfs(int node, vector<int> &visited, vector<int> &dfsVisited, vector<int> adj[]) {
  		  visited[node] = 1;
        dfsVisited[node] = 1;

        for(auto it: adj[node]) {
          if(!visited[it]) {
            if(dfs(it, visited, dfsVisited, adj)) return true;
          } else if(dfsVisited[it]) {
            return true;
          }
        }
        
        dfsVisited[node] = 0;
        return false;
  	}


    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> dfsVisited(V, 0);

        for(int i=0; i<V; i++) {
        	if(!visited[i]) {
        		if(dfs(i, visited, dfsVisited, adj)) return true;
        	}
        }

        return false;
    }
};