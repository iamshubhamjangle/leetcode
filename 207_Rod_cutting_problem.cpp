/*
Rod_cutting_problem.cpp

Given a rod of length ‘N’ units. The rod can be cut into different sizes and each 
size has a cost associated with it. Determine the maximum cost obtained by cutting 
the rod and selling its pieces.

Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20

Output 1:
12
24

https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

*/

#include <bits/stdc++.h>
using namespace std;

// // 1. Recursion. TC: O(exponential) SC: O(1) ASC: O(N)
// int solve(int ind, int N, vector<int> &price) {
// 	if(ind == 0) {
// 		return N * price[0];
// 	}


// 	int notake = 0 + solve(ind-1, N, price);
// 	int take = INT_MIN;
// 	int rodLength = ind + 1;
// 	if(rodLength <= N) {
// 		take = price[ind] + solve(ind, N - rodLength, price);
// 	}

// 	return max(take, notake);
// }

// int cutRod(vector<int> &price, int n) {
//    	return solve(n-1, n, price);
// }



// // 2. Memoisation. TC: O(N*N) SC: O(N*N) ASC: O(N)
// int solve(int ind, int N, vector<int> &price, vector<vector<int>> &dp) {
// 	if(ind == 0) {
// 		return N * price[0];
// 	}

// 	if(dp[ind][N] != -1)
// 		return dp[ind][N];

// 	int notake = 0 + solve(ind-1, N, price, dp);
// 	int take = INT_MIN;
// 	int rodLength = ind + 1;
// 	if(rodLength <= N) {
// 		take = price[ind] + solve(ind, N - rodLength, price, dp);
// 	}

// 	return dp[ind][N] = max(take, notake);
// }

// int cutRod(vector<int> &price, int n) {
// 	vector<vector<int>> dp(n, vector<int> (n+1, -1));
//    	return solve(n-1, n, price, dp);
// }




// // 3. Tabulation. TC: O(N*N) SC: O(N*N)
// int cutRod(vector<int> &price, int n) {
// 	vector<vector<int>> dp(n, vector<int> (n+1, 0));

// 	for(int N=0; N<=n; N++) {
// 		dp[0][N] = N * price[0];
// 	}

// 	for(int ind=1; ind<n; ind++) {
// 		for(int N=0; N<=n; N++) {
// 			int notake = 0 + dp[ind-1][N];
// 			int take = INT_MIN;
// 			int rodLength = ind + 1;
// 			if(rodLength <= N) {
// 				take = price[ind] + dp[ind][N - rodLength];
// 			}

// 			dp[ind][N] = max(take, notake);
// 		}
// 	}

//    	return dp[n-1][n];
// }




// // 4. Space Optimisation. TC: O(N*N) SC: O(2N)
// int cutRod(vector<int> &price, int n) {
// 	vector<int> prev(n+1, 0);
// 	vector<int> curr(n+1, 0);

// 	for(int N=0; N<=n; N++) {
// 		prev[N] = N * price[0];
// 	}

// 	for(int ind=1; ind<n; ind++) {
// 		for(int N=0; N<=n; N++) {
// 			int notake = 0 + prev[N];
// 			int take = INT_MIN;
// 			int rodLength = ind + 1;
// 			if(rodLength <= N) {
// 				take = price[ind] + curr[N - rodLength];
// 			}

// 			curr[N] = max(take, notake);
// 		}
// 		prev = curr;
// 	}

//    	return prev[n];
// }




// 4. Space Optimisation. TC: O(N*N) SC: O(1N)
int cutRod(vector<int> &price, int n) {
	vector<int> prev(n+1, 0);
	// vector<int> curr(n+1, 0);	// --

	for(int N=0; N<=n; N++) {
		prev[N] = N * price[0];
	}

	for(int ind=1; ind<n; ind++) {
		for(int N=0; N<=n; N++) {
			int notake = 0 + prev[N];
			int take = INT_MIN;
			int rodLength = ind + 1;
			if(rodLength <= N) {
				take = price[ind] + prev[N - rodLength];	// take = price[ind] + curr[N - rodLength];
			}

			prev[N] = max(take, notake);	// curr[N] = max(take, notake);
		}
		// prev = curr;		// --
	}

   	return prev[n];
}


int main(){
	vector<int> price; 
	int n;

	n = 5;
	price = {2, 5, 7, 8, 10};
	cout << cutRod(price, n) << endl;

	n = 8;
	price = {3, 5, 8, 9, 10, 17, 17, 20};
	cout << cutRod(price, n) << endl;
}