/*
Triangle.cpp

Input:
2
4
2 
3 4
6 5 7
4 1 8 3
1
-10 

Output:
11
-10

https://www.codingninjas.com/codestudio/problems/triangle_1229398
Recursion - DP.

*/

#include <bits/stdc++.h>
using namespace std;

// // Recursion. TC: O(2^(n*n)) SC: O(1) ASC: O(N)
// int solve(int i, int j, vector<vector<int>> &arr, int n) {
//     if(i == n-1)
//         return arr[i][j];
    
//     int down = arr[i][j] + solve(i+1, j, arr, n);
//     int diag = arr[i][j] + solve(i+1, j+1, arr, n);
    
//     return min(down, diag);
// }

// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	return solve(0, 0, triangle, n);
// }


// // Memoisation. TC: O(n*n) SC: O(N*N) ASC: O(N)
// int solve(int i, int j, vector<vector<int>> &arr, int n, vector<vector<int>> &dp) {
//     if(i == n-1)
//         return arr[i][j];
    
//     if(dp[i][j] != -1)
//     	return dp[i][j];

//     int down = arr[i][j] + solve(i+1, j, arr, n, dp);
//     int diag = arr[i][j] + solve(i+1, j+1, arr, n, dp);
    
//     return dp[i][j] = min(down, diag);
// }

// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	vector<vector<int>> dp(n, vector<int>(n,-1));
// 	return solve(0, 0, triangle, n, dp);
// }


// // Tabulation. TC: O(n*n) SC: O(N*N)
// int minimumPathSum(vector<vector<int>>& arr, int n){
// 	vector<vector<int>> dp(n, vector<int>(n,0));
	
// 	for(int j=0; j<n; j++) {			// base case
// 		dp[n-1][j] = arr[n-1][j];
// 	}

// 	for(int i=n-2; i>=0; i--) {
// 		for(int j=i; j>=0; j--) {
// 			int down = arr[i][j] + dp[i+1][j];
// 			int diag = arr[i][j] + dp[i+1][j+1];

// 			dp[i][j] = min(down, diag);
// 		}
// 	}

// 	return dp[0][0];
// }


// Space optimisation. TC: O(n*n) SC: O(N)
int minimumPathSum(vector<vector<int>>& arr, int n){
	vector<int> front(n,0), curr(n,0);

	for(int j=0; j<n; j++) {			// base case
		front[j] = arr[n-1][j];
	}

	for(int i=n-2; i>=0; i--) {
		for(int j=i; j>=0; j--) {
			int down = arr[i][j] + front[j];
			int diag = arr[i][j] + front[j+1];

			curr[j] = min(down, diag);
		}
		front = curr;
	}

	return front[0];
}

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n; cin >> n;
		vector<vector<int>> triangle;

		for(int i=1; i<=n; i++) {
			vector<int> temp;
			for(int j=1; j<=i; j++) {
				int x; cin >> x;
				temp.push_back(x);
			}	
			triangle.push_back(temp);
		}

		cout << minimumPathSum(triangle, n) << endl;
	}
}
