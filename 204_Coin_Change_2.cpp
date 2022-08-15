/*
Coin_Change_2.cpp

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4

Example 2:
Input: amount = 3, coins = [2]
Output: 0

https://leetcode.com/problems/coin-change-2/
1. Recursion. TC: >>O(2^n) exponential, SC: O(target)
2. Memoisation. TC: O(N*K) SC: O(N*K) ASC: O(target)
3. Tabulation. TC: O(N*K) SC: O(N*K)
4. Space optimisation. TC: O(N*K) SC: O(K)
*/

// // 1. Recursion. TC: >>O(2^n) exponential, SC: O(target)
// int solve(int n, vector<int> &coins, int k) {
//     if(n == 0) {
//         return (k % coins[0] == 0);
//     }
    
//     int notake = solve(n-1, coins, k);
//     int take = 0;
//     if(coins[n] <= k) 
//         take = solve(n, coins, k - coins[n]);

//     return notake + take;
// }

// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     return solve(n-1, coins, amount);
// }


// // 2. Memoisation. TC: O(N*K) SC: O(N*K) ASC: O(target)
// int solve(int n, int k, vector<int> &coins, vector<vector<int>> &dp) {
//     if(n == 0) {
//         return (k % coins[0] == 0);
//     }
    
//     if(dp[n][k] != -1)
//     	return dp[n][k];

//     int notake = solve(n-1, k, coins, dp);
//     int take = 0;
//     if(coins[n] <= k) 
//         take = solve(n, k - coins[n], coins, dp);

//     return dp[n][k] = notake + take;
// }

// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount+1, -1)); 
//     return solve(n-1, amount, coins, dp);
// }


// // 3. Tabulation. TC: O(N*K) SC: O(N*K)
// int change(int k, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(k+1, 0)); 

//     for(int T=0; T<=k; T++) {
//         // if(k%coins[0] == 0) dp[0][i] = 1;
//         // else dp[0][i] = 1;
//         dp[0][T] = (T%coins[0] == 0);
//     }

//     for(int i=1; i<n; i++) {
//         for(int j=0; j<=k; j++) {
//             int notake = dp[i-1][j];
//             int take = 0;
//             if(coins[i] <= j)
//                 take = dp[i][j - coins[i]];

//             dp[i][j] = notake + take;
//         }
//     }

//     return dp[n-1][k];
// }


// 4. Space optimisation. TC: O(N*K) SC: O(K)
int change(int k, vector<int>& coins) {
    int n = coins.size();
    vector<int> prev(k+1, 0);
    vector<int> curr(k+1, 0);

    for(int T=0; T<=k; T++) {
        prev[T] = (T%coins[0] == 0);
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<=k; j++) {
            int notake = prev[j];
            int take = 0;
            if(coins[i] <= j)
                take = curr[j - coins[i]];

            curr[j] = notake + take;
        }
        prev = curr;
    }

    return prev[k];
}