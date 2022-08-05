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


// // Memoisation. TC: O(N*target) SC: O(N) ASC: O(N)
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
