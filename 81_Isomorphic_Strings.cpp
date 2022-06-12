/*
Isomorphic_Strings.cpp

Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in str1 should map to the same character in str2

Input:
str1 = aab
str2 = xxy
Output: 1

Input:
str1 = aab
str2 = xyz
Output: 0

https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#
	- Method 1: using um for both string. TC: O(N), SC: O(N)

*/
#include<bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256

class Solution
{
    public:
    // Method 1: using um for both string. TC: O(N), SC: O(N)
    bool areIsomorphic(string str1, string str2) {
    	int n = str1.size();
    	int m = str2.size();
    	if (n != m) return 0;

    	unordered_map<char, char> um1;
    	unordered_map<char, char> um2;

		for(int i=0; i<n; i++) {
			if(um1[str1[i]] || um2[str2[i]]) {
				if(um1[str1[i]] != str2[i] || um2[str2[i]] != str1[i])
					return 0;
			} else {
			    um1[str1[i]] = str2[i];
			    um2[str2[i]] = str1[i];
			}
		}

		return 1;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends