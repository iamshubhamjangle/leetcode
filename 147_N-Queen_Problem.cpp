/*
N-Queen_Problem.cpp

Input : 1
Output: [1]

Input : 4
Output: [2 4 1 3 ] [3 1 4 2 ]

https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
Method: Backtracking. TC: O(n!) SC: O(n2)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isValid(vector<vector<int>> board, int x, int y, int n) {
        for(int i = 0; i<x; i++) {   /// verticle column check
            if(board[i][y] == 1) {
                return false;
            }
        }
        
        // Diagonal left top
        int row = x, col = y;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 1){
                return false;
            }
            row--;
            col--;
        }
        
        // Diagonal right top
        row = x, col = y;
        while(row >= 0 && col < n){
            if(board[row][col] == 1){
                return false;
            }
            row--;
            col++;
        }
        
        return true;
    }
    
    void solve(vector<vector<int>> &board, int x, int n, vector<vector<int>> &result) {
        if(x == n) {        // If we reach last row +1 push all ways into result
            vector<int> vt;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(board[i][j] == 1) 
                        vt.push_back(j+1);
                }
            }
            result.push_back(vt);
            return;
        }
        
        for(int col=0; col<n; col++) {
            if(isValid(board, x, col, n)) { // board, row, col, size
                board[x][col] = 1;
                solve(board, x+1, n, result);
                board[x][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;                         // to return outpur
        vector<vector<int>> board(n, vector<int>(n,0));     // as input is board size
        solve(board, 0, n, result);
        sort(result.begin(), result.end());
        return result;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}