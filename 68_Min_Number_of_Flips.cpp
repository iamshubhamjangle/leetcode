/*
Min_Number_of_Flips.cpp

Given a binary string, that is it contains only 0s and 1s. 
We need to make this string a sequence of alternate characters by flipping some of the bits, 
our goal is to minimize the number of bits to be flipped.

Input : S = "001"
Output: 1

Input : S = "0001010111" 
Output: 2

https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1#
	- Method 1: there are only two possibilty. TC: O(N) SC: O(1)
		- consider pattern starting from 0. odd no should be 0 and even 1 if not Lcount++;
		- consider pattern starting from 1. odd no should be 1 and even 0 if not Rcount++;
		- return min of Lcount, Rcount
*/

#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}

int minFlips (string str) {
    int n = str.size();
    int pattern1flip = 0, pattern2flip = 0;

    for(int i=0; i<n; i++) {
    	// pattern 1 starting from 0
    	if(i%2==0 && str[i] == '1')
    		pattern1flip++;
    	else if(i%2==1 && str[i] == '0')
    		pattern1flip++;

    	// pattern 2 starting from 1
    	if(i%2==0 && str[i] == '0')
    		pattern2flip++;
    	else if(i%2==1 && str[i] == '1')
    		pattern2flip++;
    }

    return min(pattern1flip, pattern2flip);
}