/*
Longest_Palindromic_Substring.cpp

https://leetcode.com/problems/longest-palindromic-substring/
*/
#include <bits/stdc++.h>
using namespace std;

// Method 1: Bruteforce 0,i -> n. subStr(j-i+1). TC: O(N*N*M) SC:O(1)
string longestPalindrome1(string s) {
	int n = s.size();
	string longest = "";

	for(int i=0; i<n; ++i) {			// O(N)
		for (int j=i; j<n; ++j) {		// O(N)
			string subString = s.substr(i,j-i+1);
			string stringReverse { subString };
			reverse(stringReverse.begin(), stringReverse.end());		// O(M)

			if(subString == stringReverse and subString.size() > longest.size()) {
				longest = subString;
			}
		}
	}

	return longest;
}

// Method 2 - This is giving incorrect answer using expansion techique
string longestPalindrome(string s) {
    int n = s.size();
    if(n <= 1) return s;

    string res = "";

    for(int i=0; i<n; i++) {
        int l = i;
        int r = i;

        // Odd
        while(l >= 0 and r < n and s[l] == s[r]) {	// we are within bound and char are equal
            if(r-l+1 > res.size()) {
                res = s.substr(l, r+1);
            }
            l--;
            r++;
        }

        // Even length
        l = i;
        r = i+1;

        while(l >= 0 and r < n and s[l] == s[r]) {	// we are within bound and char are equal
            if(r-l+1 > res.size()) {
                res = s.substr(l, r+1);
            }
            l--;
            r++;
        }		
    }

    return res;
}

// Method 3: Using Hashmap



// Method 4: Using DP



int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		string s;
		cin >> s;
		cout << longestPalindrome(s) << endl;	//run this 't' times
	}
}
