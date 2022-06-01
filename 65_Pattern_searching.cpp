/*
Pattern_searching.cpp 

Given a string str and a pattern pat. You need to check whether pattern 
is present or not in the given string. 

Sample Input:
2
abcdefh
bcd
axzy
xy

Sample Output:
Present
Not present

https://practice.geeksforgeeks.org/problems/pattern-searching5231/1#
	- Method 1: Bruteforce TC: O(N*N). SC: O(1)
	- Method 2: Using DP(LCS) approach

*/

#include <bits/stdc++.h>
using namespace std;

// Method 1: Bruteforce TC: O(N*N). SC: O(1)
// bool searchPattern(string str, string pat) {
	// int n = str.size();
 //    for(int i=0; i<n; i++) {
 //    	for(int j=0; j<n; j++) {
 //    		if(str.substr(i, j-i+1) == pat) return true;
 //    	}
 //    }
 //    return false;
// }

bool searchPattern(string str, string pat) {
    for(int i=0;i<str.length();i++)
    {
        string check="";
        int j=0;
        int k=i;
        while(str[k]==pat[j])
        {
            check+=str[k];
            if(check==pat)
            {
                return true;
            }
            j++;
            k++;
        }
    }
    return false;
}



int main() {
    int t; cin>>t;
    
    while(t--) {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}