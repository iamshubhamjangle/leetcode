/*
Longest_Prefix_Suffix.cpp

Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:
Input: s = "abab"
Output: 2

Example 2:
Input: s = "aaaa"
Output: 3

https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
	- Method 1: Iterate using two pointer i=0, j=1. TC: O(N). SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  	// Method 1: 
  	//	- i=0, j=1 and iterate over string
  	//	- while we dont reach end, compare i, j. if they equal i++, j++, count++
  	//	- if not reset j to last matched index, and reset initMatchPointer.
  	//	- return count
  		int lps(string s) {
	    int n = s.size();
	    int i = 0;
	    int j = 1;
	    int count = 0;
	    int initMatchPointer = -1;

	    while(j < n) {
	    	// cout << "s[" << i << "] == s["<<j<<"]: " << s[i] << " == " << s[j];
	    	if(s[i] == s[j]) {
	    		i++; 
	    		j++;
	    		count++; 
	    		if(count == 1) initMatchPointer = j;
	    	} else {
	    		i = 0;
	    		count = 0;
	    		if(initMatchPointer > 0) { 
	    			j = initMatchPointer; 
	    			initMatchPointer = -1;
	    		}
	    		else { 
	    			j++; 
	    		}
	    	}
	    	// cout << " count: " << count << endl;
	    }

	    return count;
	}
};

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}