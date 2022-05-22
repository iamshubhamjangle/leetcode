/*
Reverse_a_String.cpp

You are given a string s. You need to reverse the string.

Input: s = Geeks
Output: skeeG

Input: s = for
Output: rof

https://practice.geeksforgeeks.org/problems/reverse-a-string/1
Method 1: Using inbuilt function TC: O(N)
Method 2: loop from reverse and append to new str. TC: O(N), SC: O(N)

*/

#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main() {
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin >> s;
		cout << reverseWord(s) << endl;
	}
	return 0;
}

// Method 1: using inbuild stl function
// string reverseWord(string str){
// 	reverse(str.begin(), str.end());
// 	return str;
// }

// Method 2: loop from reverse and append to new str.
// string reverseWord(string str){
// 	int n=str.length();
// 	string s = "";

// 	for(int i=n-1; i>=0; i--) {
// 		s = s + str[i];
// 	}

// 	return s;
// }
