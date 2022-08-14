/*
Largest_Local_Values_in_a_Matrix.cpp

https://leetcode.com/problems/largest-local-values-in-a-matrix/

*/

class Solution {
public:
    int findMax(vector<vector<int>> &grid, int n, int i, int j) {
        int l = grid[i][j-1];
        int r = grid[i][j+1];
        int u = grid[i-1][j];
        int d = grid[i+1][j];
        
        int lu = grid[i-1][j-1];
        int ru = grid[i-1][j+1];
        int rd = grid[i+1][j+1];
        int ld = grid[i+1][j-1];
        
        int mid = grid[i][j];
        
        return max(l, max(r, max(u, max(d, max(lu, max(ru, max(rd, max(ld, mid))))))));
    }
    
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> ans(n-2, vector<int> (n-2, 0));
        int m = ans.size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = findMax(grid, n, i+1, j+1);
            }
        }
        
        return ans;
    }
};
