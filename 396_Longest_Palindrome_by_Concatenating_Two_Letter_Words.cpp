/*
Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp

https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
*/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> counter(26, vector<int>(26, 0));
        int ans = 0;
        
        // To find palindrome of length 4. eg. "lc", "cl"
        for (string w: words) {     // for each word
            int a = w[0] - 'a';     // letter 1
            int b = w[1] - 'a';     // letter 2
            if (counter[b][a])      // if reverse word exist we got a palindrom len = 4
                ans += 4, counter[b][a]--;  // remove from map
            else 
                counter[a][b]++;            // add to map
        }
        
        // To find palindrome of length 2, which will be only one (eg. "gg")
        for (int i = 0; i < 26; i++) {
            if (counter[i][i]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};