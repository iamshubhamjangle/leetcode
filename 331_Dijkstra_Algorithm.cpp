/*
Dijkstra_Algorithm.cpp

We have to use Dijkstra algo as normal bfs with queue wont work for weighted graph.

TC: O((N+E)*logN) SC: O(2N)
*/

class Solution {
	public:
    typedef pair<int,int> pi;

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pi,vector<pi>, greater<pi>> q;
        
        q.push({0,S});
        dist[S] = 0;
        
        while(!q.empty()){
            int parentCost = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto it: adj[node]){
                int nextNode = it[0];
                int edgeCost = it[1];
                if((dist[node] + edgeCost) < dist[nextNode]){
                    dist[nextNode] = dist[node] + edgeCost;
                    q.push({dist[nextNode],nextNode});
                }
                
            }
        }
        
        return dist;
    }
};


