/*
Find_Words_That_Can_Be_Formed_by_Characters.cpp

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
Method 1: TC: O(N*M).  SC: O(N). where N is no of words in arr, M is no of char in each word
	- create map for chars
	- loop over arr words and check if each letter of word present in map.
	- if all letter present return its size, else return 0 
Method 2: TC: O(N),  SC: O(26)
	- loop over, keep 2 arrays.
	- if localArr[ch - 'a'] > globalArr[ch - 'a'] return false

*/


#include <bits/stdc++.h>
using namespace std;

// Method 1: TC: O(N*M).  SC: O(26). where N is no of words in arr, M is no of char in each word
// 		- create map for chars
//		- loop over arr words and check if each letter of word present in map.
//		- if all letter present return its size, else return 0 
int checkIfExist(string s, unordered_map<char, int> um) {
	for(auto ch: s) {
		if(um[ch])
			um[ch]--;
			continue;
		else
			return 0;
	}
	return s.size();
}

int solve(vector<string> &arr, string chars) {
	unordered_map<char, int> um;
	for(auto i: chars)
		um[i]++;

	int count = 0;

	for(auto ch: arr) {
		int res = checkIfExist(ch, um);
		if(res) {
			count += res;
		};
	}

	return count;
}

// Method 2: TC: O(N),  SC: O(26)
//	- loop over, keep 2 arrays.
//	- if localArr[ch - 'a'] > globalArr[ch - 'a'] return false

int countCharacters(vector<string>& words, string chars) {
  int cnt[26] = {}, res = 0;
  for (auto ch : chars) 
      ++cnt[ch - 'a'];
  for (auto &w : words) {
    int cnt1[26] = {}, match = true;
    for (auto ch : w)
      if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
        match = false;
        break;
      }
    if (match) 
        res += w.size();
  }
  return res;
}

int main(){
	int t; cin >> t;		//input no. of test cases
	while(t--){
		int n; cin >> n;
		vector<string> arr;
		for(int i=0; i<n; i++) {
			string word;
			cin >> word;
			arr.push_back(word);
		}
		string chars; cin >> chars;
		cout << solve(arr, chars) << endl;	//run this 't' times
	}
}
