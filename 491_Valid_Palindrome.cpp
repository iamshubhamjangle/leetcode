/*
Valid_Palindrome.cpp

https://leetcode.com/problems/valid-palindrome/description/
*/

class Solution {
public:
    // better. TC: O(N) SC: O(1)
    bool isPalindrome(string s) {
        string s2;
        for(auto &ch: s) {
            if(ch != ' ' && isalnum(ch))
                s2.push_back(tolower(ch));
        }
        
        int n = s2.size();

        for(int i=0, j=n-1; i<j; i++, j--) {
            if(s2[i] != s2[j]) 
                return false;
        }

        return true;
    }


    // consice. TC: O(N) SC: O(1)
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
            while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
            while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
        }
        return true;
    }
};