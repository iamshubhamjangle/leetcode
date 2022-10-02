/*
Minimum_Spanning_Tree.cpp

Given a weighted, undirected and connected graph of V vertices and E edges. 
The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

// PRIMS algorithm - brute force - TC: O(N*N) SC: O(3N)
class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> visited(V, false);

        key[0] = 0;
        parent[0] = -1;

        // find the minimum from the adjacent, iterate n-1 edges
        for(int count=0; count<V-1; count++) {
            int mini = INT_MAX, u;

            // find minimum
            for(int v=0; v<V; v++) {
                if(visited[v] == false && key[v] < mini)
                    mini = key[v], u = v;
            }

            visited[u] = true;

            for(auto it: adj[u]) {
                int v = it.first;
                int weight = it.second;
                if(visited[v] == false && weight < key[v])
                    parent[v] = u, key[v] = weight;
            }
        }


        for(auto i: parent) cout << i << " ";
        return 0;
    }
};




// PRIMS algorithm - optimized - TC: O((N+E)*logN) SC: O(3N)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,m;
    cin >> N >> m;
    vector<pair<int,int> > adj[N]; 

    int a,b,wt;
    for(int i = 0; i<m ; i++){
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }   
    
    int parent[N]; 
    int key[N]; 
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}