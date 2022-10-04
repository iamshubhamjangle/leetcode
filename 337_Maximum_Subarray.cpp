/*
Maximum_Subarray.cpp

https://leetcode.com/problems/maximum-subarray/
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Bruteforce. TC: O(N*N) SC: O(1)
// find each subarray, sum it. keep track of the max sum. Return the max sum.


// // 2. Recursion. TC: O(N*N) ASC: O(N)
// class Solution {
// public:
//     int solve(int i, bool mustPick, int n, vector<int> &nums) {
// 		// If we are at below first index
// 		if(i < 0) {
// 			return mustPick ? 0 : INT_MIN;
// 		}

// 		int pick = nums[i] + solve(i-1, true, n, nums);
// 		int notPick = 0;
// 		if(!mustPick) 
// 			notPick = 0 + solve(i-1, false, n, nums);
// 		return max(pick, notPick);
// 	}

//     int maxSubArray(vector<int>& nums) {
// 		int n = nums.size();
// 		int startFrom = n-1;
// 		bool mustPick = false;
// 		return solve(startFrom, mustPick, n, nums);
//     }
// };


// // 3. Memoisation.
// class Solution {
// public:
//     int solve(int i, bool mustPick, int n, vector<int> &nums, vector<vector<int>> &dp) {
// 		// If we are at below first index
// 		if(i < 0) {
// 			return mustPick ? 0 : INT_MIN;
// 		}

// 		if(dp[i][mustPick] != -1)
// 			return dp[i][mustPick];

// 		int pick = nums[i] + solve(i-1, true, n, nums, dp);
// 		int notPick = 0;
// 		if(!mustPick) 
// 			notPick = 0 + solve(i-1, false, n, nums, dp);
// 		return dp[i][mustPick] = max(pick, notPick);
// 	}

//     int maxSubArray(vector<int>& nums) {
// 		int n = nums.size();
// 		int startFrom = n-1;
// 		bool mustPick = false;
// 		vector<vector<int>> dp(n, vector<int>(2, -1));
// 		return solve(startFrom, mustPick, n, nums, dp);
//     }
// };


/// NOT WORKING
// // Tabulation
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if(n == 0) return 0;

		vector<vector<int>> dp(n+1, vector<int>(2, -1));

		dp[0][0] = nums[0];
		dp[0][1] = nums[0];

		for(int i=1; i<n; i++) {
			for(int mustPick=0; mustPick<=1; mustPick++) {
				int pick = nums[i] + dp[i-1][1];
				int notPick = 0;
				if(!mustPick) 
					notPick = 0 + dp[i-1][0];

				dp[i][mustPick] = max(pick, notPick);
			}
		}

		return dp[n-1][0];
    }
};



/// Kadanes Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MAX = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            MAX = max(sum, MAX);
            if(sum < 0) sum = 0;
        }
        return MAX;
    }
};

int main(){
	vector<int> nums;
	Solution s;

	nums = {-2,1,-3,4,-1,2,1,-5,4};	// 6
	cout << s.maxSubArray(nums) << endl;

	nums = {1};						// 1
	cout << s.maxSubArray(nums) << endl;
	
	nums = {5,4,-1,7,8};			// 23
	cout << s.maxSubArray(nums) << endl;
	
}