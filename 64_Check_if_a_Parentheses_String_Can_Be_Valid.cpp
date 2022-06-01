/*
2116. Check_if_a_Parentheses_String_Can_Be_Valid.cpp

A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return false.

https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
Method 1: Travers L2R and R2L - TC: O(N)  SC: O(1)
	- Travers from left to right if(unlocked || '(') bal++; else bal--;

************* APPROACH
A useful trick (when doing any parentheses validation) is to greedily check balance left-to-right, and then right-to-left.

Left-to-right check ensures that we do not have orphan ')' parentheses.
Right-to-left checks for orphan '(' parentheses.
We go left-to-right:

Count wild (not locked) characters.
Track the balance bal for locked parentheses.
If the balance goes negative, we check if we have enough wild characters to compensate.
In the end, check that we have enough wild characters to cover positive balance (open parentheses).
This approach alone, however, will fail for ["))((", "0011"] test case. That is why we also need to do the same going right-to-left.
*************

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canBeValid(string s, string locked) {
		int n = s.size();
		if(n&1) return false;

		int balance = 0;
		for(int i=0; i<n; i++) {
			if(locked[i] == '0' || s[i] == '(') balance++;   
			else balance--;
			if(balance < 0) return false;
		}

		balance = 0;

		for(int i=n-1; i>=0; i--) {
			if(locked[i] == '0' || s[i] == ')') balance++;
			else balance--;
			if(balance < 0) return false;
		}

		return true;
	}
};

void solve() {
	int n;
	string s;
	string locked;
	cin >> n >> s >> locked;

	Solution sol;
	cout << sol.canBeValid(s, locked) << endl;
}

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		solve();	//run this 't' times
	}
}
