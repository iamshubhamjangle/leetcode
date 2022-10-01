/*
Detect_cycle_in_a_directed_graph.cpp

Can be done in two ways:
1. DFS --> use in interview.
2. BFS (Kahn's algorithm)

Given a Directed Graph with V vertices (Numbered from 0 to V-1) 
and E edges, check whether it contains any cycle or not.

https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/


// // DFS - Use visited, dfsVisited array. O(N+E) SC: O(2N) ASC: O(N)
// class Solution {
//   public:
//   	bool dfs(int node, vector<int> &visited, vector<int> &dfsVisited, vector<int> adj[]) {
//   		  visited[node] = 1;
//         dfsVisited[node] = 1;

//         for(auto it: adj[node]) {
//           if(!visited[it]) {
//             if(dfs(it, visited, dfsVisited, adj)) return true;
//           } else if(dfsVisited[it]) {
//             return true;
//           }
//         }
		
//         dfsVisited[node] = 0;
//         return false;
//   	}


//     bool isCyclic(int V, vector<int> adj[]) {
//         vector<int> visited(V, 0);
//         vector<int> dfsVisited(V, 0);

//         for(int i=0; i<V; i++) {
//         	if(!visited[i]) {
//         		if(dfs(i, visited, dfsVisited, adj)) return true;
//         	}
//         }

//         return false;
//     }
// };




// BFS - Kahns Algorithm.
class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]) {
		queue<int> q;

		// create in degree array 
		// u -> v. we are increasing all count for 'v'
		vector<int> indegree(V, 0);
		for(int i=0; i<V; i++) {
			for(auto it: adj[i]) indegree[it]++;
		}

		// get all zero indegree in queue
		for(int i=0; i<V; i++) {
			if(indegree == 0) q.push(i);
		}

		// start from 0 indegree node
		int cnt = 0;
		while(!q.empty()) {
			int node = q.front(); q.pop();
			cnt++;

			for(auto it: adj[node]) {
				indegree[it]--;
				if(indegree[it] == 0) q.push(i); // this will be next indegree node
			}
		}

		if(cnt == N) return false;	
		return true;	 // // For cyclic the count != N
	}
}

