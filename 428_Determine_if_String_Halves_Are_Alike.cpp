/*
Determine_if_String_Halves_Are_Alike.cpp

https://leetcode.com/problems/determine-if-string-halves-are-alike/
*/

class Solution {
public:
    // TC: O(N), SC: O(10)
    bool halvesAreAlike(string s) {
        int countFirstHalf = 0;
        int countSecondHalf = 0;
        int n = s.size();
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        
        for(int i=0; i<n; i++) {
            if(i<n/2 && vowels.find(s[i]) != vowels.end()) countFirstHalf++;
            if(i>=n/2 && vowels.find(s[i]) != vowels.end()) countSecondHalf++;
        }
        
        return countFirstHalf == countSecondHalf;
    }
    
    // TC: O(N) SC: O(1). Reduce the same counter for reverse op. return if == 0
    bool halvesAreAlike(string s) {
        int t = 0;
        int n = s.size();
        
        for(int i=0; i<n; i++) {
            s[i] = tolower(s[i]);
            if(i<n/2) {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117) t++;
            } else {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117) t--;
            }     
        }
        
        return (t == 0);
    }
};