/*
Longest_Common_Subsequence.cpp

https://leetcode.com/problems/longest-common-subsequence/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// // Recursion. TC: O(2^n) SC: O(1) ASC: O(N+M)
	// int solve(int i, int j, string &s1, string &s2) {
	// 	if(i < 0 || j < 0)
	// 		return 0;

	// 	if(s1[i] == s2[j])
	// 		return 1 + solve(i-1, j-1, s1, s2);
	// 	else
	// 		return max(solve(i-1, j, s1, s2), solve(i, j-1, s1, s2));
	// }

    // int longestCommonSubsequence(string s1, string s2) {
    //     int n = s1.size();
    //     int m = s2.size();
    //     return solve(n-1, m-1, s1, s2);
    // }


    // // Memoisation. TC: O(NM) SC: O(NM) ASC: O(N+M)
	// int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
	// 	if(i < 0 || j < 0)
	// 		return 0;

	// 	if(dp[i][j] != -1) return dp[i][j];

	// 	int ans;
	// 	if(s1[i] == s2[j])
	// 		ans = 1 + solve(i-1, j-1, s1, s2, dp);
	// 	else
	// 		ans = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));

	// 	return dp[i][j] = ans;
	// }

    // int longestCommonSubsequence(string s1, string s2) {
    //     int n = s1.size();
    //     int m = s2.size();
    //     vector<vector<int>> dp(n, vector<int>(m, -1)); 
    //     return solve(n-1, m-1, s1, s2, dp);
    // }


	// // Memo Index Shifting as i,j < 0. 
	// int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
	// 	if(i == 0 || j == 0)
	// 		return 0;

	// 	if(dp[i][j] != -1) return dp[i][j];

	// 	int ans;
	// 	if(s1[i-1] == s2[j-1])
	// 		ans = 1 + solve(i-1, j-1, s1, s2, dp);
	// 	else
	// 		ans = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));

	// 	return dp[i][j] = ans;
	// }

    // int longestCommonSubsequence(string s1, string s2) {
    //     int n = s1.size();
    //     int m = s2.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); 
    //     return solve(n, m, s1, s2, dp);
    // }


    // // Tabulation. TC: O(NM) SC: O(NM)
    // int longestCommonSubsequence(string s1, string s2) {
    //     int n = s1.size();
    //     int m = s2.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    //     for(int i=1; i<=n; i++) {
    //     	for(int j=1; j<=m; j++) {
	// 			int ans;
	// 			if(s1[i-1] == s2[j-1])
	// 				ans = 1 + dp[i-1][j-1];
	// 			else
	// 				ans = max(dp[i-1][j], dp[i][j-1]);

	// 			dp[i][j] = ans;
    //     	}
    //     }

    //     return dp[n][m];
    // }


    // Space Optimisation. TC: O(NM) SC: O(1)
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int i=1; i<=n; i++) {
        	for(int j=1; j<=m; j++) {
				int ans;
				if(s1[i-1] == s2[j-1])
					ans = 1 + prev[j-1];
				else
					ans = max(prev[j], curr[j-1]);

				curr[j] = ans;
        	}
        	prev = curr;
        }

        return curr[m];
    }
};

int main(){
	Solution s;
	string a,b;
	a = "abcde";
	b = "ace";
	cout << s.longestCommonSubsequence(a,b) << endl;
	
	a = "abc";
	b = "abc";
	cout << s.longestCommonSubsequence(a,b) << endl;

	a = "abc";
	b = "def";
	cout << s.longestCommonSubsequence(a,b) << endl;
}