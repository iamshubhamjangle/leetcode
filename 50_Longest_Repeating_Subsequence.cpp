/*
Longest_Repeating_Subsequence.cpp

I'm hoping you knows what LCS is, so basically in that we have to find longest sequence and here we have to find a longest sequence which sequence itself is repeating again and again. And you have to print the number of times that sequence is repeating.

For example: AABEBCDD
Here ABD is the longest sequence which repeated twice.
indexes : 0,2,6 & 1,4,7.

I hope you understood. And now how to approach this one. Let you took another string str2 same as str now you just need to find repetition of alphabets except at same indexes i.e. i!=j (Because both strings are same so it's absolute that it'll count that one).

Input:
str = "axxzxy"
Output: 2

Input:
str = "axxxy"
Output: 2

https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
Method 1: DP. TC: O(N*N). SC: O(N*N)
	- reference: https://www.youtube.com/watch?v=hbTaCmQGqLg

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		// Method 2: DP. TC: O(N*N). SC: O(N*N)
		// int LongestRepeatingSubsequence(string str){
  //            string s = str;
  //            int n = str.size();
  //            int dp[n+1][n+1];
  //            for(int i = 0;i<=n;i++){
  //                dp[i][0] = 0;
  //            }
  //            for(int i = 0;i<=n;i++){
  //                dp[0][i] = 0;
  //            }
  //            for(int i = 1;i<=n;i++){
  //                for(int j =1;j<=n;j++){
  //                    if(str[i-1] == s[j-1] && i != j){
  //                        dp[i][j] = 1 + dp[i-1][j-1];
  //                    }
  //                    else{
  //                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
  //                    }
  //                }
  //            }
  //            return dp[n][n];
		// }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
