/*
Longest_Palindrome_in_a_String.cpp

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).

Input:
S = "aaaabbaa"
Output: aabbaa

Input: 
S = "abc"
Output: a

https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
  Method 1: Bruteforce: TC: O(N*N). SC: O(1)
  Method 2:  im not able to solve optimized. plz help

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Method 1: Bruteforce: loop through each substring. TC: O(N*N). SC: O(1)
    //  - find its reverse and check the length and return max string
    // string longestPalin (string S) {
    //     string palindrome;
    //     int n = S.length();

    //     for(int i=0; i<n; i++) {
    //         for(int j=i; j<n; j++) {
    //             string substring = S.substr(i, j-i+1);
    //             string rev { substring };
    //             reverse(rev.begin(), rev.end());
    //             if(substring == rev && substring.length() > palindrome.length()) {
    //                 palindrome.clear();
    //                 for(char c: substring) palindrome.push_back(c);
    //             }
    //         }
    //     }

    //     return palindrome;
    // }

    string longestPalin (string S) {
        int size=S.size();
        int l,h;
        int start=0,end=1;

        for(int i=0;i<size;i++) {
            l=i-1;
            h=i;

            while(l>=0 && h<size && S[l]==S[h]) {
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }

            l=i-1;
            h=i+1;

            while(l>=0 && h<size && S[l]==S[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }
        }

        return S.substr(start,end);
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}