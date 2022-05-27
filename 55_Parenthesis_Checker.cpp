/*
Parenthesis_Checker.cpp 

Given an expression string x. Examine whether the pairs and the orders 
of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for 
exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Input : {([])}
Output: true

Input : ([]
Output: false

https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
    - Method 1: Use stack to track ( { [ - TC: O(N), SC: O(N)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool ispar(string x) {
        int n = x.size();
        stack<char> st;

        for(int i=0; i<n; i++) {
            if(x[i] == '[' || x[i] == '(' || x[i] == '{') {
                st.push(x[i]);
            } else {
                if(st.empty()) return false;

                if(x[i] == ']' && st.top() == '[') st.pop();
                else if(x[i] == ')' && st.top() == '(') st.pop();
                else if(x[i] == '}' && st.top() == '{') st.pop();
                else return false;
            }            
        }
    
        return st.empty();
    }

};

int main() {
   int t;
   string a;
   cin>>t;
   while(t--) {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}