/*
Count_the_Reversals.cpp

Given a string S consisting of only opening and closing curly brackets '{' and '}', 
find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Input : S = "}{{}}{{{"
Output: 3

Input : S = "{{}{{{}{{}}{{"
Output: -1

https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#
Method 1: Greedy. TC: O(N) SC: O(1)
Variables: c is counter variable indicating the number of open brackets. 
res is number of reversals.

Intuition: Greedy. 
	- Whenever we get open brackets, add them. 
	- Whenever we get closing brackets and we have open ones available, 
	  just remove extra open brackets you have.
	- When we don't have enough opening brackets ,(c=0) then reverse the closing bracket 
	  we encountered immediately.
	- In the end, u may have some open brackets indicated by ‘c’. 
	  Example: c=3, then we can think of resultant as {{{ , 
	  we can notice that no reversal can fix this, so return -1 when c is odd. 
	  When c is even, example c=4, {{{{ => {{}} it can be changed this way by 
	  reversing half of the open brackets. so add c/2 to the result.
*/

#include<bits/stdc++.h>
using namespace std;

int countRev (string s);

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

int countRev (string s) {
    int n = s.size();
    if(n%2 != 0) return -1;

    int count = 0;
    int rev = 0;

    for(int i=0; i<n; i++) {
    	if(s[i] == '{') {
    		count++;
    	} else {
    		if(count > 0) {
    			count--;
    		} else {
    			rev++;
    			count++;
    		}
    	}
    }

    rev += count / 2;
    return rev;
}