/*
Minimum_Insertion_Steps_to_Make_a_String_Palindrome.cpp

Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.

Input: s = "zzazz"
Output: 0

Input: s = "mbadm"
Output: 2

Input: s = "leetcode"
Output: 5

https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	// 5. Space Optimisation. TC: O(N*M) SC: O(N)
	// return length of longest common subsequence
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


    int minInsertions(string s) {
        string s1(s);
        string s2(s);

        reverse(s2.begin(), s2.end());

        int n = longestCommonSubsequence(s1, s2);
        int m = s.size();

        return m-n;
    }
};

int main(){
	Solution s;
	cout << s.minInsertions("zzazz") << endl;
	cout << s.minInsertions("mbadm") << endl;
	cout << s.minInsertions("leetcode") << endl;
}


