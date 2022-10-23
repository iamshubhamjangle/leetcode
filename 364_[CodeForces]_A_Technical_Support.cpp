/*
A_Technical_Support.cpp

https://codeforces.com/contest/1754/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<char> &v, int n) {
	stack<char> s;
	for(auto ch: v) {
		if(ch == 'A') {
			if(!s.empty()) s.pop();
		} else {
			s.push(ch);
		}
	}

	return s.empty();
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		vector<char> v;
		for(int i=0; i<n; i++) {
			char c; cin >> c;
			v.push_back(c);
		}
		cout << (isValid(v, n) ? "Yes":"No") << endl;
	}
}
