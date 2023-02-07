/*
Valid_Parentheses.cpp

https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &ch: s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                if(ch == ')' && st.top() != '(') return false;
                else if(ch == '}' && st.top() != '{') return false;
                else if(ch == ']' && st.top() != '[') return false;
                else st.pop();
            }
        }

        return st.empty();
    }
};