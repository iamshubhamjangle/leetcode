/*
Remove_Consecutive_Characters.cpp

Given a string S delete the characters which are appearing more than once consecutively.

Example 1:
Input : S = aabb
Output: ab 

Example 2:
Input : S = aabaa
Output: aba

https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1
	- Method 1: loop over and dont append if equal to prev. TC: O(N). SC: O(N)

*/

#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
	// Method 1: loop over and dont append if equal to prev. TC: O(N). SC: O(N)
    string removeConsecutiveCharacter(string str) {
    	int n = str.size();
    	if(n <= 1) return str;

        string ans;
        ans.push_back(str[0]);

        for(int i=1; i<n; i++) {
        	if(str[i] != str[i-1]) 
        		ans.push_back(str[i]);
        }

        return ans;
    }
};

int main()  { 
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
}