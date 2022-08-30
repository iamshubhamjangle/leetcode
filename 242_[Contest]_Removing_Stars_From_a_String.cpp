/*
Removing_Stars_From_a_String.cpp
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

https://leetcode.com/contest/weekly-contest-308/problems/removing-stars-from-a-string/
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.length();
        int skipChar = 0;

        for(int i=n-1; i>=0; i--) {
        	if(s[i] == '*') {
        		skipChar++;
        		continue;
        	}

        	if(skipChar > 0) {
        		skipChar--;
        		continue;
        	}

    		st.push(s[i]);
        }

        string ans;
        while(!st.empty()) {
        	ans.push_back(st.top());
        	st.pop();
        }

        return ans;
    }
};

int main(){
	Solution s;
	cout << s.removeStars("leet**cod*e") << endl;	
	cout << s.removeStars("erase*****") << endl;	
}