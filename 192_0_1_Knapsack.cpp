/*
0_1_Knapsack.cpp

Sample Input:
1 
4
1 2 4 5
5 4 8 6
5

Sample Output:
13

https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542
- Recursion TC: O(2^n), SC: O(1) ASC: O(N) 
- Memoization. TC: O(n*maxWeight), SC: O(n*maxWeight) ASC: O(N) 
- Tabulation. TC: O(n*maxWeight), SC = O(N*maxWeight)
- Space Optimisation. TC: O(n*maxWeight), SC = O(maxWeight)

*/

#include <bits/stdc++.h>
using namespace std;

// // Recursion TC: O(2^n), SC: O(1) ASC: O(N) 
// int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)  {
// 	// if we are first index
// 	if(n == 0) {
// 		if(weight[0] <= maxWeight)
// 			return value[0];	// weight is under our capicity
// 		else 
// 			return 0;			// weight exceeds the our capacity
// 	}


// 	int notTake = 0 + knapsack(weight, value, n-1, maxWeight);
// 	int take    = INT_MIN;
// 	if(weight[n] <= maxWeight) take = value[n] + knapsack(weight, value, n-1, maxWeight - weight[n]);

// 	return max(notTake, take);
// }


// // Memoization. TC: O(2^n), SC: O(1) ASC: O(N) 
// int solve(int n, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)  {
// 	// if we are first index
// 	if(n == 0) {
// 		if(weight[0] <= maxWeight)
// 			return value[0];	// weight is under our capicity
// 		else 
// 			return 0;			// weight exceeds the our capacity
// 	}

// 	if(dp[n][maxWeight] != -1)
// 		return dp[n][maxWeight];

// 	int notTake = 0 + solve(n-1, maxWeight, weight, value, dp);
// 	int take    = INT_MIN;
// 	if(weight[n] <= maxWeight) take = value[n] + solve(n-1, maxWeight - weight[n], weight, value, dp);

// 	return dp[n][maxWeight] = max(notTake, take);
// }

// int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)  {
// 	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
// 	return solve(n-1, maxWeight, weight, value, dp);
// }


// // Tabulation. TC: O(n*maxWeight), SC = O(N*maxWeight)
// int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)  {
// 	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
	
// 	for(int W = weight[0]; W <= maxWeight; W++) dp[0][W] = value[0];

// 	for(int ind=1; ind < n; ind++) {
// 		for(int W=0; W <= maxWeight; W++) {
// 			int notTake = 0 + dp[ind-1][W];
// 			int take    = INT_MIN;
// 			if(weight[ind] <= W) take = value[ind] + dp[ind-1][W - weight[ind]];

// 			dp[ind][W] = max(notTake, take);			
// 		}
// 	}

// 	return dp[n-1][maxWeight];
// }

// // Space Optimisation. TC: O(n*maxWeight), SC = O(maxWeight)
// int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)  {
// 	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
	
// 	for(int W = weight[0]; W <= maxWeight; W++) prev[W] = value[0];

// 	for(int ind=1; ind < n; ind++) {
// 		for(int W=0; W <= maxWeight; W++) {
// 			int notTake = 0 + prev[W];
// 			int take    = INT_MIN;
// 			if(weight[ind] <= W) take = value[ind] + prev[W - weight[ind]];

// 			curr[W] = max(notTake, take);
// 		}
// 		prev = curr;
// 	}

// 	return prev[maxWeight];
// }


// Double Space Optimisation. TC: O(n*maxWeight), SC = O(maxWeight)
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)  {
	vector<int> prev(maxWeight+1, 0);
	
	for(int W = weight[0]; W <= maxWeight; W++) prev[W] = value[0];

	for(int ind=1; ind < n; ind++) {
		for(int W=maxWeight; W >= 0; W--) {
			int notTake = 0 + prev[W];
			int take    = INT_MIN;
			if(weight[ind] <= W) take = value[ind] + prev[W - weight[ind]];

			prev[W] = max(notTake, take);
		}
	}

	return prev[maxWeight];
}

int main(){
	// int t;
	// cin >> t;		//input no. of test cases
	// while(t--){
		int n = 4;
		vector<int> weight = {1,2,4,5};
		vector<int> value = {5,4,8,6};
		int maxWeight = 5;
		
		cout << knapsack(weight, value, n, maxWeight) << endl;
	// }
}
