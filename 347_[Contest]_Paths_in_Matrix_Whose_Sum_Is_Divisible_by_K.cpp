/*
[Contest]_Paths_in_Matrix_Whose_Sum_Is_Divisible_by_K.cpp

https://leetcode.com/contest/weekly-contest-314/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
*/

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

class Solution {
public:
    int solve(int i, int j, int sum, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &dp) {
        if(i == 0 && j == 0) {
            if((sum+grid[i][j]) % k == 0) return 1;
        	return 0;
        }

        if(i < 0 || j < 0)
        	return 0;

        if(dp[i][j][sum%k] != -1)
        	return dp[i][j][sum%k];
        
        int up = solve(i-1, j, sum+grid[i][j], grid, k, dp);
        int left = solve(i, j-1, sum+grid[i][j], grid, k, dp);

        return dp[i][j][sum%k] = (up + left)%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(m-1, n-1, 0, grid, k, dp);
    }
};


int main(){
	Solution s;	
	vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
	cout << s.numberOfPaths(grid, 3) << endl;
}