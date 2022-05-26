/*
Edit_Distance.cpp

Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.

Input : s = "geek", t = "gesek"
Output: 1

Input : s = "gfg", t = "gfg"
Output: 0

https://practice.geeksforgeeks.org/problems/edit-distance3702/1
	- DP problem. TC: O(N*N). SC: O(N*N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  	// DP problem. TC: O(N*N). SC: O(N*N)
  	int editDistance(string s, string t) {
       int m=s.length();
       int i,j,n=t.length();
       int dp[m+1][n+1];
       for(i=0;i<=m;i++){
           for(j=0;j<=n;j++){
               if(i==0)
               dp[i][j]=j;
               else if(j==0)
               dp[i][j]=i;
               else{
                   if(s[i-1]==t[j-1])
                   dp[i][j]=dp[i-1][j-1];
                   else
                   dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
               }
           }
       }
       return dp[m][n];
   }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}