/*
Detect_Capital.cpp

https://leetcode.com/problems/detect-capital/description/
*/


class Solution {
public:
    // TC: O(N) SC: O(1)
    bool detectCapitalUse(string word) {
        int n = word.size();        // size of word
        int upper = 0;              // upperCase letters count
        int lower = 0;              // lowerCase letters count
        
        for(auto ch: word) {                        // Count upper and lower case letters
            if(ch - 'a' < 0) upper++;
            else lower++;
        }

        // Check the conditions validity
        if(upper == n || lower == n) return true;           // If all are Upper/Lower case
        if(isupper(word[0]) && lower == n-1) return true;   // If first is upper / rest lower case
        return false;
    }
};