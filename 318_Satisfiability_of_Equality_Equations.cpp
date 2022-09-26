/*
Satisfiability_of_Equality_Equations.cpp

Return true if it is possible to assign integers to variable names 
so as to satisfy all the given equations, or false otherwise.
equations[i][1] is either '=' or '!'.

Input: equations = ["a==b","b!=a"]
Output: false

Input: equations = ["b==a","a==b"]
Output: true

https://leetcode.com/problems/satisfiability-of-equality-equations/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (string e : equations)
            if (e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a');
        for (string e : equations)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }

    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};

int main(){
	Solution s;
	vector<string> equations;
	equations = {"a==b","b!=a"};
	cout << s.equationsPossible(equations) << endl;
	equations = {"b==a","a==b"};
	cout << s.equationsPossible(equations) << endl;
	equations = {"a==b","b==c","a==c"};
	cout << s.equationsPossible(equations) << endl;
	equations = {"a!=a"};
	cout << s.equationsPossible(equations) << endl;

}