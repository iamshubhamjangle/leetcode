/*
print_the_LCS.cpp
longestCommonSubsequence

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: "ace"

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: "abc"

Example 3:
Input: text1 = "abc", text2 = "def"
Output: ""

*/


#include <bits/stdc++.h>
using namespace std;

// TC: O(N*M) + O(2N), SC: O(M+N)
string longestCommonSubsequence(string text1, string text2) {
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

	// return dp[n][m];
	// Now lets go through the dp[][] and find the lcs string
	int i = n; 
	int j = m;
	string ans = "";

	while(i>0 && j>0) {

		if(text1[i-1] == text2[j-1]) {
			ans += text1[i-1];
			i--;
			j--;
		} else {
			if(dp[i-1][j] < dp[i][j-1]) {
				j--;
			} else {
				i--;
			}
		}
	}

	reverse(ans.begin(), ans.end());		// O(n/2) ~ O(n)
	return ans;
}


int main(){
	cout << longestCommonSubsequence("abcde", "ace") << endl;
	cout << longestCommonSubsequence("abc", "abc") << endl;
	cout << longestCommonSubsequence("abc", "def") << endl;
}
