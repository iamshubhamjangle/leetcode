/*
Unique_Paths.cpp

https://leetcode.com/problems/unique-paths/
*/

class Solution {
public:
// // Recursion. 
//     int solve(int i, int j) {
//      if(i == 0 && j == 0)
//          return 1;
//      if(i < 0 || j < 0)
//          return 0;

//      int ans = 0;
//      ans += solve(i-1, j);
//      ans += solve(i, j-1);

//      return ans;
//     }
    
//     int uniquePaths(int m, int n) {
//         return solve(m-1, n-1);
//     }


//  // Memo. 
//     int solve(int i, int j, vector<vector<int>> &dp) {
//      if(i == 0 && j == 0)
//          return 1;
//      if(i < 0 || j < 0)
//          return 0;

//      if(dp[i][j] != -1)
//          return dp[i][j];

//      int ans = 0;
//      ans += solve(i-1, j, dp);
//      ans += solve(i, j-1, dp);

//      return dp[i][j] = ans;
//     }
    
//     int uniquePaths(int m, int n) {
//      vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solve(m-1, n-1, dp);
//     }
    
    
    // Tabulation. 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                int ans = 0;
                ans += dp[i-1][j];
                ans += dp[i][j-1];
                dp[i][j] = ans;
            }
        }

        return dp[m-1][n-1];
    }   
};