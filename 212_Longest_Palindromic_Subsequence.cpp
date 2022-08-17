/*
Longest_Palindromic_Subsequence.cpp

Given a string s, find the longest palindromic subsequence's length in s.

Input: s = "bbbab"
Output: 4

Input: s = "cbbd"
Output: 2

https://leetcode.com/problems/longest-palindromic-subsequence/
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// // 4. Tabulation. Index Shifted. TC: O(N*M) SC: O(N*M)
	// int longestCommonSubsequence(string text1, string text2) {
	// 	int n = text1.size();
	// 	int m = text2.size();
	// 	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	// 	for(int i=0; i<=n; i++) dp[i][0] = 0;
	// 	for(int i=0; i<=m; i++) dp[0][i] = 0;

	// 	for(int i=1; i<=n; i++) {
	// 		for(int j=1; j<=m; j++) {
	// 			int ans;

	// 			if(text1[i-1] == text2[j-1])
	// 				ans = 1 + dp[i-1][j-1];
	// 			else
	// 				ans = 0 + max(dp[i-1][j], dp[i][j-1]);
				
	// 			dp[i][j] = ans;
	// 		}
	// 	}

	// 	return dp[n][m];
	// }

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


    int longestPalindromeSubseq(string s) {
    	string s1(s);
    	string s2(s);
    	reverse(s2.begin(), s2.end());

    	return longestCommonSubsequence(s1, s2);
    }
};

int main(){
	Solution s;
	cout << s.longestPalindromeSubseq("bbbab") << endl;
	cout << s.longestPalindromeSubseq("cbbd") << endl;
}