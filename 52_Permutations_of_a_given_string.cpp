/*
Permutations_of_a_given_string.cpp

Given a string S. The task is to print all permutations of a given string in 
lexicographically sorted order.

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA

https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
		Method 1: Using C++ STL - O(n!*n)
		Method 2: Using Backtracking - O(n!*n)


*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		// // Method 1: Using C++ STL - O(n!*n)
		// vector<string> find_permutation(string str) {
		// 		sort(str.begin(), str.end());
		// 		vector<string> ans;

		// 		do {
		// 		   ans.push_back(str);
		// 		}	while (next_permutation(str.begin(), str.end()));

		// 		return ans;
		// }

		// Method 2: Using Backtracking - O(n!*n)
		void solve(int ind,string &s,vector<string>&ans) {
        if(ind==s.length()) {
            ans.push_back(s);
            return;
        }
        for(int i=ind;i<s.length();i++) {
            if(i>ind && s[i]==s[i-1])continue;
            swap(s[i],s[ind]);
            solve(ind+1,s,ans);
            swap(s[i],s[ind]);
        }
    }

		vector<string>find_permutation(string s) {
		    vector<string>ans;
		    sort(s.begin(),s.end());
		    solve(0,s,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}