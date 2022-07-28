/*
Palindrome_Partitioning.cpp

https://leetcode.com/problems/palindrome-partitioning/
1. Backtracking. Making partition at each index.
TC: O((2^n)*k*(n/2) )
SC: O(k * x)

// O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.
// The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).

*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void solve(string s, int idx, vector<vector<string>> &ans, vector<string> &ds) {
    if(idx == s.size()) {
        ans.push_back(ds);
        return;
    }

    for(int i=idx; i<s.size(); i++) {
        if(isValid(s, idx, i)) {
            ds.push_back(s.substr(idx,i-idx+1));
            solve(s, i+1, ans, ds);
            ds.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> ds;
    solve(s, 0, ans, ds);
    return ans;
}


int main(){
	string s = "aab";
	vector<vector<string>> ans = partition(s);
	for(auto i: ans) {
		cout << "[";
		for(auto j: i) {
			cout << j << ",";
		}
		cout << "],";
	}
}