/*
Check_if_strings_are_rotations_of_each_other_or_not.cpp

Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. 
The characters in the strings are in lowercase.

Input:
geeksforgeeks
forgeeksgeeks
Output: 
1

Input:
mightandmagic
andmagicmigth
Output: 
0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Method 1: merge and find(). TC: O(N). SC: O(1)
    bool areRotations(string s1,string s2) {
        if (s1.length() != s2.length()) return false;
        string temp = s1 + s1;
        return (temp.find(s2) != string::npos);	//string::npos = is the value for not found
    }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}