/*
321_DFS_Graph.cpp

https://www.youtube.com/watch?v=uDWljP2PGmU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=6
*/

class Solution {
  public:

  	// One Component
    void dfs(int i, vector<int> &visited, vector<int> adj[], vector<int> &res) {
    	res.push_back(i);
    	visited[i] = 1;
    	for(auto it: adj[i]) {
    		if(!visited[it]) {
    			dfs(it, visited, adj, res);
    		}
    	}
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    	vector<int> res;
    	vector<int> visited(V+1, 0);
		dfs(i, visited, adj, res);
    	return res;
    }


    // Multi component
    void dfs(int i, vector<int> &visited, vector<int> adj[], vector<int> &res) {
    	res.push_back(i);
    	visited[i] = 1;
    	for(auto it: adj[i]) {
    		if(!visited[it]) {
    			dfs(it, visited, adj, res);
    		}
    	}
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    	vector<int> res;
    	vector<int> visited(V+1, 0);

    	for(int i=0; i<=V; i++) {
    		if(!visited[i]) {
    			dfs(i, visited, adj, res);
    		}
    	}

    	return res;
    }
};
