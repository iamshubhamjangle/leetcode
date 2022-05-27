/*
Word_Break.cpp

Given a string A and a dictionary of n words B, find out if A can be 
segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.

Input:
	n = 12
	B = { "i", "like", "sam", "sung", "samsung", "mobile", "ice","cream", "icecream", "man", "go", "mango" }
	A = "ilike"
Output:
	1

Input:
	n = 12
	B = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango" }
	A = "ilikesamsung"
Output:
	1

https://practice.geeksforgeeks.org/problems/word-break1352/1
    - Method 1: DFS
    - Method 2: DP

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Method 1: DFS
    // unordered_set <string> st;
    // void dfs(string A, vector <string> &B, string s, bool &f, int n){
    //     if(A.find(s) == string::npos || f == true || st.find(s) != st.end())
    //         return;
    //     if(A == s){
    //         f = true;
    //         return;
    //     }
    //     st.insert(s);
    //     for(int i=0; i<n; i++){
    //         dfs(A, B, s+B[i], f, n);
    //         if(i != n-1)
    //         dfs(A, B, s+B[i+1], f, n);
    //     }
    // }
    // bool wordBreak(string A, vector<string> &B) {
    //     bool f = false;
    //     dfs(A, B, "", f, B.size());
    //     return f;
    // }
    
    
    // Method 2: DP
    bool wordBreak(string A, vector<string> &B) {
        int n = A.size();
        vector <bool> dp(n+1, false);
        dp[n] = true;
        for(int i=n-1; i>=0; i--){
            string s = A.substr(i);
            for(auto j:B){
                int len = j.size();
                if(len<=s.size() && j == s.substr(0, len)){
                    dp[i] = dp[i]|dp[i+len];
                    if(dp[i])
                        break;
                }
            }
        }
        return dp[0];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}