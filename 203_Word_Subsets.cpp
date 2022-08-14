/*
Word_Subsets.cpp

Example 1:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]

https://leetcode.com/problems/word-subsets/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> counter(string &s) {
	vector<int> count(26);
	for(char c: s) count[c - 'a']++;
	return count;
}

vector<string> wordSubsets(vector<string>& arr1, vector<string>& arr2) {
	int n = arr1.size();
	int m = arr2.size();
	vector<int> count(26), tmp(26);
	int i;

	for(i=0; i<m; i++) {
		tmp = counter(arr2[i]);
		for(int i=0; i<26; i++)
			count[i] = max(count[i], tmp[i]);
	}

	vector<string> ans;
	for(string a: arr1) {
		tmp = counter(a);
		for(i=0; i<26; i++)
			if(tmp[i] < count[i])	// If count has that word but tmp doesnt
				break;
		if(i == 26)
			ans.push_back(a);
	}

	return ans;
}

// print vector
void print(vector<string> v) {
	for(auto s: v)
		cout << s << ", ";
	cout << endl;
}

int main(){
	vector<string> words1;
	vector<string> words2;

	words1 = {"amazon","apple","facebook","google","leetcode"};
	words2 = {"e","o"};
	print(wordSubsets(words1, words2));

	words1 = {"amazon","apple","facebook","google","leetcode"};
	words2 = {"l","e"};
	print(wordSubsets(words1, words2));
}

