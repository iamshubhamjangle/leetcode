/*
Longest_Common_Subsequence.cpp

A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2


*/

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    // DP
};

int main() {
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}