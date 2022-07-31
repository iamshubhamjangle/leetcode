/*
Maximum_sum_of_non-adjacent_elements.cpp
Example 1:
Input:
4
3
1 2 4
4
2 1 4 9
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9

Output:
5
11
8
24

Example 2:
Input:
4
4
9 9 8 2
4
8 5 8 8
4
5 8 7 2
4
3 10 10 7

Output:
17
16
12
17


https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
1. Recursion	 : TC: O(2^n) SC: O(1) ASC: O(N)
2. Memoization: TC: O(N) SC: O(N) ASC: O(N)
3. Tabulation : TC: O(N) SC: O(N)
4. SpaceOptimized: TC: O(N) SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// ********************************************* //
// 1. Recursion. TC: O(2^n) SC: O(1) ASC: O(N)
// int solve(int i, vector<int> &nums) {
//     if(i >= nums.size()) 
//         return 0;
    
//     int take = solve(i+2, nums) + nums[i];
//     int notake = solve(i+1, nums);
//     return max(take, notake);
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     return solve(0, nums);
// }

// ********************************************* //
// 1. Recursion. TC: O(2^n) SC: O(1) ASC: O(N)
// int solve(int i, vector<int> &nums) {
//     if(i == 0) return nums[i];
//     if(i < 0) return 0;
    
//     int take   = solve(i-2, nums) + nums[i];
//     int notake = solve(i-1, nums) + 0;
//     return max(take, notake);
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     return solve(0, nums);
// }


// ********************************************* //
// Memoization. Method 2:  TC: O(N) SC: O(N) ASC: O(N)
// int solve(int i, vector<int> &nums, vector<int> &dp) {
//		if(i < 0)
//			return 0;

//     if(i == 0) 
//         return nums[0];
    
//     if(dp[i] != -1) {
//     	return dp[i];
//     }

//     int take = solve(i-2, nums, dp) + nums[i];
//     int notake = solve(i-1, nums, dp);
//     return dp[i] = max(take, notake);
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return solve(n-1, nums, dp);
// }


// ********************************************* //
// Tabulation - Method 2: Topdown. TC: O(N) SC: O(N)
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n, 0);

//     dp[0] = nums[0];
//     dp[1] = max(nums[0], nums[1]);

//     for(int i=2; i<n; i++) {
//     	int take   = dp[i-2] + nums[i];
//     	int notake = dp[i-1] + 0;
//     	dp[i] = max(take, notake);
//     }

//     return dp[n-1];
// }


// ********************************************* //
// Space optimization - Method 2: Topdown.
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();

//     int prev1 = nums[0];
//     int prev2 = nums[1];

//     for(int i=2; i<n; i++) {
//     	int take = prev1 + nums[i];
//     	int notake = prev2 + 0;
//     	int ans = max(take, notake);

//     	prev1 = prev2;
//     	prev2 = ans;
//     }

//     return prev2;
// }



int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n;
		cin >> n;
		vector<int> nums;
		for(int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			nums.push_back(temp);
		}
		cout << maximumNonAdjacentSum(nums) << endl;
	}
}
