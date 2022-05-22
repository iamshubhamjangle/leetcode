/*
Palindrome_String.cpp

Given a string S, check if it is palindrome or not.

Input: S = "abba"
Output: 1

Input: S = "abc" 
Output: 0

https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
Method 1: TC: O(N/2), SC: O(1)
	- iterate through half and check -- if(S[i] != S[n-i-1])
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int isPalindrome(string S) {
	    int n = S.length();
	    for(int i = 0; i < n/2 ; i++) {
	       if(S[i] != S[n-i-1])
	        return 0;
	    } 
	    return 1;
	}
};

int main() {
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}