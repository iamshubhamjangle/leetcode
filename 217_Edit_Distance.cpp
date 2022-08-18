/*
Edit_Distance.cpp

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

Input: word1 = "horse", word2 = "ros"
Output: 3

Input: word1 = "intention", word2 = "execution"
Output: 5

https://leetcode.com/problems/edit-distance/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// // 1. Recursion. TC: exponential (3^n) SC: O(1) ASC: O(M+N)
	// int solve(int i, int j, string word1, string word2) {
	// 	if(i < 0) return j+1;
	// 	if(j < 0) return i+1;

	// 	int ans;

	// 	if(word1[i] == word2[j]) {
	// 		ans = 0 + solve(i-1, j-1, word1, word2);
	// 	} else {
	// 		int ins = 1 + solve(i, j-1, word1, word2);		// insert
	// 		int del = 1 + solve(i-1, j, word1, word2);		// delete
	// 		int upd = 1 + solve(i-1, j-1, word1, word2);	// update
	// 		ans = min(ins, min(del, upd));
	// 	}

	// 	return ans;
	// }

	// public:
 //    int minDistance(string word1, string word2) {
 //    	int n = word1.size();    
 //    	int m = word2.size();

 //    	return solve(n-1, m-1, word1, word2);    
 //    }



	// // 2. Memoization. TC: O(m*n) SC: O(m*n) ASC: O(M+N)
	// int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp) {
	// 	if(i < 0) return j+1;
	// 	if(j < 0) return i+1;

	// 	if(dp[i][j] != -1)
	// 		return dp[i][j];

	// 	int ans;

	// 	if(word1[i] == word2[j]) {
	// 		ans = 0 + solve(i-1, j-1, word1, word2, dp);
	// 	} else {
	// 		int ins = 1 + solve(i, j-1, word1, word2, dp);		// insert
	// 		int del = 1 + solve(i-1, j, word1, word2, dp);		// delete
	// 		int upd = 1 + solve(i-1, j-1, word1, word2, dp);	// update
	// 		ans = min(ins, min(del, upd));
	// 	}

	// 	return dp[i][j] = ans;
	// }

	// public:
 //    int minDistance(string word1, string word2) {
 //    	int n = word1.size();    
 //    	int m = word2.size();
 //    	vector<vector<int>> dp(n, vector<int>(m, -1));
 //    	return solve(n-1, m-1, word1, word2, dp);
 //    }



	// // 3. Memoization. Index Shifted.  TC: O(m*n) SC: O(m*n) ASC: O(M+N)
	// int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp) {
	// 	if(i == 0) return j;	// -1
	// 	if(j == 0) return i;	// -1

	// 	if(dp[i][j] != -1)
	// 		return dp[i][j];

	// 	int ans;

	// 	if(word1[i-1] == word2[j-1]) {
	// 		ans = 0 + solve(i-1, j-1, word1, word2, dp);
	// 	} else {
	// 		int ins = 1 + solve(i, j-1, word1, word2, dp);		// insert
	// 		int del = 1 + solve(i-1, j, word1, word2, dp);		// delete
	// 		int upd = 1 + solve(i-1, j-1, word1, word2, dp);	// update
	// 		ans = min(ins, min(del, upd));
	// 	}

	// 	return dp[i][j] = ans;
	// }

	// public:
 //    int minDistance(string word1, string word2) {
 //    	int n = word1.size();    
 //    	int m = word2.size();
 //    	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));	// +1
 //    	return solve(n, m, word1, word2, dp);				// +1
 //    }



// 	// 4. Tabulation. Index Shifted.  TC: O(m*n) SC: O(m*n)
// 	public:
//     int minDistance(string word1, string word2) {
//     	int n = word1.size();    
//     	int m = word2.size();
//     	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

// 		for(int i=0; i<=n; i++) dp[i][0] = i;
//     	for(int j=0; j<=m; j++) dp[0][j] = j;

//     	for(int i=1; i<=n; i++) {
//     		for(int j=1; j<=m; j++) {
// 				int ans;

// 				if(word1[i-1] == word2[j-1]) {
// 					ans = 0 + dp[i-1][j-1];
// 				} else {
// 					int ins = 1 + dp[i][j-1];
// 					int del = 1 + dp[i-1][j];
// 					int upd = 1 + dp[i-1][j-1];
// 					ans = min(ins, min(del, upd));
// 				}

// 				dp[i][j] = ans;
//     		}
//     	}

//     	return dp[n][m];
//     }
// };




	// 5. Space Optimised. Index Shifted.  TC: O(m*n) SC: O(m)
	public:
    int minDistance(string word1, string word2) {
    	int n = word1.size();    
    	int m = word2.size();
    	vector<int> prev(n+1, 0);
    	vector<int> curr(m+1, 0);

    	for(int j=0; j<=m; j++) prev[j] = j;

    	for(int i=1; i<=n; i++) {
    		curr[0] = i;					// -- imp -- curr[0] always need to be init with i.
    		for(int j=1; j<=m; j++) {
				int ans;

				if(word1[i-1] == word2[j-1]) {
					ans = 0 + prev[j-1];
				} else {
					int ins = 1 + curr[j-1];
					int del = 1 + prev[j];
					int upd = 1 + prev[j-1];
					ans = min(ins, min(del, upd));
				}

				curr[j] = ans;
    		}
    		prev = curr;
    	}

    	return prev[m];
    }


};

int main(){
	Solution s;
	cout << s.minDistance("horse","ros") << endl;	
	cout << s.minDistance("intention","execution") << endl;	
}