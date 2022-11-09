/*
Make_The_String_Great.cpp

https://leetcode.com/problems/make-the-string-great/
*/


class Solution {
public:
    // Brute TC: O(N*N) SC: O(1)
    string makeGood(string s) {
        int n = s.size();
        for(int i=0; i<=n-2;) {
            if(s[i] != s[i+1] && (s[i] == toupper(s[i+1]) || toupper(s[i]) == s[i+1])) {
                s.erase(i,2);
                i = 0;
            } else {
                i++;
            }
        }
        return s;
    }

    // TC: O(N) SC: O(1)
    string makeGood(string s, int p = 0) {
        for (int i = 0; i < s.size(); ++i) {
            if (p > 0 && abs(s[i] - s[p - 1]) == 32)
                --p;
            else
                s[p++] = s[i];
        }
        return s.substr(0, p);
    }
};