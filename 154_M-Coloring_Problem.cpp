/*
M-Coloring_Problem.cpp

Given an undirected graph and an integer M. The task is to determine if the graph can be 
colored with at most M colors such that no two adjacent vertices of the graph are colored 
with the same color. Here coloring of a graph means the assignment of colors to all vertices. 
Print 1 if it is possible to colour vertices and 0 otherwise.

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0

https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
Method: Backtracking TC: O(M^N) SC: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	bool isPossible(bool graph[101][101], int color[], int N, int col, int node){
        for(int k=0; k<N; k++){
            if(k!=node && graph[node][k]==1 && color[k]==col) return false;     // adjacent node has same color
        }
        return true;    // none of adjacent node has same color
    }
    
    bool solve(bool graph[101][101],int m,int N,int color[],int node){
        if(node==N) return true;
            
        // try to color it with each and every color from 1 to m
        for(int i=1; i<=m; i++){  
            if(isPossible(graph,color,N,i,node)){
                color[node]=i;
                if(solve(graph,m,N,color,node+1)) return true;
                color[node]=0;
            }
                
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int N) {
        // int color[N];
        // memset(color,0,sizeof color);
        int color[N] = {0};
        return solve(graph,m,N,color,0);
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}