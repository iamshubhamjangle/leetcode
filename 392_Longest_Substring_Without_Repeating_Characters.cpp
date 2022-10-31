/*
Longest_Substring_Without_Repeating_Characters.cpp

Input: s = "abcabcbb"
Output: 3

https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    // Brute. TC: O(N^2) SC: O(N)
    int _lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        if(n == 1) return 1;

        int ans = 1;

        for(int i=0; i<n; i++) {
            unordered_map<char, int> um;
            int count = 0;

            for(int j=i; j<n; j++) {
                if(um[s[j]] > 0) {
                    break;
                }
                um[s[j]] += 1;
                count++;
                ans = max(count, ans);
            }
        }

        return ans;
    }


    // Optimised. TC: O(N) SC: O(N)
    // If we use set and don't store the index, we will have to travel O(2N) times
    // Hence we are using map<> so that we can move left directly to right+1, if left is within range
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int n = s.size();
        int ans = 0;
        int left = 0, right = 0;

        while(right < n) {
            if(mpp[s[right]] != -1) left = max(mpp[s[right]]+1, left);

            mpp[s[right]] = right;

            ans = max(ans, right-left+1);
            right++;
        }

        return ans;
    }
};