/*
Generate_Parentheses.cpp

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

https://leetcode.com/problems/generate-parentheses/
TC: exponential. SC: exponential
*/

class Solution {
public:
    void backtrack(vector<string> &ans, int max, int open, int close, string currString) {
        if(currString.length() == max*2) {
            ans.push_back(currString);
            return;
        }
        
        if(open < max) backtrack(ans, max, open+1, close, currString + "(");
        if(close < open) backtrack(ans, max, open, close+1, currString + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, n, 0, 0, "");
        return ans;
    }
};