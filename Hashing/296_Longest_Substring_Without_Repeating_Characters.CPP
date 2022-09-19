/*
Longest_Substring_Without_Repeating_Characters.CPP

Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3

Input: s = "bbbbb"
Output: 1

Input: s = "pwwkew"
Output: 3

https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// 1. Bruteforce. TC: O(N^3) SC: O(1)
	// 2. Kadane's Algo. TC: O(N^2) SC: O(1)
	// 3. Two pointer Set. TC: O(N) SC: O(N)
    int lengthOfLongestSubstring(string s) {
    	vector<int> mpp(256, -1);
    	int n = s.size();
    	int len = 0;

    	int left = 0;
    	int right = 0;

    	while(right < n) {
    		if(mpp[s[right]] != -1)
    			left = max(mpp[s[right]] + 1, left)

    		mpp[s[right]] = right;

    		len = max(len, right - left + 1);
    		right++;
    	}

    	return len;
    }
};

int main(){
	Solution s;
	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;	
	cout << s.lengthOfLongestSubstring("bbbbb") << endl;	
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;	
}