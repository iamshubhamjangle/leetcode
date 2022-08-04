/*
Subset_Sum_Equal_To_K.cpp

Input:
2
4 5
4 3 2 1
5 4
2 5 1 6 7

Output:
true
false

https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0
- Recursion. TC: O(2^n) SC: O(1) ASC: O(N)
- Memoisation. TC: O() SC: O(1) ASC: O(N)
- Tabulation. TC: O(N*K) SC: O(N*K)
- Space Optimisation. TC: O(N*K) SC: O(K)

*/
#include <bits/stdc++.h>
using namespace std;


// // Recursion. TC: O(2^n) SC: O(1) ASC: O(N)
// bool subsetSumToK(int n, int target, vector<int> &arr) {
// 	if(target == 0) return true;		// we have found a subset of sum k
// 	if(n == 0) return arr[0] == target;	// we reached base case is that the target?

// 	bool notTake = subsetSumToK(n-1, target, arr);	// not take decrease the index
// 	bool take 	 = false;	
// 	if(target >= arr[n])							// take only if curr element is <= target or else sum will get negative
// 		take = subsetSumToK(n-1, target - arr[n], arr);

// 	return take || notTake;
// }


// Memoisation. TC: O() SC: O(1) ASC: O(N)
// bool solve(int n, int target, vector<int> &arr, vector<vector<int>> &dp) {
// 	if(target == 0) return true;		// we have found a subset of sum k
// 	if(n == 0) return arr[0] == target;	// we reached base case is that the target?

// 	if(dp[n][target] != -1)
// 		return dp[n][target];

// 	bool notTake = solve(n-1, target, arr, dp);	// not take decrease the index
// 	bool take 	 = false;
// 	if(target >= arr[n])							// take only if curr element is <= target or else sum will get negative
// 		take = solve(n-1, target-arr[n], arr, dp);

// 	return dp[n][target] = take || notTake;
// }

// bool subsetSumToK(int n, int target, vector<int> &arr) {
// 	vector<vector<int>> dp(n, vector<int> (target+1, -1));
// 	return solve(n-1, target, arr, dp);
// }


// // Tabulation. TC: O(N*K) SC: O(N*K)
// bool subsetSumToK(int n, int k, vector<int> &arr) {
// 	// 1. declare dp
// 	vector<vector<bool>> dp(n, vector<bool> (k+1, false));

// 	// 2. Declare base cases
// 	for(int i=0; i<n; i++) dp[i][0] = true;		// if(target == 0) return true;
// 	if(arr[0] <= k) dp[0][arr[0]] = true;	// if(n == 0) return arr[0] == target;

// 	// 3. for the recurrance. fill dp idx, target grid
// 	for(int ind = 1; ind<n; ind++) {
// 		for(int target = 1; target <= k; target++) {
// 			bool notTake = dp[ind-1][target];
// 			bool take 	 = false;
// 			if(target >= arr[ind])							// take only if curr element is <= target or else sum will get negative
// 				take = dp[ind-1][target - arr[ind]];

// 			dp[ind][target] = take || notTake;
// 		}
// 	}

// 	return dp[n-1][k];
// }


// Space Optimisation. TC: O(N*K) SC: O(K)
bool subsetSumToK(int n, int k, vector<int> &arr) {
	// 1. declare dp
	vector<bool> prev(k+1, 0) ,cur(k+1, 0);

	// 2. Declare base cases
	prev[0] = cur[0] = true;
	prev[arr[0]] = true;

	// 3. for the recurrance. fill dp idx, target grid
	for(int ind = 1; ind<n; ind++) {
		for(int target = 1; target <= k; target++) {
			bool notTake = prev[target];
			bool take 	 = false;
			if(target >= arr[ind])							// take only if curr element is <= target or else sum will get negative
				take = prev[target - arr[ind]];

			cur[target] = take || notTake;
		}
		prev = cur;
	}

	return prev[k];
}


int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n,k; cin>>n>>k;
		vector<int> arr;
		for(int i=0; i<n; i++) {
			int x; cin >> x;
			arr.push_back(x);
		}
		cout << subsetSumToK(n, k+1, arr) << endl;	//run this 't' times
	}
}