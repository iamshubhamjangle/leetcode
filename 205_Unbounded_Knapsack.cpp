/*
Unbounded_Knapsack.cpp

You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.
For Example
Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }

https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029
*/

// // 1. Recursion. TC: >> O(2^n), SC: O(1), ASC: O(w)
// int solve(int n, int w, vector<int> &profit, vector<int> &weight) {
//     if(n == 0) {
//         if(weight[0] <= w) return profit[0]*(w/weight[0]);
//         else return 0;
//     }
    
//     int notake = 0 + solve(n-1, w, profit, weight);
//     int take = 0;
//     if(weight[n] <= w) take = profit[n] + solve(n, w-weight[n], profit, weight);
    
//     return max(take, notake);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
//     return solve(n-1, w, profit, weight);
// }



// // 2. Recursion. TC: >> O(2^n), SC: O(N*W), ASC: O(w)
// int solve(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
//     if(n == 0) {
//         if(weight[0] <= w) return profit[0]*(w/weight[0]);
//         else return 0;
//     }
    
//     if(dp[n][w] != -1)
//     	return dp[n][w];

//     int notake = 0 + solve(n-1, w, profit, weight, dp);
//     int take = 0;
//     if(weight[n] <= w) take = profit[n] + solve(n, w-weight[n], profit, weight, dp);
    
//     return dp[n][w] = max(take, notake);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
// 	vector<vector<int>> dp(n, vector<int>(w+1, -1));
//     return solve(n-1, w, profit, weight, dp);
// }


// // 3. Tabulation. TC: >> O(n*w), SC: O(N*W)
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
// 	vector<vector<int>> dp(n, vector<int>(w+1, 0));

// 	for(int i=0; i<=w; i++) {
// 		if(weight[0] <= i) dp[0][i] = profit[0]*(i/weight[0]);
// 		else dp[0][i] = 0;
// 	}

// 	for(int i=1; i<n; i++) {
// 		for(int j=0; j<=w; j++) {
// 			int notake = 0 + dp[i-1][j];
// 		    int take = 0;
// 		    if(weight[i] <= j) take = profit[i] + dp[i][j-weight[i]];
		    
// 		    dp[i][j] = max(take, notake);
// 		}
// 	}


//     return dp[n-1][w];
// }



// 4. Space Optimisation. TC: >> O(n*w), SC: O(w)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
	vector<int> prev(w+1, 0);
	vector<int> curr(w+1, 0);

	for(int i=0; i<=w; i++) {
		if(weight[0] <= i) prev[i] = profit[0]*(i/weight[0]);
		else prev[i] = 0;
	}

	for(int i=1; i<n; i++) {
		for(int j=0; j<=w; j++) {
			int notake = 0 + prev[j];
		    int take = 0;
		    if(weight[i] <= j) take = profit[i] + curr[j-weight[i]];
		    
		    curr[j] = max(take, notake);
		}
		prev = curr;
	}


    return prev[w];
}
