/*
Minimum_Swaps_for_Bracket_Balancing.cpp

You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. 
A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 
are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. 
Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

Input  : []][][
Output : 2

Input : [[][]]
Output : 0

https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1
	- Method 1: open, close, unbal, swap counters. TC: O(N). SC: O(1)
*/

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    int minimumNumberOfSwaps(string str){
        // Yet to be solved
        int n = str.size();
        if(n == 0) return 0;

        int open = 0;
        int closed = 0;
        int unbalance = 0;
        int swap = 0;

        for(int i=0; i<n; i++) {
        	if(str[i] == ']') {
        		closed++;
        	} 
        	else if(str[i] == '[') {
        		if(unbalance>0) {
        		    swap += unbalance;
        		}
        		open++;
        	}
        	unbalance = closed - open;
        }

        return swap;
    }
};

int main()  { 
    int t;
    cin>>t;
    while(t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}