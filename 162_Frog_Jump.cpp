/*
Frog_Jump.cpp

https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
1. Recursion TLE - TC: O(2^n) SC: O(1)
2. Memoisation TC: O(N) SC: O(N) 
3. Tabulation TC: O(N) SC: O(N)
4. Space Optimized TC: O(N) SC: O(1)

*/


#include <bits/stdc++.h>
using namespace std;

// 1. Recursion TLE - TC: O(2^n) SC: O(1) + stack space
// int helper(int n, vector<int> &heights) {
//     if(n == 0) return 0;

//     int l = helper(n-1, heights) + abs(heights[n] - heights[n-1]);
	
// 	int r = INT_MAX;
// 	if(n > 1) 
// 		r = helper(n-2, heights) + abs(heights[n] - heights[n-2]);

//     return min(l,r);
// }

// int frogJump(int n, vector<int> &heights) {
// 	return helper(n-1, heights);
// }


// // 2. Memoisation TC: O(N) SC: O(N) 
// int helper(int n, vector<int> &heights, vector<int> &dp) {
//     if(n == 0) return 0;

//     if(dp[n] != -1)
//     	return dp[n];

//     int l = helper(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
	
// 	int r = INT_MAX;
// 	if(n > 1) 
// 		r = helper(n-2, heights, dp) + abs(heights[n] - heights[n-2]);

//     return dp[n] = min(l,r);
// }

// int frogJump(int n, vector<int> &heights) {
// 	vector<int> dp(n+1, -1);
// 	return helper(n-1, heights, dp);
// }


// // 3. Tabulation TC: O(N) SC: O(N)
// int frogJump(int n, vector<int> &heights) {
// 	vector<int> dp(n, -1);

// 	dp[0] = 0;

// 	for(int i=1; i<n; i++) {
// 		int l = dp[i-1] + abs(heights[i] - heights[i-1]);
// 		int r = INT_MAX;

// 		if(i>1)
// 			r = dp[i-2] + abs(heights[i] - heights[i-2]);

// 		dp[i] = min(l,r);
// 	}

// 	return dp[n-1];
// }

// 4. Space Optimized TC: O(N) SC: O(1)
int frogJump(int n, vector<int> &heights) {
	int prev0 = 0;
	int prev1 = 0;

	for(int i=1; i<n; i++) {
		int l = prev1 + abs(heights[i] - heights[i-1]);
		int r = INT_MAX;

		if(i>1)
			r = prev0 + abs(heights[i] - heights[i-2]);

		int curr = min(l,r);
		prev0 = prev1;
		prev1 = curr;
	}

	return prev1;
}

int main(){
	vector<int> heights;
	heights = {10, 20, 30, 10};
	cout << frogJump(4, heights);
	cout << endl;
	heights = {10, 50, 10};
	cout << frogJump(3, heights);
}




