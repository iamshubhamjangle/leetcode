/*

Frog_Jump_with_k_Distances.cpp
1. Recursive. TC: O(K^N) SC: O(N - stack space)
2. Memoization. TC: O(K*N) SC: O(N)
3. Tabulation. TC: O(K*N) SC: O(N)

*/
#include <bits/stdc++.h>
using namespace std;


// // 1. Recursive. TC: O(K^N) SC: O(N - stack space)
// int helper(int n, int k, vector<int> &heights) {
// 	if(n == 0) return 0;

// 	int minSteps = INT_MAX;

// 	for(int j=1; j<=k; j++) {
// 		int l = INT_MAX;
// 		if(n-j >= 0)
// 			l = helper(n-j, k, heights) + abs(heights[n] - heights[n-j]);
// 		minSteps = min(minSteps, l);
// 	}

// 	return minSteps;
// }

// int frogKJump(int n, int k, vector<int> &heights) {
// 	return helper(n-1, k, heights);
// }


// // 2. Memoization. TC: O(K*N) SC: O(N)
// int helper(int n, int k, vector<int> &heights, vector<int> &dp) {
// 	if(n == 0) return 0;

// 	if(dp[n] != -1) return dp[n];

// 	int minSteps = INT_MAX;

// 	for(int j=1; j<=k; j++) {
// 		int l = INT_MAX;
// 		if(n-j >= 0)
// 			l = helper(n-j, k, heights, dp) + abs(heights[n] - heights[n-j]);
// 		minSteps = min(minSteps, l);
// 	}

// 	return dp[n] = minSteps;
// }

// int frogKJump(int n, int k, vector<int> &heights) {
// 	vector<int> dp(n+1, -1);
// 	return helper(n-1, k, heights, dp);
// }


// 3. Tabulation. TC: O(K*N) SC: O(N)
int frogKJump(int n, int k, vector<int> &heights) {
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	for(int i=1; i<n; i++) {
		int minSteps = INT_MAX;
		for(int j=1; j<=k; j++) {
			if(i-j >= 0) {
				int l = dp[i-j] + abs(heights[i] - heights[i-j]);
				minSteps = min(minSteps, l);
			}
		}
		dp[i] = minSteps;
	}

	return dp[n-1];
}

int main(){
	vector<int> heights;
	heights = {10, 20, 30, 10};
	cout << frogKJump(4, 2, heights);
	cout << endl;
	heights = {10, 50, 10};
	cout << frogKJump(3, 2, heights);
}
