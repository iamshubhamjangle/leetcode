/*
Search_Pattern_Rabin_Karp_Algorithm.cpp

Given two strings, one is a text string and other is a pattern string. 
The task is to print the indexes of all the occurences of pattern string 
in the text string. For printing, Starting Index of a string should be taken as 1.

Input : S = "batmanandrobinarebat", pat = "bat"
Output: 1 18

Input : S = "abesdu", pat = "edu"
Output: -1

https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1/
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> search(string pat, string txt)
        {
            //code here.
        }
     
};

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
