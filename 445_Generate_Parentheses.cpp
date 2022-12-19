/*
Generate_Parentheses.cpp

https://leetcode.com/problems/generate-parentheses/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void solve(int o, int c, string s, int n, vector<string> &ans) {
		if(o == n && c == n) {
			ans.push_back(s);
		}

		// two ways
		if(o < n) solve(o+1, c, s + '(', n, ans);
		if(c < n && c < o) solve(o, c+1, s + ')', n, ans);
	}

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, "", n, ans);
        return ans;
    }
};

void print(vector<string> v) {
	for(auto s: v) cout << s << " ";
	cout << endl;
}

int main(){
	Solution s;
	vector<string> ans;	
	
	ans = s.generateParenthesis(1);
	print(ans);

	ans = s.generateParenthesis(2);
	print(ans);

	ans = s.generateParenthesis(3);
	print(ans);

}