/*
Valid_Palindrome_II.cpp

https://leetcode.com/problems/valid-palindrome-ii/description/
*/

class Solution {
public:
    // // TLE.
    // bool solve(int i, int j, int k, string s) {
    //     if(i >= j) return true;

    //     bool res = false;
    //     if(s[i] == s[j]) {
    //         res = solve(i+1, j-1, k, s);
    //     } else if(k) {
    //         res = solve(i+1, j, k-1, s) || solve(i, j-1, k-1, s);
    //     }

    //     return res;
    // }

    // bool validPalindrome(string s) {
    //     int n = s.size();
    //     int k = 1;  // can delete only k times

    //     return solve(0, n-1, k, s);
    // }


    bool validPalindrome(string s) {
        for(int i=0, j=s.size()-1; i<j; i++, j--) {
            if(s[i] != s[j]) {
                int i1 = i, j1 = j-1;   // substr excluding last char
                int i2 = i+1, j2 = j;   // substr excluding first char
                while(i1 < j1 && s[i1] == s[j1]) i1++, j1--;
                while(i2 < j2 && s[i2] == s[j2]) i2++, j2--;
                return (i1 >= j1 || i2 >= j2);  // If the substr is valid
            }
        }

        return true;
    }
};





