/*
Count_Palindromic_Subsequences.cpp

Given a string str of length N, you have to find number of palindromic subsequence 
(need not necessarily be distinct) which could be formed from the string str.
Note: You have to return the answer module 109+7;

Input : Str = "abcd"
Output: 4

Input : Str = "aab"
Output: 4

https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
    - Method 1: Using Recursion. O(N*2^n). SC: O(1)
    - Method 2: Use DP to reduce overlapping recusive problems. O(N*N). SC: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{ 
    public:
    // Method 1: Using Recursion. O(N*2^n). SC: O(1)
    // long long helper(string &str, int i, int j) {
    //     if(i == j)
    //         return 1;
    //     else if(i > j)
    //         return 0;
    //     else if(str[i] == str[j])
    //         return helper(str, i+1, j) + helper(str, i, j-1) + 1;
    //     else
    //         return helper(str, i+1, j) + helper(str, i, j-1) - helper(str, i+1, j-1);
    // }

    // long long int countPS(string str) {
    //     int n = str.size();
    //     int i=0;
    //     int j=n-1;

    //     return helper(str, i, j);
    // }

    // Method 2: Use DP to reduce overlapping recusive problems. O(N*2^n). SC: O(1)
    // If we draw recursion tree of above recursive solution, 
    // we can observe overlapping Subproblems. Since the problem has overlapping 
    // subproblems, we can solve it efficiently using Dynamic Programming. 
    // Below is Dynamic Programming based solution
    long long dp[1001][1001];
        int mod = 1e9+7;
    
        long long int  countPS(string str) {
            memset(dp, -1, sizeof dp);
            return solve(str, 0, str.size() - 1);
    }

    long long solve(string& str, int i, int j) {
        if(i>j) 
            return 0;
        if(i==j) 
            return 1;
        if(dp[i][j] != -1) 
            return dp[i][j];
        if(str[i] == str[j]) 
            return dp[i][j] = ( 1 + 
                                solve(str, i+1, j) + 
                                solve(str, i, j-1)
                               ) % mod;
        else 
            return dp[i][j] = ( mod + 
                                solve(str, i+1, j) + 
                                solve(str, i, j-1) - 
                                solve(str, i+1, j-1)
                              ) % mod;
    }

};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}