/*
Unique_Paths_III.cpp

https://leetcode.com/problems/unique-paths-iii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid) {
        // if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return 0;
        // if(grid[i][j] == 2) return 1;

        // int a = solve(i, j+1, m, n, grid);
        // int b = solve(i+1, j, m, n, grid);
        // int c = solve(i-1, j, m, n, grid);
        // int d = solve(i, j-1, m, n, grid);

        // return a + b + c + d;
        return 2;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 

        int si, sj;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    si = i; sj = j;
                }
            }
        }

        cout << "si: " << si << " sj: " << sj << endl;
        return solve(si, sj, m, n, grid);
    }
};


int main(){
    Solution s;
    vector<vector<int>> grid;

    grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << s.uniquePathsIII(grid) << endl;

    grid = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    cout << s.uniquePathsIII(grid) << endl;

    grid = {{0,1},{2,0}};
    cout << s.uniquePathsIII(grid) << endl;
}