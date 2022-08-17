/*
First_Unique_Character_in_a_String.cpp

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

https://leetcode.com/problems/first-unique-character-in-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

// // Bruteforce - TC: O(N*N) SC: O(1)
// int firstUniqChar(string s) {
// 	int n = s.size();
// 	for(int i=0; i<n; i++) {
// 		bool found = false;

// 		for(int j=0; j<n; j++) {
// 			if(i == j) continue;
// 			if(s[i] == s[j]) found = true;
// 		}

// 		if(!found) return i;
// 	}

// 	return -1;
// }


// unordered_map - TC: O(N) SC: O(N)
int firstUniqChar(string s) {
	int n = s.size();
	vector<int> mp(26);

	for(int i=0; i<n; i++) {
		mp[s[i] - 'a']++;
	}

	for(int i=0; i<n; i++) {
		if(mp[s[i] - 'a'] == 1)
			return i;
	}

	return -1;
}

int main(){
	cout << firstUniqChar("leetcode") << endl;	
	cout << firstUniqChar("loveleetcode") << endl;	
	cout << firstUniqChar("aabb") << endl;	
}