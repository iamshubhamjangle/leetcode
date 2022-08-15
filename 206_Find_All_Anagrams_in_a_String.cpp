/*
Find_All_Anagrams_in_a_String.cpp

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]

Input: s = "abab", p = "ab"
Output: [0,1,2]

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.

https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Using vector for storing frequency. TC: O(n*m) SC: O(26)
// bool compare(vector<int> &ms, vector<int> &mp) {
// 	for(int i=0 ;i<26; i++) {
// 		if(ms[i] != mp[i]) return false;
// 	}
// 	return true;
// }

// vector<int> findAnagrams(string s, string p) {
// 	int n = s.length();
// 	int m = p.length();
// 	vector<int> res;

// 	vector<int> mp(26);
// 	for(char ch: p) mp[ch - 'a']++;

// 	for(int i=0; i<(n-m+1); i++) {
// 		vector<int> ms(26);
// 		for(int j=i; j<i+m; j++) {
// 			ms[s[j] - 'a']++;
// 		}
// 		bool ans = compare(ms, mp);
// 		if(ans) res.push_back(i);
// 	}

// 	return res;
// }


// 2. Using map. TC: O(n*m) SC: O(n)
bool compare(unordered_map<char, int> &ms, unordered_map<char, int> &mp) {
	for(auto i: ms) {
		if(ms[i.first] != mp[i.first]) return false;
	}
	return true;
}

vector<int> findAnagrams(string s, string p) {
	int n = s.length();
	int m = p.length();
	vector<int> res;

	unordered_map<char, int> mp;
	for(char ch: p) mp[ch]++;

	for(int i=0; i<(n-m+1); i++) {
		unordered_map<char, int> ms;
		for(int j=i; j<i+m; j++) {
			ms[s[j]]++;
		}
		if(compare(ms, mp)) 
			res.push_back(i);
	}

	return res;
}

void print(vector<int> &v) {
	for(auto i: v) cout << i << ", ";
	cout << endl;
}

int main(){
	vector<int> ans;
	string s,p;

	s = "cbaebabacd"; p = "abc";
	ans = findAnagrams(s, p);
	print(ans);

	s = "abab"; p = "ab";
	ans = findAnagrams(s, p);
	print(ans);
}