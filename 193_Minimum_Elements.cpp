/*
Minimum_Elements.cpp

Input:
2
3 7
1 2 3
1 0
1

Output:
3
0

https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091
1. Recursion. TC: >> O(2^n) SC: O(1) ASC: O(N)
2. Memoisation. TC: O(N*t) SC: O(N*t) ASC: O(N)
3. Tabulation. TC: O(N*t) SC: O(N*t)
4. Space Optimisation. TC: O(N*t) SC: O(N)

*/

/*
- infinite supply
- multiple use
in these cases keep the index of take call to be same.
*/

#include <bits/stdc++.h>
using namespace std;


// // 1. Recursion. TC: >> O(2^n) SC: O(1) ASC: O(N)
// int solve(int i, vector<int> &num, int t) {
// 	if(i == 0) {
// 		if(t % num[0] == 0) return t/num[0];	// If target is multiple of num[i]; take those many times.
// 		else return 1e9;
// 	}

// 	int notake = 0 + solve(i-1, num, t);
// 	int take = 1e9;
// 	if(num[i] <= t) take   = 1 + solve(i, num, t - num[i]);

// 	return min(take, notake);
// }

// int minimumElements(vector<int> &num, int t) {
// 	int n = num.size();
// 	int ans = solve(n-1, num, t);	// return the minimum no of coins req to get to target.
// 	if(ans >= 1e9) return -1;
// 	else return ans;
// }


// // 2. Memoisation. TC: O(N*t) SC: O(N*t) ASC: O(N)
// int solve(int i, vector<int> &num, int t, vector<vector<int>> &dp) {
// 	if(i == 0) {
// 		if(t % num[0] == 0) return t/num[0];	// If target is multiple of num[i]; take those many times.
// 		else return 1e9;
// 	}

// 	if(dp[i][t] != -1) 
// 		return dp[i][t];

// 	int notake = 0 + solve(i-1, num, t, dp);
// 	int take = 1e9;
// 	if(num[i] <= t) take   = 1 + solve(i, num, t - num[i], dp);

// 	return dp[i][t] = min(take, notake);
// }

// int minimumElements(vector<int> &num, int t) {
// 	int n = num.size();
// 	vector<vector<int>> dp(n, vector<int> (t+1, -1));
// 	int ans = solve(n-1, num, t, dp);	// return the minimum no of coins req to get to target.
// 	if(ans >= 1e9) return -1;
// 	else return ans;
// }


// // 3. Tabulation. TC: O(N*t) SC: O(N*t)
// int minimumElements(vector<int> &num, int target) {
// 	int n = num.size();
// 	vector<vector<int>> dp(n, vector<int> (target+1, 0));

// 	for(int t=0; t<=target; t++) {
// 		if(t%num[0] == 0) 
// 			dp[0][t] = t/num[0];
// 		else
// 			dp[0][t] = 1e9;
// 	}

// 	for(int i=1; i<n; i++) {
// 		for(int t=0; t<=target; t++) {
// 			int notake = 0 + dp[i-1][t];
// 			int take = 1e9;
// 			if(num[i] <= t) take   = 1 + dp[i][t - num[i]];

// 			dp[i][t] = min(take, notake);
// 		}
// 	}

// 	int ans = dp[n-1][target];
// 	if(ans >= 1e9) return -1;
// 	else return ans;
// }


// 4. Space Optimisation. TC: O(N*t) SC: O(N)
int minimumElements(vector<int> &num, int target) {
	int n = num.size();
	vector<int> prev(target+1, 0);
	vector<int> curr(target+1, 0);

	for(int t=0; t<=target; t++) {
		if(t%num[0] == 0) 
			prev[t] = t/num[0];
		else
			prev[t] = 1e9;
	}

	for(int i=1; i<n; i++) {
		for(int t=0; t<=target; t++) {
			int notake = 0 + prev[t];
			int take = 1e9;
			if(num[i] <= t) take   = 1 + curr[t - num[i]];

			curr[t] = min(take, notake);
		}
		prev = curr;
	}

	int ans = prev[target];
	if(ans >= 1e9) return -1;
	else return ans;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, t;
		cin >> n >> t;
		vector<int> num;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			num.push_back(x);
		}
		cout << minimumElements(num, t) << endl;
	}
}

