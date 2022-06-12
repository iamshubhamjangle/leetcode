/*
Transform_String.cpp

Given two strings A and B. Find the minimum number of steps required to transform string A into string B. The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.

Input:
A = "abd"
B = "bad"
Output: 1

Input:
A = "GeeksForGeeks"
B = "ForGeeksGeeks"
Output: 3

https://practice.geeksforgeeks.org/problems/transform-string5648/1
    Method 1: TC: O(N), SC: O(N)
     - Check for same characters and then count the # to move the char

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int transform (string A, string B) {
        int n = A.size();
        int m = B.size();

        if(n != m) return -1;

        // Step 1: Check if both strings has same character
        unordered_map<char, int> um;
        for(auto i: A)
            um[i]++;

        for(auto j: B)
            um[j]--;

        for(auto p: um)
            if(p.second != 0)
                return -1;

        // Step 2: As both string have same character they can be moved.
        // count no of match from reverse and return length - match
        int i = n-1;
        int j = m-1;
        int match = 0;

        while(i >= 0 && j >= 0) {
            if(A[i] == B[j]) {
                match++;
                i--;
                j--;
            } else {
                i--;
            }
        }

        return n-match;
    }
};

int main ()  {
    int t; cin >> t;
    while (t--) {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}