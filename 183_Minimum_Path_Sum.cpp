/*
Minimum_Path_Sum.cpp

# When there is no uniformnity we cannot apply greedy. As our todays decision can lead to future loss.

# Better to go with Recursion -> dp
1. Express in index
2. Explore all path
3. Take the min path
*/
/*
Minimum Path Sum

Input :
2
2 3
5 9 6
11 5 2
1 1
5

Output:
21
5

https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349
Recursion - DP
*/

#include <bits/stdc++.h>
using namespace std;


// // Recursion. TC: O(2^(m*n)) SC: O(1) ASC: O((n-1)+(m-1))
// int solve(int i, int j, vector<vector<int>> &grid) {
// 	if(i == 0 && j == 0) {
// 		return grid[i][j];
// 	}

// 	if(i<0 || j<0) {
// 		return 1e9;
// 	}

// 	int left = grid[i][j] + solve(i, j-1, grid);
// 	int up   = grid[i][j] + solve(i-1, j, grid);

// 	return min(left, up);
// }

// int minSumPath(vector<vector<int>> &grid) {
// 	int n = grid.size();
// 	int m = grid[0].size();
//     return solve(n-1, m-1, grid);
// }


// // Memoization. TC: O(m*n) SC: O(M*N) ASC: O((n-1)+(m-1))
// int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
// 	if(i == 0 && j == 0) {
// 		return grid[i][j];
// 	}

// 	if(i<0 || j<0) {
// 		return 1e9;
// 	}

// 	if(dp[i][j] != -1) return dp[i][j];

// 	int left = grid[i][j] + solve(i, j-1, grid, dp);
// 	int up   = grid[i][j] + solve(i-1, j, grid, dp);

// 	return dp[i][j] = min(left, up);
// }

// int minSumPath(vector<vector<int>> &grid) {
// 	int n = grid.size();
// 	int m = grid[0].size();
// 	vector<vector<int>> dp(n, vector<int>(m, -1));

//     return solve(n-1, m-1, grid, dp);
// }



// // Tabulation. TC: O(m*n) SC: O(M*N)
// int minSumPath(vector<vector<int>> &grid) {
// 	int n = grid.size();
// 	int m = grid[0].size();
// 	vector<vector<int>> dp(n, vector<int>(m, -1));


// 	for(int i=0; i<n; i++) {
// 		for(int j=0; j<m; j++) {
// 			if(i==0 && j==0)
// 				dp[0][0] = grid[0][0];
// 			else {
// 				int left = grid[i][j];
// 				if(j>0) left += dp[i][j-1];
// 				else left += 1e9;

// 				int up   = grid[i][j];
// 				if(i>0) up   += dp[i-1][j];
// 				else up += 1e9;

// 				dp[i][j] = min(left, up);
// 			}
// 		}
// 	}

//     return dp[n-1][m-1];
// }



// Space optimization. TC: O(m*n) SC: O(1)
int minSumPath(vector<vector<int>> &grid) {
	int n = grid.size();
	int m = grid[0].size();
	
	vector<int> prev(m, 0);
	for(int i=0; i<n; i++) {
		vector<int> temp(m, 0);
		for(int j=0; j<m; j++) {
			if(i==0 && j==0)
				temp[j] = grid[0][0];
			else {
				int left = grid[i][j];
				if(j>0) left += temp[j-1];
				else left += 1e9;

				int up   = grid[i][j];
				if(i>0) up   += prev[j];
				else up += 1e9;

				temp[j] = min(left, up);
			}
		}
		prev = temp;
	}

    return prev[m-1];
}



int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		vector<vector<int>> grid;
		int n,m; cin>>n>>m;

		for(int i=0; i<n; i++) {
			vector<int> temp;
			for(int j=0; j<m; j++) {
				int x; cin >> x;
				temp.push_back(x);
			}
			grid.push_back(temp);
		}

		cout << minSumPath(grid) << endl;
	}
}
