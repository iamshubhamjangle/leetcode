/*
Number_of_Dice_Rolls_With_Target_Sum.cpp

https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
*/


// // 1. Recursion. TC: O(n*f) SC: O(1) ASC: O(n+f)
// class Solution {
// public:
// 	const int mod = 1e9+7;

// 	int solve(int n, int f, int target) {
//         if(n == 0 && target == 0) return 1;
//         if(n <= 0 || target <= 0) return 0;

//         if(dp[n][target] != -1)
//         	return dp[n][target];

//         int sum = 0;
//         for(int i=1; i<=f; i++) {
//         	int faceSum = solve(n-1, f, target-i)%mod;
//         	sum = sum%mod + faceSum;
//         }

//         return sum%mod;
// 	}


//     int numRollsToTarget(int n, int f, int target) {
//     	return solve(n, f, target);
//     }
// };


// // 2. Memoisation. TC: O(n) SC: O(n*f) ASC: O(n+f)
// class Solution {
// public:
// 	const int mod = 1e9+7;

// 	int solve(int n, int f, int target, vector<vector<int>> &dp) {
//         if(n == 0 && target == 0) return 1;
//         if(n <= 0 || target <= 0) return 0;

//         if(dp[n][target] != -1)
//         	return dp[n][target];

//         int sum = 0;
//         for(int i=1; i<=f; i++) {
//         	int faceSum = solve(n-1, f, target-i, dp)%mod;
//         	sum = sum%mod + faceSum;
//         }

//         return dp[n][target] = sum%mod;
// 	}


//     int numRollsToTarget(int n, int f, int target) {
//     	vector<vector<int>> dp(n+2, vector<int>(target+2, -1));
//     	return solve(n, f, target, dp);
//     }
// };