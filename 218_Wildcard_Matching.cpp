/*
Wildcard_Matching.cpp

Input: s = "aa", p = "a"
Output: false

Input: s = "aa", p = "*"
Output: true

Input: s = "cb", p = "?a"
Output: false

https://leetcode.com/problems/wildcard-matching/

*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	// // 1. Recursion. TC: Exponential, SC: O(1), ASC: O(N+M)
 //    bool solve(int i, int j, string pat, string str) {
 //    	if(i < 0 && j < 0) return true;		// both exhausted - its valid
 //    	if(i < 0 && j >= 0) return false;	// pattern exhausted - its invalid
 //    	if(i >= 0 && j < 0) {				// all left pattern must be * to be valid
 //    		for(int x=0; x<=i; x++) {
 //    			if(pat[x] != '*') return false;
 //    		}
 //    		return true;
 //    	}

 //    	if(pat[i] == str[j] || pat[i] == '?') {	// match or contains '?'
 //    		return solve(i-1, j-1, pat, str);
 //    	}
 //    	if(pat[i] == '*') {					// matches to *
 //    		return solve(i-1, j, pat, str) || solve(i, j-1, pat, str);
 //    	}
 //    	return false;						// neither match/?/* = invalid
 //    }

 //    bool isMatch(string str, string pat) {
 //        int n = pat.size();
 //        int m = str.size();
 //        return solve(n-1, m-1, pat, str);
 //    }



	// // 2. Memoization. TC: O(N*M), SC: O(N*M), ASC: O(N+M)
 //    bool solve(int i, int j, string pat, string str, vector<vector<int>> &dp) {
 //    	if(i < 0 && j < 0) return true;		// both exhausted - its valid
 //    	if(i < 0 && j >= 0) return false;	// pattern exhausted - its invalid
 //    	if(i >= 0 && j < 0) {				// all left pattern must be * to be valid
 //    		for(int x=0; x<=i; x++) {
 //    			if(pat[x] != '*') return false;
 //    		}
 //    		return true;
 //    	}

 //    	if(dp[i][j] != -1)
 //    		return dp[i][j];

 //    	if(pat[i] == str[j] || pat[i] == '?') {	// match or contains '?'
 //    		return dp[i][j] = solve(i-1, j-1, pat, str, dp);
 //    	}
 //    	if(pat[i] == '*') {					// matches to *
 //    		return dp[i][j] = solve(i-1, j, pat, str, dp) || solve(i, j-1, pat, str, dp);
 //    	}
 //    	return dp[i][j] = false;						// neither match/?/* = invalid
 //    }

 //    bool isMatch(string str, string pat) {
 //        int n = pat.size();
 //        int m = str.size();
 //        vector<vector<int>> dp(n, vector<int>(m, -1));
 //        return solve(n-1, m-1, pat, str, dp);
 //    }



	// // 3. Memoization. Index Shifting. TC: O(N*M), SC: O(N*M), ASC: O(N+M)
 //    bool solve(int i, int j, string pat, string str, vector<vector<int>> &dp) {
 //    	if(i == 0 && j == 0) return true;		// both exhausted - its valid
 //    	if(i == 0 && j > 0) return false;	// pattern exhausted - its invalid
 //    	if(i > 0 && j == 0) {				// all left pattern must be * to be valid
 //    		for(int x=1; x<=i; x++) {
 //    			if(pat[x-1] != '*') return false;
 //    		}
 //    		return true;
 //    	}

 //    	if(dp[i][j] != -1)
 //    		return dp[i][j];

 //    	if(pat[i-1] == str[j-1] || pat[i-1] == '?') {
 //    		return dp[i][j] = solve(i-1, j-1, pat, str, dp);
 //    	}
 //    	if(pat[i-1] == '*') {
 //    		return dp[i][j] = solve(i-1, j, pat, str, dp) || solve(i, j-1, pat, str, dp);
 //    	}
 //    	return dp[i][j] = false;
 //    }

 //    bool isMatch(string str, string pat) {
 //        int n = pat.size();
 //        int m = str.size();
 //        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
 //        return solve(n, m, pat, str, dp);
 //    }


	// // 4. Tabulation. Index Shifting. TC: O(N*M), SC: O(N*M)
 //    bool isMatch(string str, string pat) {
 //        int n = pat.size();
 //        int m = str.size();
 //        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

 //        dp[0][0] = 1;
 //        for(int j=1; j<=m; j++) dp[0][j] = 0;
 //        for(int i=1; i<=n; i++) {
 //        	bool flag = true;
 //        	for(int x=1; x<=i; x++) {
 //        		if(pat[x-1] != '*') {
 //        			flag = false;
 //        			break;
 //        		}
 //        	}
 //        	dp[i][0] = flag;
 //        }

 //        for(int i=1; i<=n; i++) {
 //        	for(int j=1; j<=m; j++) {
	// 	    	if(pat[i-1] == str[j-1] || pat[i-1] == '?') {
	// 	    		dp[i][j] = dp[i-1][j-1];
	// 	    	} else if(pat[i-1] == '*') {
	// 	    		dp[i][j] = dp[i-1][j] || dp[i][j-1];
	// 	    	} else {
	// 	    		dp[i][j] = false;
	// 	    	}
 //        	}
 //        }
 //        return dp[n][m];
 //    }


	/**
	 * Whenever we are changing column value in each row in base condition that need to be handled in first for loop.
	 * Always use m+1 (column) size in vectors.
	 */

	// 5. Space Optimise. TC: O(N*M), SC: O(M)
    bool isMatch(string str, string pat) {
        int n = pat.size();
        int m = str.size();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int i=1; i<=n; i++) {
        	bool flag = true;
        	for(int x=1; x<=i; x++) {
        		if(pat[x-1] != '*') {
        			flag = false;
        			break;
        		}
        	}
        	curr[0] = flag;

        	for(int j=1; j<=m; j++) {
		    	if(pat[i-1] == str[j-1] || pat[i-1] == '?') {
		    		curr[j] = prev[j-1];
		    	} else if(pat[i-1] == '*') {
		    		curr[j] = prev[j] || curr[j-1];
		    	} else {
		    		curr[j] = false;
		    	}
        	}
        	prev = curr;
        }
        return prev[m];
    }
};


int main(){
	Solution s;
	cout << s.isMatch("aa", "a") << endl;		// false
	cout << s.isMatch("aa", "*") << endl;		// true
	cout << s.isMatch("cb", "?a") << endl;		// false
}

