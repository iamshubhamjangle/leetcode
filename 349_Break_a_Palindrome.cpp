/*
Break_a_Palindrome.cpp

https://leetcode.com/problems/break-a-palindrome/
*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        if(n <= 1) return "";
        
        int i;
        for(i=0; i<n/2; i++) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[n-1] = 'b';    
        return palindrome;
    }
};