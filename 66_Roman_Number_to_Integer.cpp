/*
Roman_Number_to_Integer.cpp

Given a string in roman no format (s)  your task is to convert it to an integer. 
Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Input : s = V
Output: 5

Input : s = III 
Output: 3

https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
Method 1: un-map + Iterate from end. TC: O(N). SC: O(1)
	- Iterate from n-1 to 0. if i >= i+1 then ans += str[i+1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int romanToDecimal(string &str) {
		unordered_map<char, int> um;
		um['I'] = 1;
		um['V'] = 5;
		um['X'] = 10;
		um['L'] = 50;
		um['C'] = 100;
		um['D'] = 500;
		um['M'] = 1000;

		int n = str.size();
		int ans = um[str[n-1]];

		if(n == 0) return 0;
		if(n == 1) return ans;

		for(int i=n-2; i>=0; i--) {
			if(um[str[i]] >= um[str[i+1]]) 
				ans += um[str[i]];
			else
				ans -= um[str[i]];
		}

		return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}