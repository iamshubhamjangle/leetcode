/*
Find_first_repeated_character.cpp

Given a string S. The task is to find the first repeated character in it. 
We need to find the character that occurs more than once and whose index of 
second occurrence is smallest. S contains only lowercase letters.

Input: S="geeksforgeeks"
Output: e

Input: S="hellogeeks"
Output: l

Input: S="abc"
Output: -1

https://practice.geeksforgeeks.org/problems/find-first-repeated-character4108/1
	- Method 1: Iterate and count in hashmap. TC:O(N), SC: O(26)

*/

#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}


string firstRepChar(string s) {
	int n = s.size();
	unordered_map<char, int> um;

    for(int i=0; i<n; i++) {
    	um[s[i]]++;
    	if(um[s[i]] > 1) return string { s[i] };
    }

    return "-1";
}