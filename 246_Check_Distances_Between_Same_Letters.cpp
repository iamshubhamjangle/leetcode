/*
Check_Distances_Between_Same_Letters.cpp

Return true if s is a well-spaced string, otherwise return false.

Input: s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Output: true

Input: s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Output: false

https://leetcode.com/contest/weekly-contest-309/problems/check-distances-between-same-letters/
*/

#include <bits/stdc++.h>
using namespace std;

/*
s = "abaccb", 
distance = [-1,-1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
*/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
		int n = s.size();
		for(int i=0; i<n; i++) {
			if(distance[s[i] - 'a'] == -1) continue;
			int gap = i + distance[s[i] - 'a'] + 1;
			distance[s[i] - 'a'] = -1;
			if(gap > n-1) return false;
			if(s[gap] != s[i]) return false;
		}
		return true;
    }
};

int main(){
	vector<int> distance;
	Solution s;
	distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	cout << s.checkDistances("abaccb", distance) << endl;
	distance = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	cout << s.checkDistances("aa", distance) << endl;
	distance = {10,14,9,10,11,50,11,26,32,13,31,8,18,2,34,10,15,5,20,19,10,20,5,24,22,10};
	cout << s.checkDistances("ttkk", distance) << endl;
}