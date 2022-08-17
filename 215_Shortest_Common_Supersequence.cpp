/*
Shortest_Common_Supersequence.cpp

A string s is a subsequence of string t if deleting some number of 
characters from t (possibly 0) results in the string s.

Input: str1 = "abac", str2 = "cab"
Output: "cabac"

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

https://leetcode.com/problems/shortest-common-supersequence/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
		// LCS. Tabulation. Index Shifted. TC: O(N*M) SC: O(N*M) 
		int n = str1.size();
		int m = str2.size();
		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

		for(int i=0; i<=n; i++) dp[i][0] = 0;
		for(int i=0; i<=m; i++) dp[0][i] = 0;

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				int ans;

				if(str1[i-1] == str2[j-1])
					ans = 1 + dp[i-1][j-1];
				else
					ans = 0 + max(dp[i-1][j], dp[i][j-1]);
				
				dp[i][j] = ans;
			}
		}

		// Now we have the dp array. Lets begin from bottom.
		int i = n;
		int j = m;
		string ans = "";

		// go towards top until we reach (0,0) which is right shifted indexing
		while(i>0 && j>0) {
			if(str1[i-1] == str2[j-1]) {	//if the last letter is equal add it to ans
				ans += str1[i-1];
				i--;
				j--;
			}
			else if(dp[i-1][j] > dp[i][j-1]) {
				ans += str1[i-1];
				i--;
			}
			else {
				ans += str2[j-1];
				j--;
			}
		}

		// we are at 0,0 or 0,1 or 1,0 lets add the leftovers
		while(i>0) {
			ans += str1[i-1];
			i--;
		}

		while(j>0) {
			ans += str2[j-1];
			j--;
		}

		reverse(ans.begin(), ans.end());

		return ans;
    }
};


int main() {
	Solution s;
	cout << s.shortestCommonSupersequence("abac","cab") << endl;			// Output: "cabac"
	cout << s.shortestCommonSupersequence("aaaaaaaa","aaaaaaaa") << endl;	// Output: "aaaaaaaa"
}