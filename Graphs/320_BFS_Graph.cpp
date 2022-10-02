/*
BFS_Graph.cpp

https://www.youtube.com/watch?v=UeE67iCK2lQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=5
*/

class Solution {
public:
	// // Use only component 1
	// // TC: O(N+E) SC: O(N+E)
	// // N = no of nodes, E = time taken to visit adjacent nodes
	// vector<int> bfsOfGraph(int nodes, vector<int> adj[]) {
	// 	vector<int> res;
	// 	vector<int> visited(nodes+1, 0);	// 1 based indexing

	// 	// take only nodes directly connected to node 0.
	// 	// hences lets not iterate the adj list as we need only component1.
	// 	queue<int> q;
	// 	q.push(0);
	// 	visited[0] = 1;

	// 	while(!q.empty()) {
	// 		int node = q.front(); q.pop();
	// 		res.push_back(node);

	// 		for(auto it: adj[node]) {
	// 			if(!visited[it]) {
	// 				q.push(it);
	// 				visited[it] = 1;
	// 			}
	// 		}
	// 	}

	// 	return res;
	// }


	// For multiple components
	// // TC: O(N+E) SC: O(N+E)
	// // N = no of nodes, E = time taken to visit adjacent nodes
	vector<int> bfsOfGraph(int nodes, vector<int> adj[]) {
		vector<int> res;
		vector<int> visited(nodes+1, 0);	// 1 based indexing

		for(int i=0; i<nodes; i++) {
			if(!visited[i]) {
				queue<int> q;
				q.push(i);
				visited[i] = 1;

				while(!q.empty()) {
					int node = q.front(); q.pop();
					res.push_back(node);

					for(auto it: adj[node]) {
						if(!visited[it]) {
							q.push(it);
							visited[it] = 1;
						}
					}
				}
			}
		}

		return res;
	}
}


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}