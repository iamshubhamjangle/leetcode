
#include <bits/stdc++.h>
using namespace std;


int solve(int n, string s, int k) {
	if(n == 0) {
		if(abs(s[1] - s[0]) <= k) return 1;
		
	}

	int ans = 1 + solve(n-1, s, k);
	return ans;
}

int longestIdealString(string s, int k) {
	int n = s.size();
	return solve(n-1, s, k);
}

int main(){
	cout << longestIdealString("acfgbd", 2) << endl;
	cout << longestIdealString("abcd", 3) << endl;
}