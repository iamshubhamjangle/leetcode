/*
Distinct_Subsequences.cpp

Given two strings s and t, return the number of distinct subsequences of s which equals t.

Input: s = "rabbbit", t = "rabbit"
Output: 3

Input: s = "babgbag", t = "bag"
Output: 5

https://leetcode.com/problems/distinct-subsequences/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
	public:
	// // 1. Recursion. TC: O(2^n) SC: O(1) ASC: O(N)
	// int solve(int i, int j, string s, string t) {
	// 	if(j < 0) return 1;
	// 	if(i < 0) return 0;


	// 	// If both char are equal
	// 	if(s[i] == t[j]) {
	// 		return solve(i-1, j-1, s, t) + solve(i-1, j, s, t);
	// 	}
	// else
	// 	return solve(i-1, j, s, t);
	// }


 //    int numDistinct(string s, string t) {
	// 	// f(i,j) will mean count (return 0/1) distinct words of string t in string s.
 //    	int n = s.size();
 //    	int m = t.size();
 //    	return solve(n-1, m-1, s, t);
 //    }



	// // 2. Memoization. TC: O(n*m) SC: O(m*n) ASC: O(N)
	// int solve(int i, int j, string s, string t, vector<vector<int>> &dp) {
	// 	if(j < 0) return 1;
	// 	if(i < 0) return 0;

	// 	if(dp[i][j] != -1)
	// 		return dp[i][j];

	// 	// If both char are equal
	// 	if(s[i] == t[j]) {
	// 		return dp[i][j] = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
	// 	}
	// else
	// 	return dp[i][j] = solve(i-1, j, s, t, dp);
	// }


 //    int numDistinct(string s, string t) {
	// 	// f(i,j) will mean count (return 0/1) distinct words of string t in string s.
 //    	int n = s.size();
 //    	int m = t.size();
 //    	vector<vector<int>> dp(n, vector<int> (m, -1));
 //    	return solve(n-1, m-1, s, t, dp);
 //    }



	// // 3. Memoization. Index shifted. TC: O(n*m) SC: O(m*n) ASC: O(N)
	// int solve(int i, int j, string s, string t, vector<vector<int>> &dp) {
	// 	if(j == 0) return 1;			// -- changed < 0 to == 0
	// 	if(i == 0) return 0;			// -- changed < 0 to == 0

	// 	if(dp[i][j] != -1)
	// 		return dp[i][j];

	// 	if(s[i-1] == t[j-1]) {			// -- changed to -1
	// 		return dp[i][j] = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
	// 	}
	// else
	// 	return dp[i][j] = solve(i-1, j, s, t, dp);
	// }


 //    int numDistinct(string s, string t) {
	// 	// f(i,j) will mean count (return 0/1) distinct words of string t in string s.
 //    	int n = s.size();
 //    	int m = t.size();
 //    	vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
 //    	return solve(n, m, s, t, dp);
 //    }		

	// // 4. Tabulation. Index Shifted. TC: O(n*m) SC: O(m*n)
 //    int numDistinct(string s, string t) {
 //    	int n = s.size();
 //    	int m = t.size();
 //    	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    	
 //    	for(int i=0; i<n+1; i++) dp[i][0] = 1;
 //    	for(int j=1; j<m+1; j++) dp[0][j] = 0;	// j starts from 1 as [0][0] would get replaced by 0.


 //    	for(int i=1; i<n+1; i++) {
 //    		for(int j=1; j<m+1; j++) {
	// 			if(s[i-1] == t[j-1]) {
	// 				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	// 			} else {
	// 				dp[i][j] = dp[i-1][j];
	// 			}
 //    		}
 //    	}

 //    	return dp[n][m];
 //    }

/*****
 * VECTOR DOUBLE CAN BE USED IN CASE OF OVERFLOW ERRORS ON LEETCODE FOR C++ CODES
 * vector<double>
 *  *****/

	// // 5. Space optimization. Index Shifted. TC: O(n*m) SC: O(m)
 //    int numDistinct(string s, string t) {
 //    	int n = s.size();
 //    	int m = t.size();
 //    	vector<double> prev(m+1, 0);
 //    	vector<double> curr(m+1, 0);
    	
 //    	prev[0] = curr[0] = 1;
 //    	for(int j=1; j<m+1; j++) prev[j] = 0;	// j starts from 1 as [0][0] would get replaced by 0.

 //    	for(int i=1; i<n+1; i++) {
 //    		for(int j=1; j<m+1; j++) {
	// 			if(s[i-1] == t[j-1]) {
	// 				curr[j] = prev[j-1] + prev[j];
	// 			} else {
	// 				curr[j] = prev[j];
	// 			}
 //    		}
 //    		prev = curr;
 //    	}

 //    	return (int) prev[m];
 //    }


    // 6. Space optimization. Using only prev array. TC: O(n*m) SC: O(m)
    int numDistinct(string s, string t) {
    	int n = s.size();
    	int m = t.size();
    	vector<double> prev(m+1, 0);
    	// vector<double> curr(m+1, 0);
    	
    	prev[0] = 1;
    	// for(int j=1; j<m+1; j++) prev[j] = 0;	// We can avoid this as default is 0

    	for(int i=1; i<n+1; i++) {
    		for(int j=m; j>0; j--) {
				if(s[i-1] == t[j-1]) {
					prev[j] = prev[j-1] + prev[j];
				} else {
					prev[j] = prev[j];
				}
    		}
    	}

    	return (int) prev[m];
    }

};

int main(){
	Solution s;
	cout << s.numDistinct("rabbbit", "rabbit") << endl;	
	cout << s.numDistinct("babgbag", "bag") << endl;	
}

