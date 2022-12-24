/*
Domino_and_Tromino_Tiling.cpp

https://leetcode.com/problems/domino-and-tromino-tiling/description/
*/

// Brute
// class Solution {
// public:
//     const int MOD = 1e9+7;
//     int numTilings(int n, bool previousGap = false) {
//         if(n < 0) return 0;
//         if(n == 0) return !previousGap;
//         if(previousGap)
//             return (numTilings(n-1) + numTilings(n-1, true)) % MOD;
//         return (numTilings(n-1) + numTilings(n-2) + 2l*numTilings(n-2, true)) % MOD;
//     }
// };


// Memoisation
class Solution {
public:
    const int MOD = 1e9+7;
    int dp[1001][2]{};
    int numTilings(int n, bool previousGap = false) {
        if(n < 0) return 0;
        if(n == 0) return !previousGap;
        if(dp[n][previousGap]) return dp[n][previousGap];
        if(previousGap)
            return dp[n][previousGap] = (numTilings(n-1) + numTilings(n-1, true)) % MOD;
        return dp[n][previousGap] = (numTilings(n-1) + numTilings(n-2) + 2l*numTilings(n-2, true)) % MOD;
    }
};