/*
Greatest_Common_Divisor_of_Strings.cpp

https://leetcode.com/problems/greatest-common-divisor-of-strings/
*/
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }

template<typename T>
void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }


class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        return (s1 + s2 == s2 + s1)  
                ? s1.substr(0, gcd(size(s1), size(s2)))
                : "";
    }
};