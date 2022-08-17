/*
Longest_Common_Substring.cpp

Substring is Contiguous + ordered sequence of characters.
*/

#include <bits/stdc++.h>
using namespace std;

// // Tabulation of LCS. TC: O(N*M) SC: O(N+M)
// int longestCommonSubstring(string text1, string text2) {
// 	int n = text1.size();
// 	int m = text2.size();
// 	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

// 	for(int i=0; i<=n; i++) dp[i][0] = 0;
// 	for(int i=0; i<=m; i++) dp[0][i] = 0;

// 	int maxLCS = 0;
// 	for(int i=1; i<=n; i++) {
// 		for(int j=1; j<=m; j++) {
// 			int ans;

// 			if(text1[i-1] == text2[j-1])
// 				ans = 1 + dp[i-1][j-1];
// 			else
// 				ans = 0;
			
// 			dp[i][j] = ans;
// 			maxLCS = max(maxLCS, dp[i][j]);
// 		}
// 	}

// 	return maxLCS;
// }



// Space Optimisation of LCS. TC: O(N*M) SC: O(M)
int longestCommonSubstring(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();
	vector<int> prev(m+1, 0);
	vector<int> curr(m+1, 0);

	int maxLCS = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			int ans;

			if(text1[i-1] == text2[j-1])
				ans = 1 + prev[j-1];
			else
				ans = 0;
			
			curr[j] = ans;
			maxLCS = max(maxLCS, curr[j]);
		}
		prev = curr;
	}

	return maxLCS;
}

int main(){
	cout << longestCommonSubstring("abcde", "ace") << endl;
	cout << longestCommonSubstring("abc", "abc") << endl;
	cout << longestCommonSubstring("abc", "abf") << endl;		
	cout << longestCommonSubstring("abc", "def") << endl;		
}