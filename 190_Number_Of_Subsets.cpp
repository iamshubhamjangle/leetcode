/*
Number_Of_Subsets.cpp

Input:
4
4 3
1 2 2 3
2 3
1 2
3 4
12 1 3
2 41
2 34

Output:
3
1
1
0

https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532


*/

#include <bits/stdc++.h>
using namespace std;

// // Recursion. TC: O(2^n) SC: O(1) ASC: O(N)
// int solve(vector<int> &num, int sum, int ind) {
// 	if(ind == 0) {
// 		if(sum == 0 && num[ind] == 0) return 2;
// 		if(sum == 0 || num[ind] == sum) return 1;
// 		return 0;
// 	}

// 	int notake = solve(num, sum, ind-1);
// 	int take = 0;
// 	if(num[ind] <= sum) take = solve(num, sum - num[ind], ind-1);

// 	return take + notake;
// }

// int findWays(vector<int> &num, int tar) {
// 	int n = num.size();
// 	return solve(num, tar, n-1);
// }


// // Memoisation. TC: O(N*target) SC: O(N*target) ASC: O(N)
// int solve(int ind, int sum, vector<int> &num, vector<vector<int>> &dp) {
// 	if(ind == 0) {
// 		if(sum == 0 && num[ind] == 0) return 2;
// 		if(sum == 0 || num[ind] == sum) return 1;
// 		return 0;
// 	}

// 	if(dp[ind][sum] != -1) return dp[ind][sum];

// 	int notake = solve(ind-1, sum, num, dp);
// 	int take = 0;
// 	if(num[ind] <= sum) take = solve(ind-1, sum - num[ind], num, dp);

// 	return dp[ind][sum] = take + notake;
// }

// int findWays(vector<int> &num, int tar) {
// 	int n = num.size();
// 	vector<vector<int>> dp(n, vector<int> (tar+1, -1));
// 	return solve(n-1, tar, num, dp);
// }


// // Tabulation. Top-Down - 0 to n-1. TC: O(N*target) SC: O(N*target)
// int findWays(vector<int> &num, int sum) {
// 	int n = num.size();
// 	vector<vector<int>> dp(n, vector<int> (sum+1, 0));

// 	if(num[0] == 0) dp[0][0] = 2;	// if(ind == 0) { if(sum == 0 && num[ind] == 0) return 2; }
// 	else dp[0][0] = 1;				// if(ind == 0) { sum == 0 || num[ind] == sum } return 1; }

// 	if(num[0] != 0 && num[0] <= sum) dp[0][num[0]] = 1;

// 	for(int ind=1; ind<n; ind++) {
// 		for(int j=0; j<=sum; j++) {
// 			int notake = dp[ind-1][j];
// 			int take = 0;
// 			if(num[ind] <= j) take = dp[ind-1][j - num[ind]];

// 			dp[ind][j] = take + notake;
// 		}
// 	}

// 	return dp[n-1][sum];
// }



// Space Optimisation. TC: O(N*target) SC: O(target)
int findWays(vector<int> &num, int sum) {
	int n = num.size();
	vector<int> prev(sum+1, 0), curr(sum+1, 0);

	if(num[0] == 0) prev[0] = 2;	// if(ind == 0) { if(sum == 0 && num[ind] == 0) return 2; }
	else prev[0] = 1;				// if(ind == 0) { sum == 0 || num[ind] == sum } return 1; }

	if(num[0] != 0 && num[0] <= sum) prev[num[0]] = 1;

	for(int ind=1; ind<n; ind++) {
		for(int j=0; j<=sum; j++) {
			int notake = prev[j];
			int take = 0;
			if(num[ind] <= j) take = prev[j - num[ind]];

			curr[j] = take + notake;
		}
		prev = curr;
	}

	return prev[sum];
}




int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n, s; cin >> n >> s;
		vector<int> num;
		for(int i=0; i<n; i++) {
			int x; cin>>x;
			num.push_back(x);
		}
		cout << findWays(num, s) << endl;
	}
}
