/*
Print_all_subsequences_of_a_string.cpp
Given a string, we have to find out all subsequences of it. 
A String is a subsequence of a given String, that is generated by deleting some character 
of a given string without changing its order.

Input : abc
Output : a, b, c, ab, bc, ac, abc

Input : aaa
Output : a, aa, aaa

https://www.geeksforgeeks.org/print-subsequences-string/
	- Method 1: Bruteforce TC: O(N*N) SC: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

void solve();

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		solve();	//run this 't' times
	}

	return 0;
}

// Method 1: Bruteforce TC: O(N*N) SC: O(N)
void solve() {
	string str;
	cin >> str;
	int n = str.size();

	set<string> ans;

	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			ans.insert(str.substr(i,j-i+1));
		}
	}

	for(auto i: ans) cout << i << " ";

	cout << endl;
}