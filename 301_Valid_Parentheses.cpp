/*
Valid_Parentheses.cpp

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

https://leetcode.com/problems/valid-parentheses/
*/


class Solution {
public:
	// TC: O(N) SC: O(N)
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++) {
        	if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
        		st.push(s[i]);
        	} else {
        		if(st.empty()) return false;
        		char ch = st.top();
        		if(s[i] == ')' && ch == '(') st.pop();
        		else if(s[i] == ']' && ch == '[') st.pop(); 
        		else if(s[i] == '}' && ch == '{') st.pop();
        		else return false;
        	}
        }

        return st.empty();
    }
};