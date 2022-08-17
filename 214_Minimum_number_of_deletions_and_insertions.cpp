/*
Minimum_number_of_deletions_and_insertions.cpp

Input: str1 = "heap", str2 = "pea"
Output: 3

Input : str1 = "geeksforgeeks", str2 = "geeks"
Output: 8

https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

*/
#include <bits/stdc++.h>
using namespace std;


class Solution{
	public:

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


	int minOperations(string str1, string str2) {
	    int n = str1.size();
	    int m = str2.size();

	    int nLCS = longestCommonSubsequence(str1, str2);

	    return (n - nLCS) + (m - nLCS);
	} 
};


int main(){
	Solution s;
	cout << s.minOperations("heap", "pea") << endl;	// 3
	cout << s.minOperations("geeksforgeeks", "geeks") << endl;	// 8
}