/*
Longest_Common_Prefix_in_an_Array.cpp

Given a array of N strings, find the longest common prefix among all strings present in the array.

Input :	N = 4 --> arr[] = {geeksforgeeks, geeks, geek, geezer}
Output: gee

Input : N = 2 --> arr[] = {hello, world}
Output: -1

https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1/
    - Method 1: Iterate each word and letter. TC: O(N*M). SC: O(1)
*/


#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    string longestCommonPrefix (string arr[], int N) {
        int count = INT_MAX;
        if(N == 1) return arr[0];

        string refString = arr[0];
        int l = refString.size();       // ref string length = l

        for(int i=1; i<N; i++) {
            string currString = arr[i];
            int m = currString.size();  // curr string length = m

            int x = min(l,m);
            int localCount = 0;

            for(int j=0; j<x; j++) {
                if(currString[j] == refString[j]) localCount++;
                else break;
            }

            count = min(count, localCount);
        }

        if(count == 0) return "-1";

        string ans = refString.substr(0, count);
        return ans;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}