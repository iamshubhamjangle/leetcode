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
	Method 1: loop through txt and match pat. TC: O(N). SC: O(N)
    	- if(first letter of pat == txt) then get txt substr(i, lengthOfPat) == pat
    	- if yes move the index to vector or else at end move -1 of vector empty
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    	// Method 1: loop through txt. TC: O(N). SC: O(N)
    	// - if(first letter of pat == txt) then get txt substr(i, lengthOfPat) == pat
    	// - if yes move the index to vector or else at end move -1 of vector empty
		vector<int> search(string pat, string txt) {
        	int n = txt.size();
        	int m = pat.size();
        	vector<int> ans;

			for(int i=0; i<n; i++) {
				if(txt[i] == pat[0]) {
					if(txt.substr(i,m) == pat) {
						// cout << "sub: " << txt.substr(i,m) << " == " << pat << endl;
						ans.push_back(i+1);
					}
				}
			}

			if(!ans.size()) ans.push_back(-1);

			return ans;
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
