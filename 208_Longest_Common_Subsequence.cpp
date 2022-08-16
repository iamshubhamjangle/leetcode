/*
Longest_Common_Subsequence.cpp

A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

https://leetcode.com/problems/longest-common-subsequence/
- 1. Recursion. TC: O(2^n) SC: O(1) ASC: O(N+M)
- 2. Memoisation. TC: O(N*M) SC: O(N*M) ASC: O(N+M)
- 3. Memoisation. Index Shifting TC: O(N*M) SC: O(N*M) ASC: O(N+M)
- 4. Tabulation. Index shifting for tabulation. TC: O(N*M) SC: O(N*M)
- 5. Space Optimisation. TC: O(N*M) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;


// 1. Recursion. TC: O(2^n) SC: O(1) ASC: O(N+M)
int solve(int i, int j, string text1, string text2) {
	if(i < 0 || j < 0) {
		return 0;
	}

	if(text1[i] == text2[j]) {
		return 1 + solve(i-1, j-1, text1, text2);
	} 
	else {
		return 0 + max(solve(i-1, j, text1, text2), solve(i, j-1, text1, text2));
	}
}

int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	return solve(n-1, m-1, text1, text2);
}


// 2. Memoisation TC: O(N*M) SC: O(N*M) ASC: O(N+M)
int solve(int i, int j, string text1, string text2, vector<vector<int>> &dp) {
	if(i < 0 || j < 0) {
		return 0;
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans;

	if(text1[i] == text2[j]) {
		ans = 1 + solve(i-1, j-1, text1, text2, dp);
	} 
	else {
		ans = 0 + max(solve(i-1, j, text1, text2, dp), solve(i, j-1, text1, text2, dp));
	}

	return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();
	vector<vector<int>> dp(n, vector<int>(m, -1));

	return solve(n-1, m-1, text1, text2, dp);
}


// Index shifting for tabulation.
// 3. Memoisation - Index Shifting TC: O(N*M) SC: O(N*M) ASC: O(N+M)
int solve(int i, int j, string text1, string text2, vector<vector<int>> &dp) {
	if(i == 0 || j == 0) {
		return 0;
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans;

	if(text1[i-1] == text2[j-1]) {
		ans = 1 + solve(i-1, j-1, text1, text2, dp);
	} 
	else {
		ans = 0 + max(solve(i-1, j, text1, text2, dp), solve(i, j-1, text1, text2, dp));
	}

	return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));	//-- increase the size

	return solve(n, m, text1, text2, dp);
}



// 4. Tabulation. Index Shifted. TC: O(N*M) SC: O(N*M)
int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int i=0; i<=m; i++) dp[0][i] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			int ans;

			if(text1[i-1] == text2[j-1])
				ans = 1 + dp[i-1][j-1];
			else
				ans = 0 + max(dp[i-1][j], dp[i][j-1]);
			
			dp[i][j] = ans;
		}
	}

	return dp[n][m];
}


// 5. Space Optimisation. TC: O(N*M) SC: O(N)
int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();
	vector<int> prev(m+1, 0);
	vector<int> curr(m+1, 0);

	// for(int i=0; i<=n; i++) dp[i][0] = 0;	// ** column wont be there in prev row
	for(int i=0; i<=m; i++) prev[i] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			int ans;
			
			if(text1[i-1] == text2[j-1])
				ans = 1 + prev[j-1];
			else
				ans = 0 + max(prev[j], curr[j-1]);
			
			curr[j] = ans;
		}
		prev = curr; 
	}

	return curr[m];
}



int main(){
	cout << longestCommonSubsequence("abcde", "ace") << endl;
	cout << longestCommonSubsequence("abc", "abc") << endl;
	cout << longestCommonSubsequence("abc", "def") << endl;
}