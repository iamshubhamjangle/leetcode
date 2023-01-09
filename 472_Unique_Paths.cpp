/*
Unique_Paths.cpp

https://leetcode.com/problems/unique-paths/description/
*/

class Solution {
public:
    // // Brute. TC: O(MN) SC: O(1) ASC: O(MN)
    // int solve(int i, int j) {
    //     if(i == 0 && j == 0) return 1;
    //     if(i < 0 || j < 0) return 0;

    //     int up   = solve(i-1, j);
    //     int left = solve(i, j-1);

    //     return up + left;
    // }

    // int uniquePaths(int m, int n) {
    //     return solve(m-1, n-1);
    // }


    // // Memo. TC: O(MN) SC: O(MN) ASC: O(MN)
    // int solve(int i, int j, vector<vector<int>> &dp) {
    //     if(i == 0 && j == 0) return 1;
    //     if(i < 0 || j < 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up   = solve(i-1, j, dp);
    //     int left = solve(i, j-1, dp);

    //     return dp[i][j] = up + left;
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return solve(m-1, n-1, dp);
    // }



    // Tabulation. TC: O(MN) SC: O(MN)
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // dp[0][0] = 1;
        // there can be only one solution for first row & col. we can only go to left
        // for(int i=1; i<m; i++) dp[i][0] = 1;
        // for(int j=1; j<n; j++) dp[0][j] = 1;

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                int up   = dp[i-1][j];
                int left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }

};













